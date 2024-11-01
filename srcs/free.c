/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:19:22 by micchen           #+#    #+#             */
/*   Updated: 2024/06/12 00:21:30 by micchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack || !(*stack))
		return ;
	current = *stack;
	while (current->next != *stack)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(current);
	*stack = NULL;
}

void	free_error(t_stack **stack)
{
	free_stack(stack);
	write(1, "Error\n", 6);
	exit(1);
}
