/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_simple.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrossen <mgrossen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 21:15:10 by mgrossen          #+#    #+#             */
/*   Updated: 2026/11/17 21:57:35 by mgrossen         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_simple(t_stack *stack_a, t_stack *stack_b)
{
	int	longest_ordered;

	longest_ordered = ft_s_getlongest(stack_a, stack_b);
	ft_s_pushtob(stack_a, stack_b, longest_ordered);
	ft_s_sort(stack_a, stack_b);
}
