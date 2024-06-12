/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 02:24:57 by micchen           #+#    #+#             */
/*   Updated: 2024/06/12 02:25:04 by micchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delfirst(t_stack **a)
{
	if (*a && (*a)->next->value != (*a)->value)
	{
		(*a)->next->previous = (*a)->previous;
		(*a)->previous->next = (*a)->next;
		(*a) = (*a)->next;
	}
}

void 	addfirst(t_stack **a, t_stack *new_node)
{

	if (new_node)
	{
		if (*a)
		{
			new_node->next = (*a);
			new_node->previous = (*a)->previous;
			(*a)->previous->next = new_node;
			(*a)->previous = new_node;
		}
		else
		{
			new_node->next = new_node;
			new_node->previous = new_node;
		}
		(*a) = new_node;
	}
}
