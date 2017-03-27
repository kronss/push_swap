/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:55:02 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/16 17:55:02 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_3_elem_a(t_stack **stack_a, t_stack **stack_b, t_block *block, int max_size)
{
	int i;

	i = linked_list_len(*stack_a);
	if (i <= 3)
	{
		i == 3 ? frst_sort_3_elem_a(stack_a, stack_b, block) : 0;
		i == 2 ? sort_2_elem_a(stack_a, stack_b, block) : 0;
		block->rra = 1;
	}
	else
	{
		max_size == 3 ? next_sort_3_elem_a(stack_a, stack_b, block) : 0;
		max_size == 2 ? sort_2_elem_a(stack_a, stack_b, block) : 0;
	}
}

static void			sort_3_elem_b(t_stack **stack_a, t_stack **stack_b, t_block *block, int max_size)
{
	int i;
	
	i = linked_list_len(*stack_b);
	if (i <= 3)
	{
		i == 3 ? last_sort_3_elem_b(stack_a, stack_b, block) : 0;
		i == 2 ? sort_2_elem_b(stack_a, stack_b, block) : 0;
		// block->rra = 0;
	}
	else
	{
		max_size == 3 ? next_sort_3_elem_b(stack_a, stack_b, block) : 0;
		max_size == 2 ? sort_2_elem_b(stack_a, stack_b, block) : 0;
	}
}

void			recursion_a(t_stack **stack_a, t_stack **stack_b, t_block *block, int max_size)
{
	int push_b;
	int rra;

	push_b = 0;
	rra = 0;
	if (max_size <= 3)
		return (sort_3_elem_a(stack_a, stack_b, block, max_size));
	block->pivot_i = find_pivot(*stack_a, max_size);
	while (find_rem_a(*stack_a, block->pivot_i))
	{
		if ((*stack_a)->data <= block->pivot_i && ++push_b)
			make_pb(stack_a, stack_b, 1, block);
		else
		{
			make_ra(stack_a, stack_b, 1, block);
			block->rra ? rra++ : 0;
		}
	}
	while (block->rra && rra--)
		make_rra(stack_a, stack_b, 1, block);
	recursion_a(stack_a, stack_b, block, max_size - push_b);
	recursion_b(stack_a, stack_b, block, push_b);
	while (push_b--)
		make_pa(stack_a, stack_b, 1, block);
}

void 			recursion_b(t_stack **stack_a, t_stack **stack_b, t_block *block, int push_b)
{
	int push_a;
	int rrb;
	int len;

	if (push_b <= 3)
		return (sort_3_elem_b(stack_a, stack_b, block, push_b));
	len = push_b;
	push_a = 0;
	rrb = 0;
	block->pivot_i = find_pivot(*stack_b, push_b);
	while (find_rem_b(*stack_b, block->pivot_i))
	{
		if ((*stack_b)->data > block->pivot_i && ++push_a)
			make_pa(stack_a, stack_b, 1, block);
		else
		{
			make_rb(stack_a, stack_b, 1, block);
			rrb++;
		}
	}
	recursion_a(stack_a, stack_b, block, push_b);
	while (rrb--)
		make_rrb(stack_a, stack_b, 1, block);
	recursion_b(stack_a, stack_b, block, len - push_a);
	while (push_a--)
		make_pb(stack_a, stack_b, 1, block);
}	

int								main(int ar, char **av)
{
	t_block			block;
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				i;

	init_var(&block, &stack_a, &stack_b);
	i = read_flags(&block, av, ar);
	while (i < ar)
	{
		list_push_back(&stack_a, ft_atol(av[i]), av[i]);
		i++;
	}
	pre_validate(stack_a, &block);
	/*=====================================================*/

	block.max_size > 1 ? recursion_a(&stack_a, &stack_b, &block, block.max_size) : 0;
	block.debug ? print_stacks(stack_a, stack_b) : 0; //bonus
	// print_stacks(stack_a, stack_b);
	return (0);
}
