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


void		recn_a(t_stack **stack_a, t_stack **stack_b, t_block *block, int cnt)
{
	int		pushed_cnt;
	int		pivot;
	int		size;
	int		rotate_cnt;

	pushed_cnt = 0;
	size = cnt;
	rotate_cnt = 0;
	if (cnt <= 3)
		return (sort_3_elem_a(stack_a, stack_b, block, cnt));
	pivot = find_pivot(*stack_a, cnt);
	// printf("A: pivot %d\n", pivot);
	while (cnt >= 0)
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
	int		pushed_cnt;
	int		pivot;
	int		size;
	int		rotate_cnt;

	pushed_cnt = 0;
	size = cnt;
	rotate_cnt = 0;
	if (cnt <= 3)
		return (sort_3_elem_b(stack_a, stack_b, block, cnt));//TODO:re-code logic
	pivot = find_pivot(*stack_b, cnt);
	// printf("B: pivot %d\n", pivot);
	while (cnt >= 0)
	{
		if (!rem_more_then_pivot(*stack_b, pivot, cnt))
			break;
		if ((*stack_b)->data > pivot && ++pushed_cnt) // if ((*stack_b)->data > pivot)
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
	create_dirty_copy_a(stack_a, &block);
	block.size_a = linked_list_len(stack_a);
	block.max_size > 1 ? recn_a(&stack_a, &stack_b, &block, block.size_a) : 0;
//	print_operation(&block.copy_a, &stack_b, &block);





	print_operation(&block.copy_a, &stack_b, &block);


	return (0);
}
