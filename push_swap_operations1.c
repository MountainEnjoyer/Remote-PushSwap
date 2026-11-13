/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrossen <mgrossen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 01:05:42 by mgrossen          #+#    #+#             */
/*   Updated: 2026/11/13 03:22:13 by mgrossen         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_stack **stack)
{
	swap_toptwo(*stack);
	print_operation("sa");
}

void	sb(t_stack **stack)
{
	swap_toptwo(*stack);
	print_operation("sb");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_toptwo(*stack_a);
	swap_toptwo(*stack_b);
	print_operation("ss");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push_head(stack_a, pop_head(stack_b));
	print_operation("pa");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push_head(stack_b, pop_head(stack_a));
	print_operation("pb");
}
