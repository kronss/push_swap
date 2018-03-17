/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_logic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 12:46:23 by ochayche          #+#    #+#             */
/*   Updated: 2018/03/17 12:46:25 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	frst_sort_3_elem_a(t_stack **stack_a, t_stack **stack_b,
										t_block *block, int max_size)
{
	if (max_size == 1)
		return ;
	else if (max_size == 2)
		sort_2_elem_a(stack_a, stack_b, block);
	else
		frst_sort_3_a(stack_a, stack_b, block);
}

void		sort_3_elem_a(t_stack **stack_a, t_stack **stack_b,
										t_block *block, int max_size)
{
	int		i;

	i = linked_list_len(*stack_a);
	if (i <= 3)
		return (frst_sort_3_elem_a(stack_a, stack_b, block, i));
	if (max_size == 1)
		return ;
	else if (max_size == 2)
	{
		sort_2_elem_a(stack_a, stack_b, block);
	}
	else
	{
		next_sort_3_a(stack_a, stack_b, block);
	}
}

static void	last_sort_3_elem_b(t_stack **stack_a, t_stack **stack_b,
										t_block *block, int max_size)
{
	if (max_size == 1)
		return ;
	else if (max_size == 2)
		sort_2_elem_b(stack_a, stack_b, block);
	else
		last_sort_3_b(stack_a, stack_b, block);
}

void		sort_3_elem_b(t_stack **stack_a, t_stack **stack_b,
										t_block *block, int max_size)
{
	int		i;

	i = linked_list_len(*stack_b);
	if (i <= 3)
		return (last_sort_3_elem_b(stack_a, stack_b, block, i));
	if (max_size == 1)
		return ;
	else if (max_size == 2)
	{
		sort_2_elem_b(stack_a, stack_b, block);
	}
	else
	{
		next_sort_3_b(stack_a, stack_b, block);
	}
}
