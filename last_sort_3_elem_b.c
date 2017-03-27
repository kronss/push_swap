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

void			sort_2_elem_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_b)->data < (*stack_b)->next->data)
		make_sb(stack_a, stack_b, 1, block);
}

void		last_sort_3_elem_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_b)->data > (*stack_b)->next->data) // a > b ====================
	{
		if ((*stack_b)->next->data < (*stack_b)->next->next->data) // b < c ====
		{
			if ((*stack_b)->data > (*stack_b)->next->next->data) // a < c
				make_rrb(stack_a, stack_b, 1, block);
			else if ((*stack_b)->data < (*stack_b)->next->next->data) // a < c
				make_rrb(stack_a, stack_b, 1, block);
		}
	}	
	else if ((*stack_b)->data < (*stack_b)->next->data) // a < b ===============
	{
		if ((*stack_b)->next->data > (*stack_b)->next->next->data)  // b > c ===
		{
			if ((*stack_b)->data > (*stack_b)->next->next->data) // a > c
				make_sb(stack_a, stack_b, 1, block);
			else if ((*stack_b)->data < (*stack_b)->next->next->data) // a < c
				make_rb(stack_a, stack_b, 1, block);
		}
		else // b < c worst variant
		{
			make_sb(stack_a, stack_b, 1, block);
			make_rrb(stack_a, stack_b, 1, block);
		}
	}
}














