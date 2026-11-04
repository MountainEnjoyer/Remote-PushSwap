/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 17:09:21 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/18 16:04:40 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*add;
	size_t			i;

	add = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		add[i] = (unsigned char)c;
		i++;
	}
	return ((void *)add);
}
