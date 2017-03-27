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



void		next_sort_3_elem_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	// print_stacks(*stack_a, *stack_b); //bonus
	if ((*stack_b)->data > (*stack_b)->next->data) // a > b ====================
	{
		if ((*stack_b)->next->data < (*stack_b)->next->next->data) // b < c ====
		{
			if ((*stack_b)->data < (*stack_b)->next->next->data) // a < c
			{
				// ft_printf("BBBB= 3 1 2 ==============================\n");
				//!check_rr_or_rrr(*stack_a, block) ? make_rr(stack_a, stack_b, 1) : 
				make_rb(stack_b, 1);
				// !check_ss(*stack_a, block) ? make_ss(stack_a, stack_b, 1) :
				make_sb(stack_b, 1);
				//check_rr_or_rrr(*stack_b, block) ? make_rrr(stack_a, stack_b, 1) : 
				make_rrb(stack_b, 1);
				// print_stacks(*stack_a, *stack_b); //bonus	
			}



			else if ((*stack_b)->data < (*stack_b)->next->next->data) // a < c
			{
				// ft_printf("BBBB === 2 1 3 ====================\n");

				
				// !check_rr_or_rrr(*stack_b, block) ? make_rr(stack_a, stack_b, 1) : 
				make_rb(stack_b, 1);				
				// !check_ss(*stack_a, block) ? make_ss(stack_a, stack_b, 1) : 
				make_sb(stack_b, 1);
				//check_rr_or_rrr(*stack_b, block) ? make_rrr(stack_a, stack_b, 1) : 
				make_rrb(stack_b, 1);
				// !check_ss(*stack_a, block) ? make_ss(stack_a, stack_b, 1) : 
				make_sb(stack_b, 1);
			}
		}
		// else
			// ft_printf("BBB== 3 2 1 ==============================\n");
	}	
	else if ((*stack_b)->data < (*stack_b)->next->data) // a < b ===============
	{

		if ((*stack_b)->next->data > (*stack_b)->next->next->data)  // b > c ===
		{
			if ((*stack_b)->data > (*stack_b)->next->next->data) // a > c
			{
				// ft_printf("BBB=== 2 3 1 ==============================\n");
			
				// !check_ss(*stack_a, block) ? make_ss(stack_a, stack_b, 1) : 
				make_sb(stack_b, 1);
			}



			else if ((*stack_b)->data < (*stack_b)->next->next->data) // a < c
			{
				// ft_printf("BBB== 1 3 2 ==============================\n");

				// !check_ss(*stack_a, block) ? make_ss(stack_a, stack_b, 1) : 
				make_sb(stack_b, 1);
				//check_rr_or_rrr(*stack_b, block) ? make_rr(stack_a, stack_b, 1) : 
				make_rb(stack_b, 1);
				// !check_ss(*stack_a, block) ? make_ss(stack_a, stack_b, 1) : 
				make_sb(stack_b, 1);
				//!check_rr_or_rrr(*stack_b, block) ? make_rrr(stack_a, stack_b, 1) : 
				make_rrb(stack_b, 1);
			}
		}
		else // b < c worst variant
		{
			// ft_printf("BBBB= 1 2 3 =============== WORST ===============\n");
			
			// !check_ss(*stack_a, block) ? make_ss(stack_a, stack_b, 1) : 
			make_sb(stack_b, 1);
			// !check_rr_or_rrr(*stack_b, block) ? make_rr(stack_a, stack_b, 1) : 
			make_rb(stack_b, 1);
			// !check_ss(*stack_a, block) ? make_ss(stack_a, stack_b, 1) : 
			make_sb(stack_b, 1);
			//check_rr_or_rrr(*stack_b, block) ? make_rrr(stack_a, stack_b, 1) : 
			make_rrb(stack_b, 1);
			// !check_ss(*stack_a, block) ? make_ss(stack_a, stack_b, 1) : 
			make_sb(stack_b, 1);
		}
	}
	// block->size -= 3;
	// print_stacks(*stack_a, *stack_b); //bonus	
}


















