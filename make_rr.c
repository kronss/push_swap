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

void				make_ra(t_stack **stack_a, t_stack **stack_b, char c, t_block *block)
{
	t_stack			*last;
	t_stack			*tmp;

	if ((*stack_a) && (*stack_a)->next)
	{
		last = *stack_a;
		tmp = *stack_a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = last;
		(*stack_a) = (*stack_a)->next;
		last->next = NULL;
	}
	if (c == 1)
	{
		ft_printf("ra\n");
		operation_push_back(block->oper, "ra") ;
	}
	block->debug == 1 ? ft_printf("ra\n") && print_stacks(*stack_a, *stack_b) : 0;
}

void				make_rb(t_stack **stack_a, t_stack **stack_b, char c, t_block *block)
{
	t_stack			*last;
	t_stack			*tmp;

	if ((*stack_b) && (*stack_b)->next)
	{
		last = *stack_b;
		tmp = *stack_b;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = last;
		(*stack_b) = (*stack_b)->next;
		last->next = NULL;
	}
	if (c == 1)
	{
		ft_printf("rb\n");
		operation_push_back(block->oper, "rb");
	}
	block->debug == 1 ? ft_printf("rb\n") && print_stacks(*stack_a, *stack_b) : 0;
}

void				make_rr(t_stack **stack_a, t_stack **stack_b, char c, t_block *block)
{
	if (block->debug == 1)
	{
		block->debug = 0;
		make_ra(stack_a, stack_b, 0, 0);
		make_rb(stack_b, stack_a, 0, 0);
		block->debug = 1;
	}
	else
	{
		make_ra(stack_a, stack_b, 0, 0);
		make_rb(stack_b, stack_a, 0, 0);
	}
	if (c == 1)
	{
		ft_printf("rr\n");
		operation_push_back(block->oper, "rr") ;
	}
	block->debug == 1 ? ft_printf("rr\n") && print_stacks(*stack_a, *stack_b) : 0;
}
