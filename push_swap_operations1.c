/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrossen <mgrossen@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 01:05:42 by mgrossen          #+#    #+#             */
/*   Updated: 2026/11/09 13:53:14 by mgrossen         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	print_operation(char *operation_str)
{
	ft_printf("%s\n", operation_str);
}

void	sa(t_stack *stack)
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
	print_operation("sa");
}

void	sb(t_stack *stack)
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
	print_operation("sb");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	
}
