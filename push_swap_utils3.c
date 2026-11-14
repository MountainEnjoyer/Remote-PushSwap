/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 13:02:32 by zchauve           #+#    #+#             */
/*   Updated: 2026/11/14 15:03:10 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_stack(t_stack *head)
{
	t_stack	*tmp;
	int		len;

	tmp = head;
	len = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len ++;
	}
	return (len);
}

t_stack	*indexator(t_stack *head)
{
	t_stack	*tmp;
	t_stack	*actual;
	int		cont_act;
	int		index;
	int		t_len;

	tmp = head;
	actual = head;
	t_len = -1;
	while (++t_len < len_stack(head))
	{
		index = 0;
		cont_act = actual->content;
		while (tmp != NULL)
		{
			if (cont_act > tmp->content)
				index++;
			tmp = tmp->next;
		}
		tmp = head;
		actual->index = index;
		ft_printf("value = %d, index = %d, pos = %d\n", actual->content, actual->index, t_len);
		actual = actual->next;
	}
	return (head);
}
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
