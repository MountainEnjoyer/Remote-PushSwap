/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 22:14:07 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/18 16:05:29 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	tot_size;
	size_t	i;
	size_t	j;

	if (s1 && s2)
	{
		tot_size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
		s3 = (char *)ft_calloc(tot_size + 1, sizeof(char));
		if (!s3)
			return (NULL);
		i = 0;
		j = -1;
		while (s1[++j])
			s3[i++] = s1[j];
		j = -1;
		while (s2[++j])
			s3[i++] = s2[j];
		s3[i] = '\0';
		return (s3);
	}
	return (NULL);
}
