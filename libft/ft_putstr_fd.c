/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:25:40 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/23 19:29:30 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	if (write(fd, s, ft_strlen(s)) == -1)
		return (-1);
	return (ft_strlen((const char *)s));
}
