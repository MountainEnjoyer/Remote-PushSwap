/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:32:32 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/23 19:49:40 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	*s;
	int		len;

	s = ft_itoa(n);
	if (!s)
	{
		free(s);
		return (0);
	}
	len = (int)ft_strlen((const char *)s);
	if (ft_putstr_fd(s, fd) == -1)
		return (-1);
	free(s);
	return (len);
}
