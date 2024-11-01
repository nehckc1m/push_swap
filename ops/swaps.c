/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swaps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:10:59 by micchen           #+#    #+#             */
/*   Updated: 2024/06/10 17:11:00 by micchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

void	swap(t_stack **a, char n)
{
	int	tmp_val;
	int	tmp_index;

	if (*a && (*a)->next != *a)
	{
		tmp_val = (*a)->value;
		tmp_index = (*a)->index;
		(*a)->value = (*a)->next->value;
		(*a)->index = (*a)->next->index;
		(*a)->next->value = tmp_val;
		(*a)->next->index = tmp_index;
	}
	if (n)
	{
		write(1, "s", 1);
		write(1, &n, 1);
		write(1, "\n", 1);
	}
}

void	swap_stacks(t_stack **a, t_stack **b, char n)
{
	swap(a, 0);
	swap(b, 0);
	if (n)
		write(1, "ss\n", 3);
}
