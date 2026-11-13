/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrossen <mgrossen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 03:22:28 by mgrossen          #+#    #+#             */
/*   Updated: 2026/11/13 03:28:55 by mgrossen         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	*stack_a = (*stack_a)->previous;
	print_operation("ra");
}

void	rb(t_stack **stack_b)
{
	*stack_b = (*stack_b)->previous;
	print_operation("rb");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = (*stack_a)->previous;
	*stack_b = (*stack_b)->previous;
	print_operation("rr");
}
