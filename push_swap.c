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

static int	flag_verif(s_stack **head_a, char **flags_to_verif)
{
	head_a = NULL;
	ft_printf("flags = %s", fetch_flag(flags_to_verif));
	return (0);
}

static int	ft_parser(char **stack_a, int lenght, char **av)
{
	s_stack	*last;
	s_stack	**head;
	s_stack	*actual;
	int		i;

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
	if (flag_verif(head, av))
		return (error(), 1);
	return (0);
}

static char	*concat(char **arg)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*arr;

	arr = malloc(sizeof(char) * (ft_strstrlen((const char **)arg) * 2) + 1);
	if (!arr)
		return (error(), NULL);
	i = 0;
	k = 0;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			arr[k] = arg[i][j];
			arr[k + 1] = ' ';
			j++;
			k += 2;
		}
		i++;
	}
	arr[k] = '\0';
	return (arr);
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
			else if (!ft_isdigit(arg[i][j]) || ft_isalpha(arg[i][j]))
				return (error(), -1);
			j++;
		}
		i++;
	}
	return (i);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (error(), 1);
	if (ac == 2)
	{
		if (ft_parser(ft_split(av[1], ' '), wcount(av[1], ' '), av))
			return (1);
	}
	else if (ac == 3)
	{
		if (ft_parser(ft_split(av[2], ' '), wcount(av[2], ' '), av))
			return (1);
	}
	else if (ac > 3)
	{
		if (!verif(&av[1]))
			return (1);
		else
			if (ft_parser(ft_split(concat(&av[1]), ' '), verif(&av[1]), av))
				return (1);
	}
	return (0);
}
