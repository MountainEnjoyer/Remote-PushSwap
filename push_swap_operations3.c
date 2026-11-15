/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrossen <mgrossen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 01:02:21 by mgrossen          #+#    #+#             */
/*   Updated: 2026/11/14 01:03:32 by mgrossen         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = (*stack_a)->next;
	*stack_b = (*stack_b)->next;
	print_operation("rrr");
}
