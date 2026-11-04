/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 19:23:02 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/16 14:37:34 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	dlen;

	if (!src || !dst)
		return (0);
	dlen = 0;
	while (dst[dlen])
		dlen++;
	srclen = 0;
	while (src[srclen])
		srclen++;
	if (size < dlen)
		return (size + srclen);
	i = 0;
	while ((dlen + i + 1) < size && src[i] && size > 0)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return ((dlen + srclen));
}
