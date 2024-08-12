/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:18:43 by micchen           #+#    #+#             */
/*   Updated: 2024/05/28 19:25:41 by micchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	is_number(char *str)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(str);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (++i < len)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
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

void 	find_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_len(t_stack *stack)
{
	int	count;
	
	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
	
	
	
	
