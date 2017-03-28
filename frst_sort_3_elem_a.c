/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frst_sort_3_elem_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:12:14 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/22 21:12:15 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_b_ss(t_stack *stack_b)
{
	if (stack_b && stack_b->next)
	{
		if (stack_b->data < stack_b->next->data)
			return (1);
	}
	return (0);
}

static void a_biger_then_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_a)->next->data < (*stack_a)->next->next->data)  // b < c ===
	{
		if ((*stack_a)->data < (*stack_a)->next->next->data) // a < c
		{
			// check_b_ss(*stack_b) ? make_ss(stack_a, stack_b, 1, block) : 
			make_sa(stack_a, stack_b, 1, block);
		}
		else if ((*stack_a)->data > (*stack_a)->next->next->data) // a > c
			make_ra(stack_a, stack_b, 1, block);
	}
	else // b > c worst variant
	{
		// check_b_ss(*stack_b) ? make_ss(stack_a, stack_b, 1, block) : 
		make_sa(stack_a, stack_b, 1, block);
		make_rra(stack_a, stack_b, 1, block);
	}
}

static void a_less_then_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_a)->next->data > (*stack_a)->next->next->data) // b > c ====
	{
		if ((*stack_a)->data < (*stack_a)->next->next->data) // a < c
		{
			make_rra(stack_a, stack_b, 1, block);
			// check_b_ss(*stack_b) ? make_ss(stack_a, stack_b, 1, block) : 
			make_sa(stack_a, stack_b, 1, block);
		}
		else if ((*stack_a)->data > (*stack_a)->next->next->data) // a > c
			make_rra(stack_a, stack_b, 1, block);
	}
}

void		frst_sort_3_elem_a(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_a)->data < (*stack_a)->next->data) // a < b ====================
		a_less_then_b(stack_a, stack_b, block);
	else if ((*stack_a)->data > (*stack_a)->next->data) // a > b ===============
		a_biger_then_b(stack_a, stack_b, block);
}
