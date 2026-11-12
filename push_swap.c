/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:59:49 by zchauve           #+#    #+#             */
/*   Updated: 2026/11/12 19:01:46 by zchauve          ###   ########.ch       */
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

	flags = fetch_flag(flags_to_verif);
	if (!flags)
		return (-1);
	i = 0;
	while (flags[i])
	{
		if (!ft_strncmp(flags[i], "simple", 6))
			ft_printf("simple flag\n");
		else if (!ft_strncmp(flags[i], "medium", 6))
			ft_printf("medium flag\n");
		else if (!ft_strncmp(flags[i], "complex", 7))
			ft_printf("complex flag\n");
		else if (!ft_strncmp(flags[i], "adaptative", 10))
			ft_printf("adaptative flag\n");
		else if (!ft_strncmp(flags[i], "bench", 5))
			ft_printf("bench flag\n");
		else
			return (-1);
		i++;
	}
	return (i);
}

static int	ft_parser(char **stack_a, int lenght, char **av)
{
	t_stack	*head;
	int		i;

	if (flag_verif(av) < 0 || verif(stack_a) < 0)
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
	t_stack	*tmp;
	tmp = head;
	while (tmp != NULL)
	{
		ft_printf("head_a int value from top = %d\n", tmp->content);
		if (tmp->next == NULL)
		{
			tmp = tmp->previous;
			break ;
		}
		tmp = tmp->next;
	}
	while (tmp != NULL)
	{
		ft_printf("head_a int value from bott = %d\n", tmp->content);
		tmp = tmp->previous;
	}
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
			return (1);
		if (ft_parser(ft_split(concat(locate_v(av)), ' '), verif(locate_v(av)), av))
			return (1);
	}
	return (0);
}
