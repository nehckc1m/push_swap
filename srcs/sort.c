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

static int	get_min(t_stack **stack, int val)
{
	t_stack	*head;
	int		min;
	int		size;
	int		i;

	i = 0;
	size = stack_len(*stack);
	head = *stack;
	min = head->index;
	while (i++ < size)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

static void	sort_3(t_stack **stack_a)
{
	t_stack	*highest_node;

	highest_node = find_highest(*stack_a);
	if (highest_node == *stack_a)
		rotate_stack(stack_a, 'a');
	else if ((*stack_a)->next == highest_node)
		rev_rotate_stack(stack_a, 'a');
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap(stack_a, 'a');
}

static void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		rotate_stack(stack_a, 'a');
	else if (distance == 2)
	{
		rotate_stack(stack_a, 'a');
		rotate_stack(stack_a, 'a');
	}
	else if (distance == 3)
		rev_rotate_stack(stack_a, 'a');
	if (is_sorted(*stack_a))
		return ;
	push(stack_a, stack_b, 'b');
	sort_3(stack_a);
	push(stack_b, stack_a, 'a');
}

static void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		rotate_stack(stack_a, 'a');
	else if (distance == 2)
	{
		rotate_stack(stack_a, 'a');
		rotate_stack(stack_a, 'a');
	}
	else if (distance == 3)
	{
		rev_rotate_stack(stack_a, 'a');
		rev_rotate_stack(stack_a, 'a');
	}
	else if (distance == 4)
		rev_rotate_stack(stack_a, 'a');
	if (is_sorted(*stack_a))
		return ;
	push(stack_a, stack_b, 'b');
	sort_4(stack_a, stack_b);
	push(stack_b, stack_a, 'a');
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = stack_len(*stack_a);
	if (len == 3)
		sort_3(stack_a);
	else if (len == 4)
		sort_4(stack_a, stack_b);
	else if (len == 5)
		sort_5(stack_a, stack_b);
}

/*void	sorting(t_stack **a, t_stack **b)
{
	int 	len_a;
	int 	count;
	
	count = 0;
	len_a = stack_len(*a);
	while (len_a-- > 3 && !is_sorted(*a) && count++ != 2)
		push(b, a, 'b');
	while (len_a-- > 3 && is_sorted(*a))
	{
		prep_nodes_a(*a, *b);
		push_all_to_b(a, b);
	}
	tiny_sort(a);
	//while (*b)
}*/
