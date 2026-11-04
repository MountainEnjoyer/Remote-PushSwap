/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <marvin@42.fr>                        +#+                    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 20:23:22 by zchauve        #+#    #+#                */
/*   Updated: 2026/10/18 17:05:04 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*alloc;
	size_t	total;
	size_t	i;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (size > (size_t)-1 / nmemb)
		return (NULL);
	total = nmemb * size;
	alloc = malloc(total);
	if (!alloc)
		return (NULL);
	i = 0;
	while (i < total)
	{
		alloc[i] = '\0';
		i++;
	}
	return ((void *)alloc);
}
