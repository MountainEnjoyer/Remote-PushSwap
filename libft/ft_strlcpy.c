/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <marvin@42.fr>                        +#+                    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:33:14 by zchauve        #+#    #+#                */
/*   Updated: 2026/10/18 22:39:16 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	slen;

	slen = 0;
	while (src[slen])
		slen++;
	i = 0;
	if (size == 0)
		return (slen);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}
