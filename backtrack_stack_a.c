/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:21:50 by ochayche          #+#    #+#             */
/*   Updated: 2017/04/19 12:21:50 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//UNUSED?

#include "push_swap.h"

void		backtrack_stack_a(t_stack **stack_a, t_stack **stack_b,
t_block *block, int rra)
{
	if (rra > linked_list_len(*stack_a) / 2)
		while (linked_list_len(*stack_a) - rra++ > 0)
			make_ra(stack_a, stack_b, 1, block);
	else
		while (rra--)
			make_rra(stack_a, stack_b, 1, block);
}

void		backtrack_stack_b(t_stack **stack_a, t_stack **stack_b,
										t_block *block, int rrb)
{
	if (rrb > linked_list_len(*stack_b) / 2)
		while (linked_list_len(*stack_b) - rrb++ > 0)
			make_rb(stack_a, stack_b, 1, block);
	else
		while (rrb--)
			make_rrb(stack_a, stack_b, 1, block);
}
