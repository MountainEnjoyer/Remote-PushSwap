/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:01:07 by zchauve           #+#    #+#             */
/*   Updated: 2026/11/04 17:02:55 by zchauve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_stack	*ft_stacknew(int content, s_stack *prev)
{
	s_stack	*new_list;

	new_list = malloc(sizeof(s_stack));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->previous = prev;
	new_list->next = NULL;
	return (new_list);
}

int	wcount(char const *s, char c)
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

size_t	ft_strstrlen(const char **s)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		count += ft_strlen(s[i]);
		i++;
	}
	return (count);
}


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	error(void)
{
	write(2, "Error\n", 6);
}
