/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:53:52 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/18 16:04:53 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;
	char			*ptr;

	if (!s || !f)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!res)
		return (NULL);
	ptr = (char *)s;
	i = 0;
	while (ptr[i])
	{
		res[i] = f(i, ptr[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
