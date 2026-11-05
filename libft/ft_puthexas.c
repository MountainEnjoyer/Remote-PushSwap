/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 20:16:29 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/23 01:39:20 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexas(void *data, int up)
{
	char			*s;
	unsigned char	c;
	char			*hex;

	hex = "0132456789abcdef";
	if (up)
		hex = "0132456789ABCDEF";
	s = (char *)data;
	while (*s)
	{
		c = *s;
		ft_putchar_fd(hex[c / 16], 1);
		ft_putchar_fd(hex[c % 16], 1);
		s++;
	}
}
