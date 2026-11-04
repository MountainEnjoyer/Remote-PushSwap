/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:01:07 by zchauve           #+#    #+#             */
/*   Updated: 2026/11/04 17:02:55 by zchauve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(const char *s)
{
	size_t	i;

	while (s[i])
		i++;
	return (i);
}

void	error(char *er)
{
	write(2, er, ft_strlen((const) er));
}
