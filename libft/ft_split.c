/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 15:15:53 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/18 15:17:34 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**free_all(char **arr, int count)
{
	while (count > 0)
		free(arr[--count]);
	free(arr);
	return (NULL);
}

static int	wcount(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char		**new;
	const char	*start;
	int			j;

	if (!s)
		return (NULL);
	new = ft_calloc(wcount(s, c) + 1, sizeof(char *));
	if (!new)
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		start = s;
		while (*s && *s != c)
			s++;
		new[j] = ft_substr(start, 0, s - start);
		if (!new[j])
			return (free_all(new, j));
		j++;
	}
	return (new);
}
