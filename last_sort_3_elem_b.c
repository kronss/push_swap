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
	{
		// ft_printf("BBBB == 1 2 ==================last============\n");
		// check ss??

		// !check_ss(*stack_a, block) ? make_ss(stack_a, stack_b, 1) : 
		make_sb(stack_b, 1);
	}
	// else
		// ft_printf("BBBB == 2 1 ====================last==========\n");
}

void		last_sort_3_elem_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	// print_stacks(*stack_a, *stack_b); //bonus
	if ((*stack_b)->data > (*stack_b)->next->data) // a > b ====================
	{
		if ((*stack_b)->next->data < (*stack_b)->next->next->data) // b < c ====
		{
			if ((*stack_b)->data > (*stack_b)->next->next->data) // a < c
			{
				// ft_printf("BBBB= 3 1 2 ====================last==========\n");
				make_rrb(stack_b, 1);
				// !check_ss(*stack_a, block) ? make_ss(stack_a, stack_b, 1) : 
				// make_sb(stack_b, 1);
				//check_rr_or_rrr(*stack_b, block) ? make_rrr(stack_a, stack_b, 1) : 
			}
			else if ((*stack_b)->data < (*stack_b)->next->next->data) // a < c
			{
				// ft_printf("BBBB === 2 1 3 ============last========\n");
				make_rrb(stack_b, 1);
			}
		}
		// else
			// ft_printf("BBB== 3 2 1 ====================last==========\n");
	}	
	else if ((*stack_b)->data < (*stack_b)->next->data) // a < b ===============
	{

		if ((*stack_b)->next->data > (*stack_b)->next->next->data)  // b > c ===
		{
			if ((*stack_b)->data > (*stack_b)->next->next->data) // a > c
			{
				// ft_printf("BBB=== 2 3 1 ====================last==========\n");
				// !check_ss(*stack_a, block) ? make_ss(stack_a, stack_b, 1) : 
				make_sb(stack_b, 1);
			}
			else if ((*stack_b)->data < (*stack_b)->next->next->data) // a < c
			{
				// ft_printf("BBB== 1 3 2 ====================last==========\n");
				make_rb(stack_b, 1);
			}
		}
		else // b < c worst variant
		{
			// ft_printf("BBBB= 1 2 3 =============== WORST =======last========\n");
			
			//!check_ss(*stack_a, block) ? make_ss(stack_a, stack_b, 1) : 
			make_sb(stack_b, 1);
			make_rrb(stack_b, 1);
		}
	}
}














