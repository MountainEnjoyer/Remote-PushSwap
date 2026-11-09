/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrossen <mgrossen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 01:05:42 by mgrossen          #+#    #+#             */
/*   Updated: 2026/11/10 00:23:20 by mgrossen         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	print_operation(char *operation_str)
{
	ft_printf("%s\n", operation_str);
}

void	swap_toptwo(t_stack *stack)
{
	int	temp_index;
	int	temp_content;

	if (!stack || !stack->next || stack->next == stack)
		return ;
	temp_index = stack->index;
	temp_content = stack->content;
	stack->index = stack->next->index;
	stack->content = stack->next->content;
	stack->next->index = temp_index;
	stack->next->content = temp_content;
}

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
	t_stack	*temp_ptr;

	if (!(*stack_b))
		return ;
	if (!(*stack_a))
	{
		*stack_a = *stack_b;
		(*stack_b)->previous->next = (*stack_b)->next;
		(*stack_b)->next->previous = (*stack_b)->previous;
		*stack_b = (*stack_b)->next;
		(*stack_a)->previous = *stack_a;
		(*stack_a)->next = *stack_a;
	}
	temp_ptr = (*stack_b)->next;
	(*stack_b)->previous->next = (*stack_b)->next;
	(*stack_b)->next->previous = (*stack_b)->previous;
	(*stack_a)->previous->next = *stack_b;
	(*stack_b)->previous = (*stack_a)->previous;
	(*stack_b)->next = *stack_a;
	(*stack_a)->previous = *stack_b;
	*stack_a = (*stack_a)->previous;
	*stack_b = temp_ptr;
	if (*stack_b == *stack_a)
		*stack_b = NULL;
}
