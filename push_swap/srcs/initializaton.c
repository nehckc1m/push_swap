/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializaton.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 02:34:25 by micchen           #+#    #+#             */
/*   Updated: 2024/06/12 02:34:31 by micchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**init_tab(int ac, char **av, int *c)
{
	int 		i;
	int 		j;
	char 	**res;

	i = -1;
	while (++i < ac)
		*c += count_words(av[i]);
	res = malloc((*c + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (i < *c)
	{
		if (count_words(av[j]) > 1)
			ft_tabcat(&res, av[j++], &i);
		else
			res[i] = ft_strdup(av[j++]);
		i++;
	}
	res[i] = 0;
	return (res);
}

void	append_node(t_stack **a, int n)
{
	t_stack *node;
	t_stack *last;
	
	if (!stack)
		return;
	node = malloc(sizeof(t_stack));
	if (!node)
		return;
	node->next = NULL;
	node->value = n;
	if (!(*stack))
	{
		*stack = node;
		node->previous = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->previous = last node;
	}
}

void	init_stack(t_stack **a, char **av)
{
	int 	i;
	int 	*res;
	long int 	atoi_res;

	len = 0;
	i = 0;
	while(tab[len])
		len++;
	res = malloc(sizeof(int) * len);
	while (av[i])
	{
		if (is_number(tab[i]))
		{
			atoi_res = ft_atoi(tab[i]);
			if (atoi_res > INT_MAX || atoi_res < INT_MIN)
				return (NULL);
			append_node(a, (int)n);
			i++;
		}
	}
}

int check_double(int *array, int len)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] == array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
