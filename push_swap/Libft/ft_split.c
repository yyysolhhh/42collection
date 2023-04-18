/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:12:54 by yesollee          #+#    #+#             */
/*   Updated: 2023/03/19 04:48:25 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			cnt++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (cnt);
}

static int	word_len(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	*sep_word(char const *str, char c)
{
	char	*word;
	int		i;
	int		len;

	len = word_len(str, c);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**all_free(char **string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		free(string[i]);
		string[i] = NULL;
		i++;
	}
	free(string);
	string = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**string;
	int		i;

	if (!s)
		return (NULL);
	string = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			string[i] = sep_word(s, c);
			if (!string[i])
				return (all_free(string));
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	string[i] = 0;
	return (string);
}
