/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 16:55:10 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/24 19:46:43 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	print_nbr(int nbr, int count)
{
	int	temp1;
	int	temp2;

	temp1 = nbr / 10;
	temp2 = nbr % 10;
	if (temp1 > 9)
	{
		count += print_nbr(temp1, count);
	}
	else if (temp1 > 0)
	{
		temp1 = temp1 + '0';
		count += write(1, &temp1, 1);
	}
	if (count == -1)
		return (-1);
	temp2 = temp2 + '0';
	count += write(1, &temp2, 1);
	if (count == -1)
		return (-1);
	return (count);
}

int	ft_putnbr(int nb)
{
	char	sign;
	int		count;
	int		temp;

	sign = '-';
	count = 0;
	temp = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb >= 0)
	{
		count = print_nbr(nb, count);
	}
	else
	{
		nb = nb * -1;
		temp = write(1, &sign, 1);
		count += print_nbr(nb, count);
	}
	if (count == -1)
		return (count);
	return (count + temp);
}

// void    main(void)
// {
//     ft_putnbr(-6364645);
// }
