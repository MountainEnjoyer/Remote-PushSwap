/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 22:33:53 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/23 21:27:08 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_digit(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		count ++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	nb;
	int		count;
	int		i;

	nb = n;
	if (n == 0)
		return (ft_strdup("0"));
	count = count_digit(nb);
	result = ft_calloc(count + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = count - 1 ;
	if (nb < 0)
		nb *= -1;
	while (i >= 0)
	{
		result[i] = (nb % 10) + 48;
		if (nb > 9)
			nb = nb / 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
