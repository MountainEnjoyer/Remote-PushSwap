/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 13:02:32 by zchauve           #+#    #+#             */
/*   Updated: 2026/11/07 14:58:38 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
tstack	*insert_head(t_stack *head, int data)
{
	head->next = *head;
	head->previous = node;
	*head = node;
	return (node);
}*/

t_stack	*insert_tail(t_stack *head, int data)
{
	t_stack	*temp;
	t_stack	*tp;

	temp = malloc(sizeof(t_stack));
	temp->previous = NULL;
	temp->content = data;
	temp->next = NULL;
	tp = head;
	while (tp->next != NULL)
		tp = tp->next;
	tp->next = temp;
	temp->previous = tp;
	return (head);
}
