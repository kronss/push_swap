/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_sort_3_elem_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 21:46:13 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/26 21:46:14 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 		a_bigger_then_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_b)->next->data < (*stack_b)->next->next->data) // b < c ====
	{
		if ((*stack_b)->data < (*stack_b)->next->next->data) // a < c
		{
			make_rb(stack_a, stack_b, 1, block);
			make_sb(stack_a, stack_b, 1, block);
			make_rrb(stack_a, stack_b, 1, block);
		}
		else if ((*stack_b)->data < (*stack_b)->next->next->data) // a < c
		{
			make_rb(stack_a, stack_b, 1, block);				
			make_sb(stack_a, stack_b, 1, block);
			make_rrb(stack_a, stack_b, 1, block);
			make_sb(stack_a, stack_b, 1, block);
		}
	}
}

void 		a_less_then_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_b)->next->data > (*stack_b)->next->next->data)  // b > c ===
	{
		if ((*stack_b)->data > (*stack_b)->next->next->data) // a > c
			make_sb(stack_a, stack_b, 1, block);
		else if ((*stack_b)->data < (*stack_b)->next->next->data) // a < c
		{
			make_sb(stack_a, stack_b, 1, block);
			make_rb(stack_a, stack_b, 1, block);
			make_sb(stack_a, stack_b, 1, block);
			make_rrb(stack_a, stack_b, 1, block);
		}
	}
	else // b < c worst variant
	{
		make_sb(stack_a, stack_b, 1, block);
		make_rb(stack_a, stack_b, 1, block);
		make_sb(stack_a, stack_b, 1, block);
		make_rrb(stack_a, stack_b, 1, block);
		make_sb(stack_a, stack_b, 1, block);
	}
}


void		next_sort_3_elem_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_b)->data > (*stack_b)->next->data) // a > b ====================
		a_bigger_then_b(stack_a, stack_b, block);
	else if ((*stack_b)->data < (*stack_b)->next->data) // a < b ===============
		a_less_then_b(stack_a, stack_b, block);
}


















