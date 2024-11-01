/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:12:58 by micchen           #+#    #+#             */
/*   Updated: 2024/09/06 17:13:00 by micchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack **stack)
{
	t_stack	*head;
	int		max;
	int		max_bits;
	int		size;
	int		i;

	i = 0;
	max_bits = 0;
	size = stack_len(*stack);
	head = *stack;
	max = head->value;
	while (i++ < size)
	{
		if (head->value > max)
			max = head->value;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head = *stack_a;
	size = stack_len(*stack_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head = *stack_a;
			if (((head->index >> i) & 1) == 1)
				rotate_stack(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
		}
		while (*stack_b)
			push(stack_b, stack_a, 'a');
		i++;
	}
}
