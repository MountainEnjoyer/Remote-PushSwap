/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:59:49 by zchauve           #+#    #+#             */
/*   Updated: 2026/11/14 15:16:07 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	verif(char **arg)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (arg[++i])
	{
		j = -1;
		while (arg[i][++j])
		{
			if (arg[i][0] == '-')
				break ;
			else if (!ft_isdigit(arg[i][j]) || ft_isalpha(arg[i][j]))
				return (-1);
			else
			{
				k = -1;
				while (arg[++k])
					if (i != k
						&& !ft_strncmp(arg[i], arg[k], ft_strlen(arg[i]) + 1))
						return (-1);
			}
		}
	}
	return (i);
}

static int	flag_verif(char **flags_to_verif)
{
	char	**flags;
	int		i;
	int		flag;

	flags = fetch_flag(flags_to_verif);
	if (flags == NULL)
		return (-1);
	i = -1;
	flag = 0;
	while (++i < count_flag(flags_to_verif))
	{
		if (ft_strncmp(flags[i], "simple", 6) == 0)
			flag |= FLAG_SIMPLE;
		else if (ft_strncmp(flags[i], "medium", 6) == 0)
			flag |= FLAG_MEDIUM;
		else if (ft_strncmp(flags[i], "complex", 7) == 0)
			flag |= FLAG_COMPLEXE;
		else if (ft_strncmp(flags[i], "adaptative", 10) == 0)
			flag |= FLAG_ADAPTIVE;
		else if (ft_strncmp(flags[i], "bench", 5) == 0)
			flag |= FLAG_BENCH;
		else
			return (-1);
	}
	return (flag);
}

static int	ft_parser(char **stack_a, int lenght, char **av)
{
	t_stack	*head;
	int		i;
	int		ver_flag;

	ver_flag = flag_verif(av);
	if (ver_flag < 0 || verif(stack_a) < 0)
		return (error(), 1);
	head = NULL;
	head = ft_stacknew(head, ft_atoi(stack_a[0]));
	i = 1;
	while (i < lenght)
	{
		head = insert_tail(head, ft_atoi(stack_a[i]));
		if (!head)
			return (error(), 1);
		i++;
	}
	head = indexator(head);
	ft_ps_logic(head, ver_flag);
	return (0);
}

static char	*concat(char **arg)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*arr;

	arr = ft_calloc((ft_strstrlen((const char **)arg) * 2 + 1), sizeof(char));
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

int	main(int ac, char **av)
{
	if (ac == 1 || (ac - count_flag(av)) == 1)
		return (error(), 1);
	if ((ac - count_flag(av)) == 2)
	{
		if (ft_parser(ft_split(locate(av), ' '), wcount(locate(av), ' '), av))
			return (1);
	}
	else if (locate_v(av) != NULL)
	{
		if (verif(&av[1]) <= 0)
			return (error(), 1);
		if (ft_parser(ft_split(concat(locate_v(av)), ' '),
				verif(locate_v(av)), av))
			return (1);
	}
	return (0);
}
