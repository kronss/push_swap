/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_sort_3_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 19:36:18 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/23 19:36:19 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_2_elem_a(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
	{
		make_sa(stack_a, stack_b, 1, block);
	}
}

static void	a_biger_then_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_a)->next->data < (*stack_a)->next->next->data)
	{
		if ((*stack_a)->data < (*stack_a)->next->next->data)
		{
			make_sa(stack_a, stack_b, 1, block);
		}
		else if ((*stack_a)->data > (*stack_a)->next->next->data)
		{
			make_sa(stack_a, stack_b, 1, block);
			make_ra(stack_a, stack_b, 1, block);
			make_sa(stack_a, stack_b, 1, block);
			make_rra(stack_a, stack_b, 1, block);
		}
	}
	else
	{
		make_sa(stack_a, stack_b, 1, block);
		make_ra(stack_a, stack_b, 1, block);
		make_sa(stack_a, stack_b, 1, block);
		make_rra(stack_a, stack_b, 1, block);
		make_sa(stack_a, stack_b, 1, block);
	}
}

static void	a_less_then_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		if ((*stack_a)->data < (*stack_a)->next->next->data)
		{
			make_ra(stack_a, stack_b, 1, block);
			make_sa(stack_a, stack_b, 1, block);
			make_rra(stack_a, stack_b, 1, block);
		}
		else if ((*stack_a)->data > (*stack_a)->next->next->data)
		{
			make_ra(stack_a, stack_b, 1, block);
			make_sa(stack_a, stack_b, 1, block);
			make_rra(stack_a, stack_b, 1, block);
			make_sa(stack_a, stack_b, 1, block);
		}
	}
}

void		next_sort_3_a(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_a)->data < (*stack_a)->next->data)
		a_less_then_b(stack_a, stack_b, block);
	else if ((*stack_a)->data > (*stack_a)->next->data)
		a_biger_then_b(stack_a, stack_b, block);
}
