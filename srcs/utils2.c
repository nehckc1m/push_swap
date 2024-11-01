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

t_stack	*find_highest(t_stack *stack)
{
	int		highest;
	t_stack	*highest_node;
	t_stack	*head;
	int		i;
	int		size;

	if (stack == NULL)
		return (NULL);
	size = stack_len(stack);
	head = stack;
	highest = stack->value;
	highest_node = stack;
	i = 0;
	while (i++ < size)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	free_all(t_stack **a, t_stack **b)
{
	if (a)
	{
		free_stack(a);
		free_stack(b);
	}
	if (b)
	{
		free(b);
		free(a);
	}
}

void	ft_error(t_stack **a, t_stack **b)
{
	ft_printf("Error\n");
	free_all(a, b);
	return ;
}

int	get_distance(t_stack **stack, int index)
{
	t_stack	*head;
	int		distance;
	int		i;
	int		len;

	i = 0;
	distance = 0;
	head = *stack;
	len = stack_len(head);
	while (i++ < len)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

int	check_ac_av(int *ac, char ***av)
{
	if (*ac < 2)
		return (0);
	if (*ac == 2 && (check_n(*av) == 1))
	{
		*av = ft_split((*av)[1], ' ');
		return (2);
	}
	return (1);
}
