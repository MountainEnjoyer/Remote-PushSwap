/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:59:49 by zchauve           #+#    #+#             */
/*   Updated: 2026/11/04 17:00:55 by zchauve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_parser(char *stack_a, char *strat)
{
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		if (!ft_parser(av[1], ""))
			return (-1);
	else if (ac == 3)
		if (!ft_parser(av[1], av[2]))
			return (-1);
	return (0);
}
