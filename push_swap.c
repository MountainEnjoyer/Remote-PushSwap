/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:59:49 by zchauve           #+#    #+#             */
/*   Updated: 2026/11/06 14:41:00 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	flag_verif(s_stack **head_a, char **flags_to_verif)
{
	while (*head_a)
	{
		ft_printf("head_a int value = %d\n", (*head_a)->content);
		*head_a = (*head_a)->previous;
	}
	ft_printf("flags = %s\n", fetch_flag(flags_to_verif));
	return (0);
}

static int	ft_parser(char **stack_a, int lenght, char **av)
{
	s_stack	**head;
	s_stack	*prev;
	s_stack	*actual;
	s_stack	*next;
	int		i;

	actual = NULL;
	i = (lenght);
	while (i-- >= 0)
	{
		actual = ft_stacknew(ft_atoi(stack_a[i]), actual);
		actual->previous = prev;
		prev->next = actual;
		if (!actual)
			return (error(), -1);
	}
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

	arr = ft_calloc((ft_strstrlen((const char **)arg) * 2 + 2), sizeof(char));
	if (!arr)
		return (error(), NULL);
	i = 0;
	k = 0;
	while (arg[i])
	{
		j = -1;
		while (arg[i][++j])
		{
			arr[k] = arg[i][j];
			k++;
		}
		arr[k++] = ' ';
		i++;
	}
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
		if (ft_parser(ft_split(locate(av), ' '), wcount(locate(av), ' '), av))
			return (1);
	if (ac == 3)
		if (ft_parser(ft_split(locate(av), ' '), wcount(locate(av), ' '), av))
			return (1);
	if (ac == 4)
		if (ft_parser(ft_split(locate(av), ' '), wcount(locate(av), ' '), av))
			return (1);
	if (ac > 4)
	{
		if (!verif(&av[1]))
			return (1);
		if (ft_parser(ft_split(concat(locate_v(av)), ' '), verif(locate_v(av)), av))
			return (1);
	}
	return (0);
}
