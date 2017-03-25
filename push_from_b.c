/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_from_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 21:48:27 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/25 21:48:28 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char			check_heavy_elem_in_top(t_stack *stack_b)
{
	int p;
	int is_max;
	t_stack *tmp;

	if (!stack_b)
		return (0);
	tmp = stack_b;
	p = stack_b->p;
	is_max = stack_b->data;
	while (tmp && p == tmp->p)
	{
		if (is_max < tmp->data)
			return (0);
		tmp = tmp->next;
	}
	while (stack_b && p == stack_b->p)
	{
		stack_b->p--;
		stack_b = stack_b->next;
	}
	return (1);
}

int 	is_last_pivot(t_stack *stack_b, int pivot)
{
	printf("pivot %d\n", pivot);
	while (stack_b)
	{
		if (pivot != stack_b->data)
			return (0);
		stack_b = stack_b->next;
	}
	return (1);
}

int 			find_rem_b_pivot(t_stack *stack_b, int pivot)
{
	int limmit = stack_b->p;

	while (stack_b)
	{
		if (stack_b->p != limmit)
			return (0);
		if (pivot <= stack_b->data)
			return (1);
		stack_b = stack_b->next;
	}
	return (0); //?????????????
}
int 			find_low_ind(t_stack *stack_b)
{
	int cmp;

	if (!stack_b)
		return (0);
	cmp = stack_b->p;
	while (stack_b)
	{
		if (stack_b->p != cmp)
			return (stack_b->p);
		stack_b = stack_b->next;
	}
	return (0);
}

void			push_from_b(t_stack **stack_a, t_stack **stack_b, int *arr, t_block *block)
{
	int rrb;

	rrb = 0;
	if (check_heavy_elem_in_top(*stack_b))
	{
		make_pa(stack_a, stack_b, 1);
		print_stacks(*stack_a, *stack_b); //bonus
		block->curr_size_b-- && block->curr_size_a++;
		return ;
	}
	printf("curr_size_b %d\n", block->curr_size_b);
	block->pivot_i = find_pivot(arr, find_low_ind(*stack_b), (*stack_b)->p);
	printf("pivot\nindex %d\nvalue %d\n", block->pivot_i, arr[block->pivot_i]);

	for (int j = 0; j < block->max_size; ++j)
	{
		printf("arr[%d] == [%d]\n", j, (arr[j]));
	}
	while (find_rem_b_pivot(*stack_b, arr[block->pivot_i]))
	{
		printf("pivot\nindex %d\nvalue %d\n", block->pivot_i, arr[block->pivot_i]);
			// sleep(20);
		if ((arr[block->pivot_i]) <= (*stack_b)->data)
		{
			make_pa(stack_a, stack_b, 1);
			block->curr_size_b-- && block->curr_size_a++;
			print_stacks(*stack_a, *stack_b);
		}
		else
		{
			rrb++;
			(*stack_b)->p = block->pivot_i;
			make_rb(stack_b, 1);
			print_stacks(*stack_a, *stack_b);
		}
		// sleep(100);
		
	}
	while (rrb)
	{
		if (is_last_pivot(*stack_b, (*stack_b)->p))
			break ;
		make_rrb(stack_b, 1);
		print_stacks(*stack_a, *stack_b);
		rrb--;
	}
	// for (int j = 0; j < block->max_size; ++j)
	// {
	// 	printf("arr[%d] == [%d]\n", j, (arr[j]));
	// }
	// chenge_pivot_pack(stack_b, )
	// sleep(1000);
}