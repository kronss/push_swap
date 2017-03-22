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

// int				look_mediana(t_stack *stack_a, int min, int max)
// {
// 	t_stack *tmp;
// 	int pvt;
// 	int tmp_pvt;

// 	tmp = stack_a;
// 	while (tmp)
// 	{
// 		tmp->data > max ? max = tmp->data : 0;
// 		tmp->data < min ? min = tmp->data : 0;
// 		tmp = tmp->next;
// 	}
// 	tmp_pvt = (max + min) / 2;
// 	ft_printf("min = %d\n", min);
// 	ft_printf("max = %d\n", max);
// 	// tmp = stack_a;
// 	ft_printf("mediana = %d\n", tmp_pvt);

// 	return (tmp_pvt);
// }

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
    int i = first, j = last, x = s_arr[(first + last) / 2];

    while (i <= j) {
        while (s_arr[i] < x) i++;
        while (s_arr[j] > x) j--;

        if(i <= j) {
            if (s_arr[i] > s_arr[j]) ft_swap(&s_arr[i], &s_arr[j]);
            i++;
            j--;
        }
    } 

    if (i < last)
        q_sort(s_arr, i, last);
    if (first < j)
        q_sort(s_arr, first, j);
}

void begin_sorting(t_stack **stack_a, t_stack **stack_b, unsigned int size)
{
	int arr[size];

	push_data_ta_arr(*stack_a, arr);
	for (unsigned int j = 0; j < size; ++j)
	{
		printf("arr[%u] == [%u]\n", j, (arr[j]));
	}
	q_sort(arr, 0, size - 1);
	printf("===========\n");
	for (unsigned int j = 0; j < size; ++j)
	{
		printf("arr[%u] == [%u]\n", j, (arr[j]));
	}
	if (size > 3)
		
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
	pre_validate(stack_a, &block.size);
	/*=====================================================*/
	ft_printf("size %u\n", block.size);
	begin_sorting(&stack_a, &stack_b, block.size);

	print_stacks(stack_a, stack_b); //bonus
	// look_mediana(stack_a, stack_a->data, stack_a->next->data);


	return (0);
}
