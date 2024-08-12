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

#include "push_swap.h"

void	swap(t_stack **a, char n)
{
	int 	tmp_val;

	if (*a && (*a)->next)
	{
		tmp_val = (*a)->value;
		(*a)->value = (*a)->next->value;
		(*a)->next->value = tmp_val;
	}
	if (n)
	{
		write(1,"s",1);
		write(1,&name,1);
		write(1,"\n",1);
	}
}

void 	swap_stacks(t_stack **a, t_stack **b, char n)
{
	swap(a, 0);
	swap(b, 0);
	if(n)
		write(1,"ss\n",3);
}
