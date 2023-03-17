/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:43:54 by yesollee          #+#    #+#             */
/*   Updated: 2023/03/17 16:18:25 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line_bonus.h"

static int	save_line(char **buf, char **backup)
{
	char	*temp;	

	if (!*backup)
	{
		*backup = ft_strdup("");
		if (!*backup)
			return (0);
	}
	temp = *backup;
	*backup = ft_strjoin(temp, *buf);
	if (!*backup)
		return (0);
	free(temp);
	temp = NULL;
	return (1);
}

static char	*read_file(int fd, char *buf, char *backup)
{
	int		check_read;

	check_read = 1;
	while (check_read > 0)
	{
		check_read = read(fd, buf, BUFFER_SIZE);
		if (check_read == -1)
			return (NULL);
		else if (check_read == 0)
			break ;
		buf[check_read] = '\0';
		if (!save_line(&buf, &backup))
			return (NULL);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*extract_line(char *line)
{
	char	*next_backup;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	next_backup = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!next_backup)
		return (NULL);
	if (*next_backup == '\0')
	{
		free(next_backup);
		next_backup = NULL;
	}
	line[i + 1] = '\0';
	return (next_backup);
}

char	*get_next_line(int fd)
{
	static char	*backup[FD_MAX];
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, NULL, 0) < 0)
	{
		free(backup[fd]);
		backup[fd] = NULL;
		return (NULL);
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = read_file(fd, buf, backup[fd]);
	free(buf);
	if (!line)
	{
		free(backup[fd]);
		backup[fd] = NULL;
		return (NULL);
	}
	backup[fd] = extract_line(line);
	return (line);
}
