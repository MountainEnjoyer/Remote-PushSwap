/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:59:46 by zchauve           #+#    #+#             */
/*   Updated: 2026/11/14 14:22:21 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**locate_v(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]))
				return (&av[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*locate(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]))
				return (av[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

int	count_flag(char **flag)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (flag[i])
	{
		j = 0;
		if (flag[i][j] == '-' && flag[i][j + 1] == '-')
			count++;
		i++;
	}
	return (count);
}

int	len_flag(char **flag)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (flag[i])
	{
		j = 0;
		if (flag[i][j] == '-' && flag[i][j + 1] == '-')
		{
			while (flag[i][j])
			{
				count++;
				j++;
			}
		}
		i++;
	}
	return (count);
}

char	**fetch_flag(char **verifs)
{
	char	*flags;
	int		i;
	int		j;
	int		k;

	flags = ft_calloc(len_flag(verifs) + 1, sizeof(char));
	i = -1;
	k = -1;
	while (verifs[++i])
	{
		j = 0;
		if (verifs[i][j] == '-' && verifs[i][j + 1] == '-'
			&& verifs[i][j + 2] != '-')
		{
			while (verifs[i][j])
				flags[++k] = verifs[i][j++];
		}
		if ((verifs[i][j] == '-' && verifs[i][j + 1] != '-') ||
		(verifs[i][j] == '-' && verifs[i][j + 1] == '-' && verifs[i][j + 2] == '-'))
			return (NULL);
	}
	return (ft_split(flags, '-'));
}
