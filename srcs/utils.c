/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:18:43 by micchen           #+#    #+#             */
/*   Updated: 2024/08/29 01:50:51 by micchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char **av)
{
	int	i;
	int	len;
	int	j;

	i = 1;
	while (av[i])
	{
		j = -1;
		len = ft_strlen(av[i]);
		if (av[i][0] == '-' || av[i][0] == '+')
			j++;
		while (++j < len)
		{
			if (!((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == ' '))
			{
				ft_printf("Error\n");
				return (0);
			}
			if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
				return (0);
		}
		i++;
	}
	return (1);
}
/*
char	*ft_strdup(const char *s)
{
	int		slen;
	int		i;
	char	*res;

	i = 0;
	slen = ft_strlen(s);
	res = malloc((slen + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i <= slen)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

void 	ft_tabcat(char ***dest, char *src, int *index)
{
	char	**w_tab;
	int 		tab_len;
	int		i;
	
	i = 0;
	tab_len = count_words(src);
	w_tab = ft_split(src);
	while (i < tab_len)
	{
		(*dest)[*index] = ft_strdup(w_tab[i]);
		i++;
		(*index)++;
	}
	(*index)--;
}*/

/*t_stack	*find_last_node(t_stack *stack)
{
	
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}*/

int	stack_len(t_stack *stack)
{
	int		count;
	t_stack	*head;
	t_stack	*tmp;

	head = stack;
	tmp = stack;
	count = 1;
	while (tmp->next != head)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

static	t_stack	*get_next_min(t_stack **stack)
{
	t_stack	*head;
	t_stack	*min;
	int		has_min;
	int		i;
	int		size;

	size = stack_len(*stack);
	i = 0;
	min = NULL;
	has_min = 0;
	head = *stack;
	while (i++ < size)
	{
		if ((head->index < 0) && (!has_min || head->value < min->value))
		{
			min = head;
			has_min = 1;
		}
		head = head->next;
	}
	return (min);
}

void	index_stack(t_stack **stack)
{
	t_stack	*head;
	int		index;
	int		i;
	int		size;

	size = stack_len(*stack);
	i = 0;
	index = 0;
	head = get_next_min(stack);
	while (i++ < size)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}
