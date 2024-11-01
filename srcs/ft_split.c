/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 02:33:06 by micchen           #+#    #+#             */
/*   Updated: 2024/06/12 02:33:18 by micchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	res;

	res = 0;
	while (s[res])
		res ++;
	return (res);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	i;
	char	*res;

	i = 0;
	slen = ft_strlen(s);
	if (slen <= len + start)
		len = slen - start;
	if (start >= slen)
		len = 0;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int	word_len(char const *s)
{
	int	i;

	i = 0;
	while (s[i] && !(s[i] == ' '))
		i++;
	return (i);
}

int	count_words(char const *s)
{
	int	i;
	int	in_word;
	int	count;

	i = 0;
	in_word = 0;
	count = 0;
	while (s[i])
	{
		if (!(s[i] == ' ') && !in_word)
		{
			count++;
			in_word = 1;
		}
		if ((s[i] == ' ') && in_word)
			in_word = 0;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s)
{
	char	**res;
	int		j;
	int		in_word;

	j = 0;
	in_word = 0;
	res = (char **) malloc((count_words(s) + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	while (*s)
	{
		if (!(*s == ' ') && !in_word)
		{
			res[j] = ft_substr(s, 0, word_len(s));
			in_word = 1;
			j++;
		}
		if ((*s == ' ') && in_word)
			in_word = 0;
		s++;
	}
	res[j] = 0;
	return (res);
}
