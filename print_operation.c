/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 12:48:18 by ochayche          #+#    #+#             */
/*   Updated: 2018/03/17 12:48:19 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		list_push_back_copy_a(t_stack **begin_list, int data)
{
	t_stack		*curr;

	curr = *begin_list;
	if (curr)
	{
		while (curr->next)
			curr = curr->next;
		curr->next = create_elem(data);
	}
	else
	{
		*begin_list = create_elem(data);
	}
}

void			create_dirty_copy_a(t_stack *tmp_a, t_block *block)
{
	while (tmp_a)
	{
		list_push_back_copy_a(&(block->copy_a), tmp_a->data);
		tmp_a = tmp_a->next;
	}
}

void			do_operation(t_stack **copy_a, t_stack **stack_b,
											t_block *block, char *operation)
{
	if (!ft_strcmp(operation, "pa"))
		make_pa(copy_a, stack_b, 0, block);
	else if (!ft_strcmp(operation, "pb"))
		make_pb(copy_a, stack_b, 0, block);
	else if (!ft_strcmp(operation, "ra"))
		make_ra(copy_a, stack_b, 0, block);
	else if (!ft_strcmp(operation, "rb"))
		make_rb(copy_a, stack_b, 0, block);
	else if (!ft_strcmp(operation, "rr"))
		make_rr(copy_a, stack_b, 0, block);
	else if (!ft_strcmp(operation, "sa"))
		make_sa(copy_a, stack_b, 0, block);
	else if (!ft_strcmp(operation, "sb"))
		make_sb(copy_a, stack_b, 0, block);
	else if (!ft_strcmp(operation, "ss"))
		make_ss(copy_a, stack_b, 0, block);
	else if (!ft_strcmp(operation, "rra"))
		make_rra(copy_a, stack_b, 0, block);
	else if (!ft_strcmp(operation, "rrb"))
		make_rrb(copy_a, stack_b, 0, block);
	else if (!ft_strcmp(operation, "rrr"))
		make_rrr(copy_a, stack_b, 0, block);
}

void			print_operation(t_stack **copy_a, t_stack **stack_b,
															t_block *block)
{
	t_oper	*curr;

	curr = block->oper;
	while (curr != NULL)
	{
		ft_printf("%s\n", curr->data);
		if (block->debug)
		{
			do_operation(copy_a, stack_b, block, curr->data);
			print_stacks(*copy_a, *stack_b);
		}
		curr = curr->next;
	}
}
