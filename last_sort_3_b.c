/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_sort_3_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 22:32:41 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/26 22:32:42 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_2_elem_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_b)->data < (*stack_b)->next->data)
	{
		make_sb(stack_a, stack_b, 1, block);
	}
	// make_pa(stack_a, stack_b, 1, block);
	// make_pa(stack_a, stack_b, 1, block);
}

static void	a_biger_then_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_b)->next->data < (*stack_b)->next->next->data)
	{
		if ((*stack_b)->data > (*stack_b)->next->next->data)
		{
			make_rrb(stack_a, stack_b, 1, block);
			make_sb(stack_a, stack_b, 1, block);
		}
		else if ((*stack_b)->data < (*stack_b)->next->next->data)
			make_rrb(stack_a, stack_b, 1, block);
	}
}

static void	a_less_then_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_b)->next->data > (*stack_b)->next->next->data)
	{
		if ((*stack_b)->data > (*stack_b)->next->next->data)
		{
			make_sb(stack_a, stack_b, 1, block);
		}
		else if ((*stack_b)->data < (*stack_b)->next->next->data)
			make_rb(stack_a, stack_b, 1, block);
	}
	else
	{
		make_sb(stack_a, stack_b, 1, block);
		make_rrb(stack_a, stack_b, 1, block);
	}
}

void		last_sort_3_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_b)->data > (*stack_b)->next->data)
		a_biger_then_b(stack_a, stack_b, block);
	else if ((*stack_b)->data < (*stack_b)->next->data)
		a_less_then_b(stack_a, stack_b, block);

	// make_pa(stack_a, stack_b, 1, block);
	// make_pa(stack_a, stack_b, 1, block);
	// make_pa(stack_a, stack_b, 1, block);
}
