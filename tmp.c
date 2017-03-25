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
	// printf("=========\n");
	// int pivot_i;

	return ((begin + max_size) / 2);
		// return (pivot_i);
	// else
	// 	return (find_pivot(arr, (begin + max_size)/2, max_size));
}

void			sort_2_elem(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
	{
		// ft_printf("===== 2 1 ==============================\n");
		check_ss(*stack_b, block) ? make_ss(stack_a, stack_b, 1) : make_sa(stack_a, 1);
	}
	// else
	// 	ft_printf("===== 1 2 ==============================\n");
}



// 
// void			push_from_b_last(stack_a, stack_b, arr, block)
// {
// 	if (block->curr_size_b == 3)
// 	{
// 		if ((*stack_b)->data > (*stack_b)->next->data) // c > b
// 		{
// 			if ((*stack_b)->next->data > (*stack_b)->next->next->data) //b > a
// 			{
// 				make_pa(stack_a, stack_b);
// 				make_pa(stack_a, stack_b);
// 				make_pa(stack_a, stack_b);
// 			}
// 			else
// 			{
// 				make_pa(stack_a, stack_b); // b < a
// 				make_sb(stack_a, stack_b);
// 				make_pa(stack_a, stack_b);
// 				make_pa(stack_a, stack_b);
// 			}
// 		}
// 	}
// 	else if (block->curr_size_b == 2)
// 	{

// 	}	
// 	else


// }

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

// char 		find_way_ra_rra(t_stack *stack_a, t_block *block, int pivot)
// {
// 	// t_stack *tmp;
// 	int size;
// 	int ra;
// 	int rra;

// 	ra = 0;
// 	rra = 0;
// 	size = -block->curr_size_a * 2 / 3;
// 	while (stack_a)
// 	{
// 		if (pivot > stack_a->data)
// 			size <= 0 ? ra++ : rra++;
// 		size++;
// 		stack_a = stack_a->next;
// 	}
// 	return (ra >= rra) ? (1) : (0);
// }

void			push_from_a(t_stack **stack_a, t_stack **stack_b, int *arr, t_block *block)
{
	block->pivot_i = find_pivot(arr, block->pivot_i, block->max_size);
	//print_stacks(*stack_a, *stack_b); //sleep(1);
	// 	for (int j = 0; j < block->max_size; ++j)
	// {
	// 	printf("arr[%u] == [%u]\n", j, (arr[j]));
	// }
	// printf("pivot\nindex %d\nvalue %d\n", block->pivot_i, arr[block->pivot_i]); sleep(5);
	// sleep(5);
	
	while (find_rem_a(*stack_a, arr[block->pivot_i]))   // check (elem);
	{
		if (check_stack_a(*stack_a))
			return ;
		// printf("arr[%d] > data[%d]\n", arr[block->pivot_i], (*stack_a)->data);
		// printf("pivot_ind %d\n", block->pivot_i);
		if (arr[block->pivot_i] > (*stack_a)->data)
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
			// sleep (1);
	}
	// block->pivot_i = find_pivot(arr, block->pivot_i, block->curr_size_a);
	// sleep(100);
	// ft_printf("======FRST================================================FRST==============\n");
	block->curr_size_a == 3 ? frst_sort_3_elem(stack_a, stack_b, block) : 0;
	block->curr_size_a == 2 ? sort_2_elem(stack_a, stack_b, block) : 0;
	block->curr_size_a == 1 ? ft_printf(" ===== 1 ================================\n") : 0;
}

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

// check_packlen(t_stack *)

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
	print_stacks(*stack_a, *stack_b);
	while (!check_stack_a(*stack_a))
		push_from_a(stack_a, stack_b, arr, block);
	// printf("pivot\nindex %d\nvalue %d\n", block->pivot_i, arr[block->pivot_i]);
	
	//block->pivot_i = find_pivot(arr, block->pivot_i, block->max_size - 1);
	while (block->curr_size_b)
	{
		// if (check_stack_a(*stack_a) && (check_stack_b(*stack_b)))
		// {
		// 	ultimate(stack_a, stack_b, block);
		// 	return ;
		// }
		push_from_b(stack_a, stack_b, arr, block);
		sleep(2);
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
