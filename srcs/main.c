/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:01:25 by micchen           #+#    #+#             */
/*   Updated: 2024/08/29 01:48:40 by micchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_lists(char ***array, int i, t_stack **a, t_stack **b)
{
	if (!(check_number(*array)))
	{
		free_all(a, b);
		return (0);
	}
	if (!(check_double(*array, i)))
	{
		free_all(a, b);
		free_av(*array);
		return (0);
	}
	return (1);
}

static void	sorting(t_stack **a, t_stack **b)
{
	if (!is_sorted(*a))
	{
		if (stack_len(*a) == 2)
			rotate_stack(a, 'a');
		else if (stack_len(*a) <= 5)
			simple_sort(a, b);
		else if (stack_len(*a) > 5)
			radix(a, b);
	}
}

int	check_n(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if (av[1][i + 1] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	free_av(char **av)
{
	int	i;

	i = 0;
	if (!av)
		return ;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

int	main(int ac, char **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	int		i;
	int		check;

	i = 0;
	if ((ac == 2 && check_number(av) == 0) || (ac == 2 && (check_n(av) == 0))
		|| (ac > 2 && check_double(av, i + 1) == 0)
		|| (ac > 2 && check_number(av) == 0))
		return (0);
	stack_a = (t_stack **)malloc(sizeof(t_list));
	stack_b = (t_stack **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	check = check_ac_av(&ac, &av);
	if (check == 1)
		av = av + 1;
	if (!(check_lists(&av, i, stack_a, stack_b)))
		return (0);
	init_stack(stack_a, av);
	if (ac == 2)
		free_av(av);
	sorting(stack_a, stack_b);
	free_all(stack_a, stack_b);
	return (0);
}
