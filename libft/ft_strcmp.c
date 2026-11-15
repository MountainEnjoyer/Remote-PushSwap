/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:58:55 by zchauve           #+#    #+#             */
/*   Updated: 2026/11/13 12:55:34 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			j++;
		i++;
	}
	if (j == i && ft_strlen(s1) == ft_strlen(s2))
		return (1);
	return (-1);
}
