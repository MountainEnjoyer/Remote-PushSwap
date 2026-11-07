/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:01:07 by zchauve           #+#    #+#             */
/*   Updated: 2026/11/07 14:52:41 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(t_stack *head, int content)
{
	t_stack	*temp;

	temp = malloc(sizeof(t_stack));
	if (!temp)
		return (NULL);
	temp->content = content;
	temp->previous = NULL;
	temp->next = NULL;
	head = temp;
	return (head);
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
