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

/*int	**init_tab(int ac, char **av, int *c)
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
*/
void	append_node(t_stack **a, int n)
{
	t_stack	*node;
	t_stack	*last;

	if (!a)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->value = n;
	node->index = -1;
	if (!(*a))
	{
		*a = node;
		node->next = node;
	}
	else
	{
		last = *a;
		while (last->next != *a)
			last = last->next;
		last->next = node;
		node->next = *a;
	}
}
/*
void print_stack(t_stack *a)
{
    t_stack *start = a;  // Sauvegarde du début de la liste pour vérifier la fin

    if (a)
    {
        do {
            printf("value: %d\n", a->value);  // Affiche la valeur du nœud actuel
            a = a->next;  // Passe au nœud suivant
        } while (a != start);  // Continue jusqu'à revenir au nœud de départ
    }
}*/

int	init_stack(t_stack **a, char **av)
{
	int			i;
	long int	atol_res;

	i = 0;
	while (av[i])
	{
		if (check_number(av))
		{
			atol_res = ft_atol(av[i]);
			if (atol_res > INT_MAX || atol_res < INT_MIN)
				return (0);
			append_node(a, (int)atol_res);
		}
		i++;
	}
	index_stack(a);
	return (1);
}

int	check_double(char **array, int start)
{
	int	i;
	int	j;
	int	len;

	len = start;
	i = start;
	j = i + 1;
	while (array[len])
		len++;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(array[i]) == ft_atoi(array[j]))
			{
				ft_printf("Error\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
