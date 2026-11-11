/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrossen <mgrossen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 15:22:12 by mgrossen          #+#    #+#             */
/*   Updated: 2026/11/11 16:02:17 by mgrossen         ###   ########.ch       */
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

t_stack	*pop_head(t_stack **stack)
{
	t_stack	*return_ptr;

	return_ptr = *stack;
	(*stack)->previous->next = (*stack)->next;
	(*stack)->next->previous = (*stack)->previous;
	*stack = (*stack)->next;
	return_ptr->next = return_ptr;
	return_ptr->previous = return_ptr;
	return (return_ptr);
}
