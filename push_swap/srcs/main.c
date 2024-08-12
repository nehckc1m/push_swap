/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:01:25 by micchen           #+#    #+#             */
/*   Updated: 2024/06/11 22:36:10 by micchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2 && is_number()
		av = split(av[1]);
	if (is_number(av) == 0)
		return (1);
	else
		init_stack(&stack_a, av + 1);
	if (!is_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			rotate_stack(&a,a);
		if (stack_len(stack_a) == 3)
			tiny_sort(&stack_a);
		if (stack_len(stack_a) > 3)
			sort(&stack_a, &stack_b);
	}
	ft_free(&stack_a);
	return (0);
}
