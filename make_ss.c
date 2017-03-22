/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 22:06:48 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/17 22:06:49 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void						make_pb(t_stack **stack_a, t_stack **stack_b, char c)
{
	t_stack *tmp;

	if (*stack_a)
	{
		tmp = *stack_a;

		*stack_a = (*stack_a)->next;

		tmp->next = (*stack_b);
		*stack_b = tmp;
	}
	c == 1 ? ft_printf("pb\n") : 0;
}

void						make_pa(t_stack **stack_a, t_stack **stack_b, char c)
{
	t_stack *tmp;

	if (*stack_b)
	{
		tmp = *stack_b;

		*stack_b = (*stack_b)->next;

		tmp->next = (*stack_a);
		*stack_a = tmp;
	}
	c == 1 ? ft_printf("pa\n") : 0;
}

void			make_sa(t_stack **head, char c)
{
	t_stack		*frst;
	t_stack		*scnd;

	frst = (*head);
	if (frst && frst->next)
	{
		scnd = frst->next;
		frst->next = scnd->next;
		scnd->next = frst;
		(*head) = scnd;
	}
	c == 1 ? ft_printf("sa\n") : 0;
}

void			make_sb(t_stack **head, char c)
{
	t_stack		*frst;
	t_stack		*scnd;

	frst = (*head);
	if (frst && frst->next)
	{
		scnd = frst->next;
		frst->next = scnd->next;
		scnd->next = frst;
		(*head) = scnd;
	}
	c == 1 ?  ft_printf("sb\n") : 0;
}

void			make_ss(t_stack **stack_a, t_stack **stack_b, char c)
{
	make_sa(stack_a, 0);
	make_sb(stack_b, 0);
	c == 1 ? ft_printf("ss\n") : 0;
}
