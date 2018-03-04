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

static void	sort_3_elem_a(t_stack **stack_a, t_stack **stack_b, t_block *block,
																int max_size)
{
	int i;

	i = linked_list_len(*stack_a);
	if (i <= 3)
	{
		i == 3 ? frst_sort_3_a(stack_a, stack_b, block) : 0;
		i == 2 ? sort_2_elem_a(stack_a, stack_b, block) : 0;
		block->rra = 1;
	}
	else
	{
		max_size == 3 ? next_sort_3_a(stack_a, stack_b, block) : 0;
		max_size == 2 ? sort_2_elem_a(stack_a, stack_b, block) : 0;
	}
}

static void	sort_3_elem_b(t_stack **stack_a, t_stack **stack_b, t_block *block,
																int max_size)
{
	int i;

	i = linked_list_len(*stack_b);


	printf("==================================================\n");
	printf("=====================ULTIMATE BBB=================\n");
	printf("==================================================\n");
	printf("max_size %d\n", max_size);
	printf("len list %d\n", i);
	// printf("%s\n", max_size);


	if (i <= 3)
	{
		i == 3 ? last_sort_3_b(stack_a, stack_b, block) : 0;
		i == 2 ? sort_2_elem_b(stack_a, stack_b, block) : 0;
		i == 1 ? 	make_pa(stack_a, stack_b, 1, block) : 0;
		block->rra = 0;
	}
	else
	{
		max_size == 3 ? next_sort_3_b(stack_a, stack_b, block) : 0;
		max_size == 2 ? sort_2_elem_b(stack_a, stack_b, block) : 0;
		max_size == 1 ? make_pa(stack_a, stack_b, 1, block) : 0;
	}
}

void		recn_a(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	t_block next_block;
	int		pivot;

	printf("AAA block->size_a  %d\n", block->size_a);
	printf("AAA block->size_b  %d\n", block->size_b);

	if (block->size_a <= 3)
		return (sort_3_elem_a(stack_a, stack_b, block, block->size_a));
	// printf("pushed_a == %d\n", pushed_a);
	pivot = find_pivot(*stack_a, block->size_a);
	
	init_tmp_var(block, &next_block);
	while (block->size_a > 0)
	{
		printf("(*stack_a)->data %d\n", (*stack_a)->data);
		printf("pivot %d\n", pivot);


		if ((*stack_a)->data < pivot)
		{
			make_pb(stack_a, stack_b, 1, block);
			next_block.size_b ++;
			block->size_b ++ ;
		}
		else
		{
			make_ra(stack_a, stack_b, 1, block);
			next_block.size_a ++;
		}

		block->size_a -- ;
	printf("pivot == %d\n", pivot);
	printf("--A block->size_a  %d\n", block->size_a);
	printf("--A block->size_b  %d\n", block->size_b);

	}

	block->size_a ++;

printf("----------------------------------\n");

	recn_a(stack_a, stack_b, &next_block);

//if else

	recn_b(stack_a, stack_b, &next_block);

	// if (block->rra == 1)
	// 	backtrack_stack_a(stack_a, stack_b, block, rra);

	// recn_a(stack_a, stack_b, block);
	// recn_b(stack_a, stack_b, block);
	// while (push_b--)
	// 	make_pa(stack_a, stack_b, 1, block);
}

void		recn_b(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	t_block next_block;
	int		pivot;

	printf("BBB block->size_a  %d\n", block->size_a);
	printf("BBB block->size_b  %d\n", block->size_b);


	if (block->size_b <= 3)
		return (sort_3_elem_b(stack_a, stack_b, block, block->size_b));

	pivot = find_pivot(*stack_b, block->size_b);

	init_tmp_var(block, &next_block);
	while (block->size_b > 0)
	{
		if ((*stack_b)->data >= pivot)
		{
			make_pa(stack_a, stack_b, 1, block);
			next_block.size_a ++;
		}
		else
		{
			make_rb(stack_a, stack_b, 1, block);
			next_block.size_b ++;	
		}

		block->size_b --;
	}

		block->size_b ++;

	recn_a(stack_a, stack_b, &next_block);
	// if (block->rra == 1)
	// 	backtrack_stack_b(stack_a, stack_b, block, rrb);
	recn_b(stack_a, stack_b, &next_block);
	// while (push_a--)
	// 	make_pb(stack_a, stack_b, 1, block);
}

int			main(int ar, char **av)
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
	if (is_a_sorted(stack_a))
		return (0);
	block.size_a = linked_list_len(stack_a);
	block.max_size > 1 ? recn_a(&stack_a, &stack_b, &block) : 0;
	block.file ? print_stacks(stack_a, stack_b) : 0;
	return (0);
}
