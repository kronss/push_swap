/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_sort_3_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 21:46:13 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/26 21:46:14 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_bigger_then_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_b)->next->data < (*stack_b)->next->next->data)
	{
		if ((*stack_b)->data < (*stack_b)->next->next->data)
		{
			make_rb(stack_a, stack_b, 1, block);
			make_sb(stack_a, stack_b, 1, block);
			make_rrb(stack_a, stack_b, 1, block);
		}
		else if ((*stack_b)->data < (*stack_b)->next->next->data)
		{
			make_rb(stack_a, stack_b, 1, block);
			make_sb(stack_a, stack_b, 1, block);
			make_rrb(stack_a, stack_b, 1, block);
			make_sb(stack_a, stack_b, 1, block);
		}
	}
}

void	a_less_then_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_b)->next->data > (*stack_b)->next->next->data)
	{
		if ((*stack_b)->data > (*stack_b)->next->next->data)
		{
			make_sb(stack_a, stack_b, 1, block);
		}
		else if ((*stack_b)->data < (*stack_b)->next->next->data)
		{
			make_sb(stack_a, stack_b, 1, block);
			make_rb(stack_a, stack_b, 1, block);
			make_sb(stack_a, stack_b, 1, block);
			make_rrb(stack_a, stack_b, 1, block);
		}
	}
	else
	{
		make_sb(stack_a, stack_b, 1, block);
		make_rb(stack_a, stack_b, 1, block);
		make_sb(stack_a, stack_b, 1, block);
		make_rrb(stack_a, stack_b, 1, block);
		make_sb(stack_a, stack_b, 1, block);
	}
}

void	next_sort_3_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_b)->data > (*stack_b)->next->data)
		a_bigger_then_b(stack_a, stack_b, block);
	else if ((*stack_b)->data < (*stack_b)->next->data)
		a_less_then_b(stack_a, stack_b, block);

		// make_pa(stack_a, stack_b, 1, block);
	// make_pa(stack_a, stack_b, 1, block);
	// make_pa(stack_a, stack_b, 1, block);
}
