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

char			find_rem_a(t_stack *stack_a, int pivot)
{
	while (stack_a)
	{
		if (pivot >= stack_a->data)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

char			find_rem_b(t_stack *stack_b, int pivot)
{
	while (stack_b)
	{
		if (pivot < stack_b->data)
			return (1);
		stack_b = stack_b->next;
	}
	return (0);
}


int				find_pivot(t_stack *stack_a, int max_size)
{
	// printf("max_size %d\n", max_size);
	int arr[max_size];
	int i;

	i = 0;
	while (stack_a && i < max_size)
	{
		// printf("%d\n", stack_a->data);
		arr[i] = stack_a->data;
		

		stack_a = stack_a->next;
		i++;
	}
	i--;

	q_sort(arr, 0, i);
	// printf("==========%d\n", arr[0]);

	// for (int j = 0; j < max_size; j++)
	// {
	// 	printf("arr[%d] == [%d]\n", j, (arr[j]));
		
	// }
	// sleep (1);
	return (arr[(0 + i) / 2]);
}


int 			linked_list_len(t_stack *tmp)
{
	int i;

	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void			sort_3_elem_a(t_stack **stack_a, t_stack **stack_b, t_block *block, int max_size)
{
	int i;

	i = linked_list_len(*stack_a);
	if (i <= 3)
	{
		i == 3 ? frst_sort_3_elem_a(stack_a, stack_b, block) : 0;
		i == 2 ? sort_2_elem_a(stack_a, stack_b, block) : 0;
		block->rra = 1;
	}
	else
	{
		max_size == 3 ? next_sort_3_elem_a(stack_a, stack_b, block) : 0;
		max_size == 2 ? sort_2_elem_a(stack_a, stack_b, block) : 0;
	}
}

void			sort_3_elem_b(t_stack **stack_a, t_stack **stack_b, t_block *block, int max_size)
{
	int i;
	
	i = linked_list_len(*stack_b);
	if (i <= 3)
	{
		i == 3 ? last_sort_3_elem_b(stack_a, stack_b, block) : 0;
		i == 2 ? sort_2_elem_b(stack_a, stack_b, block) : 0;
		// block->rra = 0;
	}
	else
	{
		max_size == 3 ? next_sort_3_elem_b(stack_a, stack_b, block) : 0;
		max_size == 2 ? sort_2_elem_b(stack_a, stack_b, block) : 0;
	}
}

void			recursion_a(t_stack **stack_a, t_stack **stack_b, t_block *block, int max_size)
{
	int push_b;
	int rra;

	push_b = 0;
	rra = 0;
	if (max_size <= 3)
		return (sort_3_elem_a(stack_a, stack_b, block, max_size));
	block->pivot_i = find_pivot(*stack_a, max_size);

	while (find_rem_a(*stack_a, block->pivot_i))
	{
		// printf("block->pivot_i %d\n", block->pivot_i);
		// printf("block->pivot_i %d > %d   A\n", block->pivot_i, (*stack_a)->data);
		if ((*stack_a)->data <= block->pivot_i)
		{
			make_pb(stack_a, stack_b, 1, block);
			block->debug ? print_stacks(*stack_a, *stack_b) : 0;
			push_b++;
		}
		else
		{
			make_ra(stack_a, stack_b, 1, block); // find_way;????????????????????????????????????
			block->debug ? print_stacks(*stack_a, *stack_b): 0;
			block->rra ? rra++ : 0;
		}
	}
	while (rra && block->rra)
	{
		// if (check_stack_a(*stack_a))
		// 	break ;
		make_rra(stack_a, 1); // find_way;????????????????????????????????????
		block->debug ? print_stacks(*stack_a, *stack_b): 0;
		rra--;
	}
	recursion_a(stack_a, stack_b, block, max_size - push_b);
	recursion_b(stack_a, stack_b, block, push_b);
	while (push_b --)
	{
		make_pa(stack_a, stack_b, 1);
		block->debug ? print_stacks(*stack_a, *stack_b): 0;
	}
}

void 			recursion_b(t_stack **stack_a, t_stack **stack_b, t_block *block, int push_b)
{
	int push_a;
	int rrb;
	int len;

	if (push_b <= 3)
		return (sort_3_elem_b(stack_a, stack_b, block, push_b));
	len = push_b;

	push_a = 0;
	rrb = 0;
	block->pivot_i = find_pivot(*stack_b, push_b);
	
	while (find_rem_b(*stack_b, block->pivot_i))
	{
		// printf("block->pivot_i %d\n", block->pivot_i);
		// printf("block->pivot_i %d < %d   B\n", block->pivot_i, (*stack_a)->data);
		if ((*stack_b)->data > block->pivot_i)
		{
			make_pa(stack_a, stack_b, 1);
			block->debug ? print_stacks(*stack_a, *stack_b) : 0;
			(block->curr_size_a)++;
			(block->curr_size_b)--;
			push_a++;
		}
		else
		{
			make_rb(stack_b, 1);
			block->debug ? print_stacks(*stack_a, *stack_b): 0;
			rrb++;
		}
	}
	recursion_a(stack_a, stack_b, block, push_b);
	while (rrb)
	{
		make_rrb(stack_b, 1);
		block->debug ? print_stacks(*stack_a, *stack_b): 0;
		rrb--;
	}
	recursion_b(stack_a, stack_b, block, len - push_a);
	while (push_a--)
	{
		make_pb(stack_a, stack_b, 1);
		block->debug ? print_stacks(*stack_a, *stack_b): 0;
	}
}	

void			begin_sorting(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	block->debug ? print_stacks(*stack_a, *stack_b) : 0;
	recursion_a(stack_a, stack_b, block, block->max_size);
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
	
	block.max_size > 1 ? begin_sorting(&stack_a, &stack_b, &block) : 0;
	block.debug ? print_stacks(stack_a, stack_b) : 0; //bonus
	// print_stacks(stack_a, stack_b);
	return (0);
}
