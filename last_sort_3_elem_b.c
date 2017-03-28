/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_sort_3_elem_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 22:32:41 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/26 22:32:42 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_a_ss(t_stack *stack_a)
{
	if (stack_a && stack_a->next)
	{
		if (stack_a->data > stack_a->next->data)
			return (1);
	}
	return (0);
}

void			sort_2_elem_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_b)->data < (*stack_b)->next->data)
	{	
		// check_a_ss(*stack_a) ? make_ss(stack_a, stack_b, 1, block) : 
		make_sb(stack_a, stack_b, 1, block);
	}
}

static void a_biger_then_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_b)->next->data < (*stack_b)->next->next->data) // b < c ====
	{
		if ((*stack_b)->data > (*stack_b)->next->next->data) // a > c
		{
			make_rrb(stack_a, stack_b, 1, block);
			// check_a_ss(*stack_a) ? make_ss(stack_a, stack_b, 1, block) : 
			make_sb(stack_a, stack_b, 1, block);
		}
		else if ((*stack_b)->data < (*stack_b)->next->next->data) // a < c
			make_rrb(stack_a, stack_b, 1, block);
	}
}

static void a_less_then_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_b)->next->data > (*stack_b)->next->next->data)  // b > c ===
	{
		if ((*stack_b)->data > (*stack_b)->next->next->data) // a > c
		{
			// check_a_ss(*stack_a) ? make_ss(stack_a, stack_b, 1, block) : 
			make_sb(stack_a, stack_b, 1, block);
		}
		else if ((*stack_b)->data < (*stack_b)->next->next->data) // a < c
			make_rb(stack_a, stack_b, 1, block);
	}
	else // b < c worst variant
	{
		// check_a_ss(*stack_a) ? make_ss(stack_a, stack_b, 1, block) : 
		make_sb(stack_a, stack_b, 1, block);
		make_rrb(stack_a, stack_b, 1, block);
	}
}


void		last_sort_3_elem_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_b)->data > (*stack_b)->next->data) // a > b ====================
		 a_biger_then_b(stack_a, stack_b, block);
	else if ((*stack_b)->data < (*stack_b)->next->data) // a < b ===============
		a_less_then_b(stack_a, stack_b, block);
}














