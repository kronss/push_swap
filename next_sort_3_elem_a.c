/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_sort_3_elem_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 19:36:18 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/23 19:36:19 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			sort_2_elem_a(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
	{
		// ft_printf("===== 2 1 ==============================\n");
		check_ss(*stack_b, block) ? make_ss(stack_a, stack_b, 1) : make_sa(stack_a, 1);
	}
	// else
	// 	ft_printf("===== 1 2 ==============================\n");
}

void		next_sort_3_elem_a(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	// print_stacks(*stack_a, *stack_b); //bonus
	if ((*stack_a)->data < (*stack_a)->next->data) // a < b ====================
	{
		if ((*stack_a)->next->data > (*stack_a)->next->next->data) // b > c ====
		{
			if ((*stack_a)->data < (*stack_a)->next->next->data) // a < c
			{
				// ft_printf("===== 1 3 2 ==============================\n");
	

				!check_rr_or_rrr(*stack_b, block) ? make_rr(stack_a, stack_b, 1) : make_rra(stack_a, 1);
				check_ss(*stack_b, block) ? make_ss(stack_a, stack_b, 1) : make_sa(stack_a, 1);
				check_rr_or_rrr(*stack_b, block) ? make_rrr(stack_a, stack_b, 1) : make_rra(stack_a, 1);
				// print_stacks(*stack_a, *stack_b); //bonus	
			}
			else if ((*stack_a)->data > (*stack_a)->next->next->data) // a > c
			{
				// ft_printf("===== 2 3 1 ====================\n");

				
				!check_rr_or_rrr(*stack_b, block) ? make_rr(stack_a, stack_b, 1) : make_ra(stack_a, 1);				
				check_ss(*stack_b, block) ? make_ss(stack_a, stack_b, 1) : make_sa(stack_a, 1);
				check_rr_or_rrr(*stack_b, block) ? make_rrr(stack_a, stack_b, 1) : make_rra(stack_a, 1);
				check_ss(*stack_b, block) ? make_ss(stack_a, stack_b, 1) : make_sa(stack_a, 1);
			}
		}
		// else
			// ft_printf("===== 1 2 3 ==============================\n");
	}	
	else if ((*stack_a)->data > (*stack_a)->next->data) // a > b ===============
	{
		if ((*stack_a)->next->data < (*stack_a)->next->next->data)  // b < c ===
		{
			if ((*stack_a)->data < (*stack_a)->next->next->data) // a < c
			{
				// ft_printf("===== 2 1 3 ==============================\n");
			
				check_ss(*stack_b, block) ? make_ss(stack_a, stack_b, 1) : make_sa(stack_a, 1);
			}
			else if ((*stack_a)->data > (*stack_a)->next->next->data) // a > c
			{
				// ft_printf("===== 3 1 2 ==============================\n");

				check_ss(*stack_b, block) ? make_ss(stack_a, stack_b, 1) : make_sa(stack_a, 1);
				check_rr_or_rrr(*stack_b, block) ? make_rr(stack_a, stack_b, 1) : make_ra(stack_a, 1);
				check_ss(*stack_b, block) ? make_ss(stack_a, stack_b, 1) : make_sa(stack_a, 1);
				!check_rr_or_rrr(*stack_b, block) ? make_rrr(stack_a, stack_b, 1) : make_rra(stack_a, 1);
			}
		}
		else // b > c worst variant
		{
			// ft_printf("===== 3 2 1 =============== WORST ===============\n");
			check_ss(*stack_b, block) ? make_ss(stack_a, stack_b, 1) : make_sa(stack_a, 1);
			!check_rr_or_rrr(*stack_b, block) ? make_rr(stack_a, stack_b, 1) : make_ra(stack_a, 1);
			check_ss(*stack_b, block) ? make_ss(stack_a, stack_b, 1) : make_sa(stack_a, 1);
			check_rr_or_rrr(*stack_b, block) ? make_rrr(stack_a, stack_b, 1) : make_rra(stack_a, 1);
			check_ss(*stack_b, block) ? make_ss(stack_a, stack_b, 1) : make_sa(stack_a, 1);
		}
	}
	// block->size -= 3;
	// print_stacks(*stack_a, *stack_b); //bonus	
}


















