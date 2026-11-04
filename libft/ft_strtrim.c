/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 22:54:11 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/18 16:05:16 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_isset(char c, const char *set)
{
	int		i;
	char	*ptr;

	ptr = (char *)set;
	i = 0;
	while (ptr[i])
	{
		if (c == ptr[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p1;
	char	*p2;
	char	*res;

	if (!s1)
		return (NULL);
	p1 = (char *)s1;
	p2 = (char *)s1 + 1;
	if (p2[1])
		p2 = (char *)s1 + (ft_strlen((char *)s1) - 1);
	while (ft_isset(*p1, set) && *p1)
		p1++;
	while (ft_isset(*p2, set) && *p2)
		p2--;
	res = ft_substr((char const *)p1, 0, (p2 - p1) + 1);
	return (res);
}
