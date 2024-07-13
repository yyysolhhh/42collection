/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:10:31 by                   #+#    #+#             */
/*   Updated: 2023/03/20 09:54:15 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define A		1
# define B		2
# define AB		3

# define CA		4
# define CB		5
# define CAB	6

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

void	error_message(void);
void	parse_av(t_stack **a, t_stack **b, int ac, char **av);
void	index_av(t_stack **a);
t_stack	*init_stack(void);
t_node	*init_node(void);
int		ft_atoi_ps(const char *str);
void	check_duplicated(t_node *node);
int		is_sorted(t_stack *stack);
void	pushswap_sort(t_stack *a, t_stack *b);
void	sort_small_size(t_stack *a, t_stack *b);
void	swap(t_stack *a, t_stack *b, int flag);
void	push(t_stack *from, t_stack *to, int flag);
void	rotate(t_stack *a, t_stack *b, int flag);
void	reverse_rotate(t_stack *a, t_stack *b, int flag);
void	free_all(t_stack *stack);

#endif
