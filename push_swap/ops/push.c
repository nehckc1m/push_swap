/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:11:07 by micchen           #+#    #+#             */
/*   Updated: 2024/06/10 17:11:08 by micchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	delfirst(t_stack **a)
{
	if (*a && (*a)->next->value != (*a)->value)
	{
		(*a)->next->previous = (*a)->previous;
		(*a)->previous->next = (*a)->next;
		(*a) = (*a)->next;
	}
}

static void 	addfirst(t_stack **a, t_stack *new_node)
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

void	push(t_stack **from, t_stack **to, char n)
{
	if (*from)
	{
		node_buffer = *from;
		delfirst(from);
		addfirst(to, node_buffer);
		if (n)
		{
			write(1,"p",1);
			write(1,&name,1);
			write(1,"\n",1);
		}
	
	}
	if (stack_size(*from) == 0)
		from = NULL;
}
