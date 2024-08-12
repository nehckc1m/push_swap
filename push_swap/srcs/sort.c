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

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	int 	lenght;
	int 	count;
	
	count = 0;
	lenght = stack_len(*a);
	while (len_a-- > 3 && !is_sorted(*a) && count++ != 2)
		push(b, a, b);
	while (len_a-- > 3 && is_sorted(*a))
	{
		prep_nodes_a(*a, *b);
		push_all_to_b(a, b);
	}
	tiny_sort(a);
	while (*b)


}
