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
