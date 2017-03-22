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
	unsigned int i;

	i = 0;
	while (stack_a)
	{
		arr[i] = stack_a->data;
		stack_a = stack_a->next;
		i++;
	}
}

void		q_sort(int* s_arr, int first, int last)
{
    int i;
    int j;
    int x;
    
    i = first;
    j = last;
    x = s_arr[(first + last) / 2];
    while (i <= j)
    {
        while (s_arr[i] < x)
        	i++;
        while (s_arr[j] > x)
        	j--;
        if(i <= j)
        {
            if (s_arr[i] > s_arr[j])
            	ft_swap(&s_arr[i], &s_arr[j]);
            i++;
            j--;
        }
    } 
    if (i < last)
        q_sort(s_arr, i, last);
    if (first < j)
        q_sort(s_arr, first, j);
}


void			work_1(t_stack **stack_a, t_stack **stack_b, int *arr, t_block *block)
{
	print_stacks(*stack_a, *stack_b);
	while (block->curr_size_a > 3)
	{
		// print_stacks(*stack_a, *stack_b);
		if (arr[block->size - 3] > (*stack_a)->data)
		{
			make_pb(stack_a, stack_b, 1);
			(block->curr_size_a)--;
			(block->curr_size_b)++;
		}
		else
			make_ra(stack_a, 1);
		// sleep(1);
	}
	frst_sort(stack_a, stack_b, block);
}

void			begin_sorting(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	int arr[block->size];

	push_data_ta_arr(*stack_a, arr);
	// for (int j = 0; j < block->size; ++j)
	// {
	// 	ft_printf("arr[%u] == [%u]\n", j, (arr[j]));
	// }
	q_sort(arr, 0, block->size - 1);
	ft_printf("===========\n");
	// for (int j = 0; j < block->size; ++j)
	// {
	// 	ft_printf("arr[%u] == [%u]\n", j, (arr[j]));
	// }
	if (block->size > 3)
		work_1(stack_a, stack_b, arr, block);
		
	// printf("dick\n");
}

// void							quik_sort(unsigned int size, unsigned int i, t_stack *stack_a)
// {
// 	unsigned int 			arr[size];

// 	while (stack_a)
// 	{
// 		arr[i] = stack_a->data;
// 		stack_a = stack_a->next;
// 		i++;
// 	}
// 	
// }

// void			quik_sort(block.size, 0, stack_a)

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
	ft_printf("size %u\n", block.size);
	begin_sorting(&stack_a, &stack_b, &block);

	// print_stacks(stack_a, stack_b); //bonus
	// look_mediana(stack_a, stack_a->data, stack_a->next->data);


	return (0);
}
