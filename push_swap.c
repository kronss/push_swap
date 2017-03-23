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
	// for (int j = 0; j < max_size; ++j)
	// {
	// 	printf("arr[%d] == [%d]\n", j, (arr[j]));
	// }
	printf("=========\n");
	int pivot_i;

	pivot_i = begin;
	if (ABS(max_size - begin) < 4)
		return (pivot_i);
	else
		return (find_pivot(arr, (begin + max_size)/2, max_size));
}

void			sort_2_elem(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
	{
		ft_printf("===== 2 1 ==============================\n");
		check_ss(*stack_b, block) ? make_ss(stack_a, stack_b, 1) : make_sa(stack_a, 1);
	}
	else
		ft_printf("===== 1 2 ==============================\n");
}

void			push_from_a(t_stack **stack_a, t_stack **stack_b, int *arr, t_block *block)
{
	print_stacks(*stack_a, *stack_b);
	// 	for (int j = 0; j < block->max_size; ++j)
	// {
	// 	printf("arr[%u] == [%u]\n", j, (arr[j]));
	// }
	// sleep(10);

	while (block->curr_size_a > block->max_size - block->pivot_i)
	{
		print_stacks(*stack_a, *stack_b);
		printf("arr[%d] > data[%d]\n", arr[block->pivot_i], (*stack_a)->data);
		if (arr[block->pivot_i] > (*stack_a)->data)
		{
			make_pb(stack_a, stack_b, 1);
			(block->curr_size_a)--;
			(block->curr_size_b)++;
		}
		else
			make_ra(stack_a, 1);
			// sleep (1);
	}
	ft_printf("======FRST================================================FRST==============\n");
	block->curr_size_a == 3 ? frst_sort_3_elem(stack_a, stack_b, block) : 0;
	block->curr_size_a == 2 ? sort_2_elem(stack_a, stack_b, block) : 0;
	block->curr_size_a == 1 ? ft_printf(" ===== 1 ================================\n") : 0;
}

void			push_from_b(t_stack **stack_a, t_stack **stack_b, int *arr, t_block *block)
{
	block->pivot_i = find_pivot(arr, 1, block->pivot_i);
	printf("block->pivot_i == %d\n", block->pivot_i);
	ft_printf("===========\n");

	for (int j = 0; j < block->max_size; ++j)
	{
		printf("arr[%d] == [%d]\n", j, (arr[j]));
	}

	// block->curr_size_b > 2 ? tmp = block->curr_size_a + 3 : 0;
	// print_stacks(*stack_a, *stack_b);
	// printf("tmp %d\n", tmp);
	// printf("block->curr_size_a %d\n", block->curr_size_a);
	// printf("arr[tmp] %d\n", arr[tmp]);
	// printf("arr[tmp - size] %d\n", arr[tmp - block->size]);
	
	 while (block->curr_size_a < block->max_size - block->pivot_i)
	{
		printf("%d\n", arr[block->pivot_i]);
		print_stacks(*stack_a, *stack_b);
		if (arr[block->pivot_i] <= (*stack_b)->data)
		{
			make_pa(stack_a, stack_b, 1);
			(block->curr_size_a)++;
			(block->curr_size_b)--;
		}
		else
			make_rb(stack_b, 1);
		
		sleep(4);
	}
	// frst_sort_3_elem(stack_a, stack_b, block);
}




void			begin_sorting(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	int			arr[block->max_size];

	push_data_ta_arr(*stack_a, arr);
	q_sort(arr, 0, block->max_size - 1);
	block->pivot_i = (block->max_size > 6) ? find_pivot(arr, block->pivot_i, block->max_size) : 3;
	// for (int j = 0; j < block->max_size; ++j)
	// {
	// 	printf("arr[%d] == [%d]\n", j, (arr[j]));
	// }
	printf("block->pivot_i == %d\n", block->pivot_i);
	ft_printf("===========\n");
	// for (int j = 0; j < block->size; ++j)
	// {
	// 	ft_printf("arr[%u] == [%u]\n", j, (arr[j]));
	// }
	// if (block->curr_size_a > 3)
	// {
		push_from_a(stack_a, stack_b, arr, block);
	// }
	printf("block->pivot_i == %d\n", block->pivot_i);

	if (block->pivot_i > 2)
		push_from_b(stack_a, stack_b, arr, block);
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
	ft_printf("size %i\n", block.max_size);
	block.max_size > 1 ? begin_sorting(&stack_a, &stack_b, &block) : 0;

	print_stacks(stack_a, stack_b); //bonus
	// look_mediana(stack_a, stack_a->data, stack_a->next->data);


	return (0);
}
