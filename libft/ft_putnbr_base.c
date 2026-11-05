/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 19:47:40 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/23 09:43:10 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdio.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (j == i)
				j++;
			if (base[j] == base[i])
				return (1);
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
			return (1);
		i++;
	}
	if (i == 0 || i == 1)
		return (1);
	return (0);
}

int	print_nbr(long long nbr, char *base, int bas, int count)
{
	int	temp1;
	int	temp2;

	temp1 = nbr / bas;
	temp2 = nbr % bas;
	if (temp1 > bas - 1)
	{
		count += print_nbr(temp1, base, bas, count);
	}
	else if (temp1 > 0)
	{
		count += write(1, &base[temp1], 1);
	}
	count += write(1, &base[temp2], 1);
	return (count);
}

int	ft_putnbr_base(long long nbr, char *base)
{
	int						bas;
	long long				nb;
	int						count;

	count = 0;
	nb = nbr;
	if (check_base(base) == 1)
		return (0);
	bas = (int)ft_strlen((const char *)base);
	if (nb >= 0)
		count += print_nbr(nb, base, bas, count);
	else
	{
		nb = nb * -1;
		count += print_nbr(nb, base, bas, count);
	}
	return (count);
}
