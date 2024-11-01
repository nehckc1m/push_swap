/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:11:14 by micchen           #+#    #+#             */
/*   Updated: 2024/06/10 17:11:16 by micchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

void	rotate_stack(t_stack **a, char n)
{
	if (*a)
	{
		*a = (*a)->next;
		if (n)
		{
			write(1, "r", 1);
			write(1, &n, 1);
			write(1, "\n", 1);
		}
	}
}

void	rev_rotate_stack(t_stack **a, char n)
{
	t_stack	*current;

	if (*a)
	{
		current = *a;
		while (current->next != *a)
			current = current->next;
		*a = current;
		if (n)
		{
			write(1, "rr", 2);
			write(1, &n, 1);
			write(1, "\n", 1);
		}
	}
}

void	rr(t_stack **a, t_stack **b, int n)
{
	rotate_stack(a, 0);
	rotate_stack(b, 0);
	if (n)
		write(1, "rr\n", 1);
}

void	rrr(t_stack **a, t_stack **b, int n)
{
	rev_rotate_stack(a, 0);
	rev_rotate_stack(b, 0);
	if (n)
		write(1, "rrr\n", 4);
}
