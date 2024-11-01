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

#include "../srcs/push_swap.h"

static void	delfirst(t_stack **a)
{
	t_stack	*last;

	if (*a)
	{
		last = *a;
		if ((*a)->next == *a)
			*a = NULL;
		else
		{
			while (last->next != *a)
				last = last->next;
			last->next = (*a)->next;
			*a = (*a)->next;
		}
	}
}

static void	addfirst(t_stack **a, t_stack *new_node)
{
	t_stack	*last;

	if (new_node)
	{
		if (*a)
		{
			new_node->next = *a;
			last = *a;
			while (last->next != *a)
				last = last->next;
			last->next = new_node;
		}
		else
			new_node->next = new_node;
		*a = new_node;
	}
}

void	push(t_stack **from, t_stack **to, char n)
{
	t_stack	*node_buffer;

	if (*from)
	{
		node_buffer = *from;
		delfirst(from);
		addfirst(to, node_buffer);
		if (n)
		{
			write(1, "p", 1);
			write(1, &n, 1);
			write(1, "\n", 1);
		}
	}
	if (*from == NULL)
		from = NULL;
}
