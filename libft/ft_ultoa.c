/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 22:33:53 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/22 23:44:05 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_digit(unsigned long long n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count ++;
		n = n / 10;
	}
	return (count);
}

char	*ft_ultoa(unsigned long n)
{
	char				*result;
	unsigned long long	nb;
	int					count;
	int					i;

	nb = n;
	if (n == 0)
		return (ft_strdup("0"));
	count = count_digit(nb);
	result = ft_calloc(count + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = count - 1 ;
	while (i >= 0)
	{
		result[i] = (nb % 10) + 48;
		if (nb > 9)
			nb = nb / 10;
		i--;
	}
	return (result);
}
