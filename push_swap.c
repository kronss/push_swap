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
																int cnt)
{
	int i;

	i = linked_list_len(*stack_a);


	// printf("==================================================\n");
	// printf("=====================AAA ULTIMATE ================\n");
	// printf("==================================================\n");
	// printf("cnt %d\n", cnt);
	// printf("len list %d\n", i);
	if (i <= 3)
	{
		i == 3 ? frst_sort_3_a(stack_a, stack_b, block) : 0;
		i == 2 ? sort_2_elem_a(stack_a, stack_b, block) : 0;
		block->rra = 1;
	}
	else
	{
		cnt == 3 ? next_sort_3_a(stack_a, stack_b, block) : 0;
		cnt == 2 ? sort_2_elem_a(stack_a, stack_b, block) : 0;
	}
}

static void	sort_3_elem_b(t_stack **stack_a, t_stack **stack_b, t_block *block,
																int max_size)
{
	int i;

	i = linked_list_len(*stack_b);


	// printf("==================================================\n");
	// printf("=====================ULTIMATE BBB=================\n");
	// printf("==================================================\n");
	// printf("max_size %d\n", max_size);
	// printf("len list %d\n", i);
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


void		recn_a(t_stack **stack_a, t_stack **stack_b, t_block *block, int cnt)
{
	int		pivot;
	int		pushed_cnt;
	int		rotate_cnt;
	int		size;

	size = cnt;
	pushed_cnt = 0;
	rotate_cnt = 0;
	if (cnt <= 3)
		return (sort_3_elem_a(stack_a, stack_b, block, cnt));
	pivot = find_pivot(*stack_a, cnt);
	while (cnt > 0)
	{
		if (!rem_less_then_pivot(*stack_a, pivot, cnt))
			break;
		if ((*stack_a)->data < pivot && ++pushed_cnt)
			make_pb(stack_a, stack_b, 1, block);
		else
		{
			make_ra(stack_a, stack_b, 1, block);
			rotate_cnt++;
		}
		cnt--;
	}
	while (rotate_cnt-- && linked_list_len(*stack_a) != size - pushed_cnt)
		make_rra(stack_a, stack_b, 1, block);
	recn_a(stack_a, stack_b, block, size - pushed_cnt);
	recn_b(stack_a, stack_b, block, pushed_cnt);
	while (pushed_cnt--)
		make_pa(stack_a, stack_b, 1, block);
}


void		recn_b(t_stack **stack_a, t_stack **stack_b, t_block *block, int cnt)
{
	int		pivot;
	int		pushed_cnt;
	int		rotate_cnt;
	int		size;

	size = cnt;
	pushed_cnt = 0;
	rotate_cnt = 0;
	if (cnt <= 3)
		return (sort_3_elem_b(stack_a, stack_b, block, block->size_b));//TODO:re-code logic
	pivot = find_pivot(*stack_b, cnt);
	while (cnt > 0)
	{
		if (!rem_more_then_pivot(*stack_b, pivot, cnt))
			break;
		if ((*stack_b)->data >= pivot && ++pushed_cnt) // if ((*stack_b)->data > pivot)
			make_pa(stack_a, stack_b, 1, block);
		else
		{
			make_rb(stack_a, stack_b, 1, block);
			rotate_cnt++;	
		}
		cnt--;
	}
	recn_a(stack_a, stack_b, block, pushed_cnt);
	while (rotate_cnt-- && linked_list_len(*stack_b) != size - pushed_cnt)
		make_rrb(stack_a, stack_b, 1, block);
	recn_b(stack_a, stack_b, block, size - pushed_cnt);
	while (pushed_cnt--)
		make_pb(stack_a, stack_b, 1, block);
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
	if (is_sorted(stack_a))
		return (0);
	block.size_a = linked_list_len(stack_a);
	block.max_size > 1 ? recn_a(&stack_a, &stack_b, &block, block.size_a) : 0;
	block.file ? print_stacks(stack_a, stack_b) : 0;
	return (0);
}
