/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <marvin@42.fr>                        +#+                    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 18:56:54 by zchauve        #+#    #+#                */
/*   Updated: 2026/10/18 15:25:53 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	count;
	char	*p;
	int		found;

	i = 0;
	found = 0;
	count = 0;
	p = (char *)s;
	while (i <= ft_strlen(p))
	{
		if ((unsigned char)p[i] == (unsigned char)c)
		{
			count = i;
			found = 1;
		}
		i++;
	}
	if (found == 0)
		return (NULL);
	return (&p[count]);
}
