/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:13:20 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/24 22:54:52 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

static int	ft_putadr(void *s, int ye, uintptr_t rec, int count)
{
	uintptr_t		adr;
	char			*hex;
	int				test_write;

	hex = "0123456789abcdef";
	adr = rec;
	test_write = 0;
	if (!s)
	{
		test_write = ft_putstr_fd("(nil)", 1);
		return (test_write);
	}
	if (rec <= 0)
		adr = (uintptr_t)s;
	if (!ye)
		if (ft_putstr_fd("0x", 1) == -1)
			return (-1);
	if (adr >= 16)
		count += ft_putadr(s, 1, (adr / 16), count) + 1;
	if (ft_putchar_fd(hex[adr % 16], 1) == -1)
		return (-1);
	if (!ye)
		return (count + 3);
	return (count);
}

static int	parssing(char c, va_list arg)
{
	int	res;

	res = 0;
	if (c == 'c')
		res = ft_putchar_fd((char)va_arg(arg, int), 1);
	else if (c == 's')
		res = ft_putstr_fd(va_arg(arg, char *), 1);
	else if (c == 'p')
		res = ft_putadr(va_arg(arg, void *), 0, 0, 0);
	else if (c == 'd')
		res = ft_putnbr(va_arg(arg, int));
	else if (c == 'i')
		res = ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		res = ft_putunbr_fd(va_arg(arg, unsigned int), 1);
	else if (c == 'x')
		res = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		res = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		res = ft_putchar_fd('%', 1);
	if (res == -1)
		return (-1);
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	argptr;
	int		count;
	int		temp;

	count = 0;
	temp = 0;
	if (format)
		va_start(argptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			temp = parssing(*format, argptr);
		}
		else
			temp = write(1, format, 1);
		if (temp == -1)
			return (-1);
		count += temp;
		format++;
	}
	return (count);
}
