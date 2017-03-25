/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_from_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 19:53:17 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/25 19:53:18 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char			find_rem_a(t_stack *stack_a, int pivot)
{
	while (stack_a)
	{
		if (pivot > stack_a->data)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int		hip_size(t_stack *stack_a)
{
	int i;

	int pivot = stack_a->p;
	i = 0;
	while (stack_a)
	{
		if (pivot == stack_a->p)
			i++;
		else
			break;
		stack_a = stack_a->next;
	}
	return (i);
}

void			push_from_a(t_stack **stack_a, t_stack **stack_b, int *arr, t_block *block)
{
	if (block->curr_size_a <= 3)
	{
		block->curr_size_a == 3 ? frst_sort_3_elem(stack_a, stack_b, block) : 0;
		block->curr_size_a == 2 ? sort_2_elem(stack_a, stack_b, block) : 0;
		// block->curr_size_a == 1 ? ft_printf(" ===== 1 ================================\n") : 0;
	}
	else
	{
		printf("hipp_size======%d==\n",hip_size(*stack_a));
		hip_size(*stack_a) == 3 ? next_sort_3_elem(stack_a, stack_b, block) : 0;
		hip_size(*stack_a) == 2 ? sort_2_elem(stack_a, stack_b, block) : 0;
		// hip_size(*stack_a) == 1 ? 
	}

	block->pivot_i = find_pivot(arr, block->pivot_i, (*stack_a)->p);
	//print_stacks(*stack_a, *stack_b); //sleep(1);
	// 	for (int j = 0; j < block->max_size; ++j)
	// {
	// 	printf("arr[%u] == [%u]\n", j, (arr[j]));
	// }
	printf("pivot\nindex %d\nvalue %d\n", block->pivot_i, arr[block->pivot_i]); sleep(5);
	// sleep(5);
	if (check_stack_a(*stack_a))
		return ;
	while (find_rem_a(*stack_a, arr[block->pivot_i]))   // check (elem);
	{
		if (check_stack_a(*stack_a))
			return ;
		// printf("arr[%d] > data[%d]\n", arr[block->pivot_i], (*stack_a)->data);
		// printf("pivot_ind %d\n", block->pivot_i);
		if ((*stack_a)->data < arr[block->pivot_i])
		{
			(*stack_a)->p = block->pivot_i;
			// printf("============%d\n", (*stack_a)->p);
			make_pb(stack_a, stack_b, 1);
			print_stacks(*stack_a, *stack_b);
			(block->curr_size_a)--;
			(block->curr_size_b)++;
			// if (block->curr_size_b % 2 == 0)
		}
		// if (check_ab_ss(*stack_a, *stack_b, block))// ? make_ss(stack_a, stack_b, 1) : 0;  //DELL??????
		// {
		// 	make_ss(stack_a, stack_b, 1);
		// 	// print_stacks(*stack_a, *stack_b);
		// }
		// if (find_way_ra_rra(*stack_a, block, arr[block->pivot_i]))
		// {
		// 	make_ra(stack_a, 1);
		// }
		else
		{
			make_ra(stack_a, 1); // find_way;????????????????????????????????????
			print_stacks(*stack_a, *stack_b);
		}
			sleep (1);
		
	}
	// block->pivot_i = find_pivot(arr, block->pivot_i, block->curr_size_a);
	// sleep(100);
	// ft_printf("======FRST================================================FRST==============\n");
	
}










