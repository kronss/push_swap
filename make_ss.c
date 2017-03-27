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

void						make_pb(t_stack **stack_a, t_stack **stack_b, char c, t_block *block)
{
	t_stack *tmp;

	if (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = (*stack_b);
		*stack_b = tmp;
	}
	if (c == 1)
	{
		block->debug == 1 ? 0 : ft_printf("pb\n");
		operation_push_back(block->oper, "pb");
	}
	block->debug == 1 ? ft_printf("pb\n") && print_stacks(*stack_a, *stack_b) : 0;
}

void						make_pa(t_stack **stack_a, t_stack **stack_b, char c, t_block *block)
{
	t_stack *tmp;

	if (*stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = (*stack_a);
		*stack_a = tmp;
	}
	if (c == 1)
	{
		block->debug == 1 ? 0 : ft_printf("pa\n");
		operation_push_back(block->oper, "pa");
	}
	block->debug == 1 ? ft_printf("pa\n") && print_stacks(*stack_a, *stack_b) : 0;
}

void			make_sa(t_stack **stack_a, t_stack **stack_b, char c, t_block *block)
{
	t_stack		*frst;
	t_stack		*scnd;

	frst = (*stack_a) ;
	if (frst && frst->next)
	{
		scnd = frst->next;
		frst->next = scnd->next;
		scnd->next = frst;
		(*stack_a)  = scnd;
	}
	if (c == 1)
	{
		block->debug == 1 ? 0 : ft_printf("sa\n");
		operation_push_back(block->oper, "sa");
	}
	block->debug == 1 ? ft_printf("sa\n") && print_stacks(*stack_a, *stack_b) : 0;
}

void			make_sb(t_stack **stack_a, t_stack **stack_b, char c, t_block *block)
{
	t_stack		*frst;
	t_stack		*scnd;

	frst = (*stack_b);
	if (frst && frst->next)
	{
		scnd = frst->next;
		frst->next = scnd->next;
		scnd->next = frst;
		(*stack_b) = scnd;
	}
	if (c == 1)
	{
	block->debug == 1 ? 0 : ft_printf("sb\n");
	operation_push_back(block->oper, "sb");
	}
	block->debug == 1 ? ft_printf("sb\n") && print_stacks(*stack_a, *stack_b) : 0;
}

void			make_ss(t_stack **stack_a, t_stack **stack_b, char c, t_block *block)
{
	if (block->debug == 1)
	{
		block->debug = 0;	
		make_sa(stack_a, stack_b, 0, block);
		make_sb(stack_a, stack_b, 0, block);
		block->debug = 1;
	}
	else
	{
		make_sa(stack_a, stack_b, 0, block);
		make_sb(stack_a, stack_b, 0, block);
	}
	if (c == 1)
	{
	block->debug == 1 ? 0 : ft_printf("ss\n");
	operation_push_back(block->oper, "ss");
	}
	block->debug == 1 ? ft_printf("ss\n") && print_stacks(*stack_a, *stack_b) : 0;
}







