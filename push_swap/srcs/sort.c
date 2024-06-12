/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:56:28 by micchen           #+#    #+#             */
/*   Updated: 2024/06/12 19:51:16 by micchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

t_stack_node	*find_highest(t_stack *stack)
{
	int 				highest;
	t_stack_node 	*highest_node;

	if (stack == NULL)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	tiny_sort(t_stack **stack_a)
{
	t_stack_node	*highest;

	highest = find_highest(*a);
	if (*a == highest)
		rotate_stack(a,a);
	else if ((*a)->next == highest)
		rev_rotate_stack(a, a);
	if ((*a)->value > (*a)->next->value)
		swap(a, a);
}
