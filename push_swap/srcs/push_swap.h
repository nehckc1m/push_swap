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

typedef struct nbr_node
{
	int				value;
	int 				index;
	int				cost;
	bool				above_mediane;
	bool				cheapest;
	struct nbr_node *target;
	struct nbr_node	*next;
	struct nbr_node	*previous;	
}	t_stack;

//operation
void	push(t_stack **from, t_stack **to, char n);
void 	rotate_stack(t_stack **a, char n);
void 	rev_rotate_stack(t_stack **a, char n);
void 	rr(t_stack **a, t_stack **b, int n);
void 	rrr(t_stack **a, t_stack **b, int n);

//init
void	append_node(t_stack **a, int n);
void	init_stack(t_stack **a, char **av);
int check_double(int *array, int len);

//split
int	ft_strlen(const char *s);
int	count_words(char const *s);
char	**ft_split(char const *s);
//atoi 
long int	ft_atoi(const char *str);
//sort
void	tiny_sort(t_stack **stack_a);
//utils
int 	is_number(char *str);
void 	find_last_node(t_stack_node *stack);
int	stack_len(t_stack *stack);
//utils2
t_stack_node	*find_highest(t_stack *stack);
//check_sort
int	is_sorted(t_stack **stack_a);


#endif
