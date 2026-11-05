/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:59:49 by zchauve           #+#    #+#             */
/*   Updated: 2026/11/04 20:19:18 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_parser(char **stack_a, int lenght, char *strat)
{
	stack_list	*last;
	stack_list	**head;
	stack_list	*actual;
	int			i;

	if (strat)
		return (error(), 0);
	actual = NULL;
	i = (lenght - 1);
	while (i >= 0)
	{
		actual = ft_stacknew(ft_atoi(stack_a[i]), actual);
		if (!actual)
			return (error(), -1);
		if (i == (lenght - 1))
			last = actual;
		i--;
	}
	actual->previous = last;
	head = &actual;
	return (0);
}

static int	concat(char **arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ()
}

static int	verif(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			if (arg[i][0] == '-')
				break;
			if (!ft_isdigit(arg[i][j]) || ft_isalpha(arg[i][j]))
				return (error(), -1);
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (error(), 1);
	if (ac == 2)
	{
		if (!ft_parser(ft_split(av[1], ' '), wcount(av[1], ' '), NULL))
			return (1);
	}
	else if (ac == 3)
	{
		if (!ft_parser(ft_split(av[1], ' '), wcount(av[1], ' '), av[2]))
			return (1);
	}
	else if (ac > 3)
	{
		if (!concat(&av[1]))
			return (1);
	}
	return (0);
}
