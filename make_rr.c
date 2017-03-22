/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 23:15:24 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/17 23:15:25 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void						make_ra(t_stack **head, char c)
{
	t_stack			*last;
	t_stack			*tmp;

	if ((*head) && (*head)->next)
	{
		last = *head;
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = last;
		(*head) = (*head)->next;
		last->next = NULL;
	}
	c == 1 ? ft_printf("ra\n") : 0;
}

void						make_rb(t_stack **head, char c)
{
	t_stack			*last;
	t_stack			*tmp;

	if ((*head) && (*head)->next)
	{
		last = *head;
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = last;
		(*head) = (*head)->next;
		last->next = NULL;
	}
	c == 1 ? ft_printf("rb\n") : 0;
}

void						make_rr(t_stack **stack_a, t_stack **stack_b, char c)
{
	make_ra(stack_a, 0);
	make_rb(stack_b, 0);
	c == 1 ? ft_printf("rr\n") : 0;
}
