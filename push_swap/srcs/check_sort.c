/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:01:56 by micchen           #+#    #+#             */
/*   Updated: 2024/06/12 01:12:27 by micchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack_a)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		else
			stack = stack->next;
	}
	return (1);
}
