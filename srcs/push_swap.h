/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:23:14 by micchen           #+#    #+#             */
/*   Updated: 2024/05/27 17:59:01 by micchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}				t_stack;

//operation
long int	ft_atol(const char *str);
void		free_all(t_stack **a, t_stack **b);
void		ft_error(t_stack **a, t_stack **b);
void		free_av(char **av);
int			check_ac_av(int *ac, char ***av);
int			check_n(char **av);
void		push(t_stack **from, t_stack **to, char n);
void		rotate_stack(t_stack **a, char n);
void		rev_rotate_stack(t_stack **a, char n);
void		rr(t_stack **a, t_stack **b, int n);
void		rrr(t_stack **a, t_stack **b, int n);
void		swap(t_stack **a, char n);
void		swap_stacks(t_stack **a, t_stack **b, char n);
void		print_stack(t_stack *a);
//sort
void		simple_sort(t_stack **stack_a, t_stack **stack_b);
void		radix(t_stack **stack_a, t_stack **stack_b);
//init
void		append_node(t_stack **a, int n);
int			init_stack(t_stack **a, char **av);
void		index_stack(t_stack **stack);
void		init_var_stack(t_stack **a, t_stack **b);
int			check_double(char **array, int start);
int			count_words(char const *s);

//utils
int			check_number(char **str);
t_stack		*find_last_node(t_stack *stack);
int			stack_len(t_stack *stack);
int			get_distance(t_stack **stack, int index);
//utils2
t_stack		*find_highest(t_stack *stack);
//check_sort
int			is_sorted(t_stack *stack_a);
int			is_sorted_av(char **av);
//free
void		free_stack(t_stack **stack);
#endif
