/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_logic1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrossen <mgrossen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 17:51:19 by mgrossen          #+#    #+#             */
/*   Updated: 2026/11/08 18:25:46 by mgrossen         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	ft_dissorder_mesure(t_stack *stack)
{
	int		mistakes;
	int		pairs;
	t_stack *i;
	t_stack	*j;

	mistakes = 0;
	pairs = 0;
	i = stack;
	while (i->next != stack)
	{
		j = i->next;
		while (j != stack)
		{
			pairs++;
			if (i->content > j->content)
				mistakes++;
			j = j->next
		}
		i = i->next;
	}
	return ((mistakes / pairs) * 100);

}

void	ft_ps_logic(t_stack *stack_a, int flags)
{
	int	dissorder;

	dissorder = -1;
	if (flags & (FLAG_BENCH | FLAG_ADAPTIVE))
		dissorder = ft_dissorder_mesure(stack_a);
	if (flags & FLAG_SIMPLE)
		ft_simple(stack_a);
	else if (flags & FLAG_MEDIUM)
		ft_medium(stack_a);
	else if (flags & FLAG_COMPLEXE)
		ft_complexe(stack_a);
	else
	{
		if (dissorder < 20)
			ft_simple(stack_a);
		else if (dissorder >= 20 && dissorder < 50)
			ft_medium(stack_a);
		else
			ft_complexe(stack_a);
	}

}
