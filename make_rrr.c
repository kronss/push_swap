/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:15:44 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/19 18:15:45 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void						make_rra(t_stack **head, char c)
{
	t_stack					*tmp;
	t_stack					*will_be_head;

	if ((*head) && (*head)->next)
	{
		tmp = *head;
		while (tmp->next->next)
			tmp = tmp->next;
		will_be_head = tmp->next;
		will_be_head->next = (*head);
		(*head) = will_be_head;
		tmp->next = NULL;
	}
	c == 1 ? ft_printf("rra\n") : 0;
}

void						make_rrb(t_stack **head, char c)
{
	t_stack					*tmp;
	t_stack					*will_be_head;

	if ((*head) && (*head)->next)
	{
		tmp = *head;
		while (tmp->next->next)
			tmp = tmp->next;
		will_be_head = tmp->next;
		will_be_head->next = (*head);
		(*head) = will_be_head;
		tmp->next = NULL;
	}
	c == 1 ? ft_printf("rrb\n") : 0;
}

void						make_rrr(t_stack **stack_a, t_stack **stack_b, char c)
{
	make_rra(stack_a, 0);
	make_rrb(stack_b, 0);
	c == 1 ? ft_printf("rrr\n") : 0;
}
