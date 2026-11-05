/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:59:46 by zchauve           #+#    #+#             */
/*   Updated: 2026/11/05 16:59:46 by zchauve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	*fetch_flag(char **verifs)
{
	char	*flags;
	int		i;
	int		j;
	int		k;

	flags = ft_calloc(len_flag(verifs), sizeof(char));
	i = 0;
	k = 0;
	while (verifs[i])
	{
		j = 0;
		if (verifs[i][j] == '-' && verifs[i][j + 1] == '-')
		{
			while (verifs[i][j])
			{
				flags[k] = verifs[i][j];
				j++;
				k++;
			}
		}
		i++;
	}
	flags[k] = '\0';
	return (flags);
}
