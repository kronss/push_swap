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

void	push_data_ta_arr(t_stack *stack_a, int *arr)
{
	int i;

	i = 0;
	while (stack_a)
	{
		arr[i] = stack_a->data;
		stack_a = stack_a->next;
		i++;
	}
}

int 			find_pivot(int *arr, int begin, int max_size)
{
	return ((begin + max_size) / 2);
}



void			begin_sorting(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	int			arr[block->max_size];

	push_data_ta_arr(*stack_a, arr);
	q_sort(arr, 0, block->max_size - 1);
	// block->pivot_i = find_pivot(arr, block->pivot_i, block->max_size - 1);
	// for (int j = 0; j < block->max_size; ++j)
	// {
	// 	printf("arr[%d] == [%d]\n", j, (arr[j]));
	// }
	// printf("pivot\nindex %d\nvalue %d\n", block->pivot_i, arr[block->pivot_i]); sleep(5);
	// ft_printf("===========\n");
	
	// for (int j = 0; j < block->size; ++j)
	// {
	// 	ft_printf("arr[%u] == [%u]\n", j, (arr[j]));
	// }
	// if (block->curr_size_a > 3)
	// {
	// block->pivot_i = block->curr_size_a - 1;
	// while (!check_stack_a(*stack_a))
	// 	push_from_a(stack_a, stack_b, arr, block);
	print_stacks(*stack_a, *stack_b);
	while (!check_stack_a(*stack_a) || (*stack_b))
	{
		while (!check_stack_a(*stack_a))
			push_from_a(stack_a, stack_b, arr, block);


	// printf("pivot\nindex %d\nvalue %d\n", block->pivot_i, arr[block->pivot_i]);
	
	//block->pivot_i = find_pivot(arr, block->pivot_i, block->max_size - 1);
		// while (block->curr_size_b)
		// {
			// if (check_stack_a(*stack_a) && (check_stack_b(*stack_b)))
			// {
			// 	ultimate(stack_a, stack_b, block);
			// 	return ;
			// }
		if (*stack_b)
			push_from_b(stack_a, stack_b, arr, block);
		sleep(2);
	// }
	}
	// if (block->curr_size_b)
	// 	push_from_b_last(stack_a, stack_b, arr, block);
	// printf("dick\n");
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
	// ft_printf("size %i\n", block.max_size);
	block.max_size > 1 ? begin_sorting(&stack_a, &stack_b, &block) : 0;

	// print_stacks(stack_a, stack_b); //bonus
	// look_mediana(stack_a, stack_a->data, stack_a->next->data);


	return (0);
}
