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

void	make_rra(t_stack **stack_a, t_stack **stack_b, char c, t_block *block)
{
	t_stack		*tmp;
	t_stack		*will_be_head;

	(void)stack_b;
	if ((*stack_a) && (*stack_a)->next)
	{
		tmp = *stack_a;
		while (tmp->next->next)
			tmp = tmp->next;
		will_be_head = tmp->next;
		will_be_head->next = (*stack_a);
		(*stack_a) = will_be_head;
		tmp->next = NULL;
	}
	if (c == 1)
	{
		operation_push_back(&block->oper, "rra");
	}
	if (block->debug && block->program == CHECKER)
		print_stacks(*stack_a, *stack_b);
}

void	make_rrb(t_stack **stack_a, t_stack **stack_b, char c, t_block *block)
{
	t_stack		*tmp;
	t_stack		*will_be_head;

	(void)stack_a;
	if ((*stack_b) && (*stack_b)->next)
	{
		tmp = *stack_b;
		while (tmp->next->next)
			tmp = tmp->next;
		will_be_head = tmp->next;
		will_be_head->next = (*stack_b);
		(*stack_b) = will_be_head;
		tmp->next = NULL;
	}
	if (c == 1)
	{
		operation_push_back(&block->oper, "rrb");
	}
	if (block->debug && block->program == CHECKER)
		print_stacks(*stack_a, *stack_b);
}

void	make_rrr(t_stack **stack_a, t_stack **stack_b, char c, t_block *block)
{
	if (block->debug == 1)
	{
		block->debug = 0;
		make_rra(stack_a, stack_b, 0, block);
		make_rrb(stack_a, stack_b, 0, block);
		block->debug = 1;
	}
	else
	{
		make_rra(stack_a, stack_b, 0, block);
		make_rrb(stack_a, stack_b, 0, block);
	}
	if (c == 1)
	{
		operation_push_back(&block->oper, "rrr");
	}
	if (block->debug && block->program == CHECKER)
		print_stacks(*stack_a, *stack_b);
}
