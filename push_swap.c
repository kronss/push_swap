/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:55:02 by ochayche          #+#    #+#             */
/*   Updated: 2018/03/17 17:49:32 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	init_var_array(int *var, int cnt)
{
	var[PSHD] = 0;
	var[PIVOT] = 0;
	var[SIZE] = cnt;
	var[ROTAT] = 0;
}

void				recn_a(t_stack **stack_a, t_stack **stack_b,
													t_block *block, int cnt)
{
	int		var[MAX_VAR];

	init_var_array(var, cnt);
	if (cnt <= 3)
		return (sort_3_elem_a(stack_a, stack_b, block, cnt));
	var[PIVOT] = find_pivot(*stack_a, cnt);
	while (cnt >= 0)
	{
		if (!rem_less_then_pivot(*stack_a, var[PIVOT], cnt))
			break ;
		if ((*stack_a)->data < var[PIVOT] && ++var[PSHD])
			make_pb(stack_a, stack_b, 1, block);
		else
		{
			make_ra(stack_a, stack_b, 1, block);
			var[ROTAT]++;
		}
		cnt--;
	}
	while (var[ROTAT]-- && linked_list_len(*stack_a) != var[SIZE] - var[PSHD])
		make_rra(stack_a, stack_b, 1, block);
	recn_a(stack_a, stack_b, block, var[SIZE] - var[PSHD]);
	recn_b(stack_a, stack_b, block, var[PSHD]);
	while (var[PSHD]--)
		make_pa(stack_a, stack_b, 1, block);
}

void				recn_b(t_stack **stack_a, t_stack **stack_b,
													t_block *block, int cnt)
{
	int		var[MAX_VAR];

	init_var_array(var, cnt);
	if (cnt <= 3)
		return (sort_3_elem_b(stack_a, stack_b, block, cnt));
	var[PIVOT] = find_pivot(*stack_b, cnt);
	while (cnt >= 0)
	{
		if (!rem_more_then_pivot(*stack_b, var[PIVOT], cnt))
			break ;
		if ((*stack_b)->data > var[PIVOT] && ++var[PSHD])
			make_pa(stack_a, stack_b, 1, block);
		else
		{
			make_rb(stack_a, stack_b, 1, block);
			var[ROTAT]++;
		}
		cnt--;
	}
	recn_a(stack_a, stack_b, block, var[PSHD]);
	while (var[ROTAT]-- && linked_list_len(*stack_b) != var[SIZE] - var[PSHD])
		make_rrb(stack_a, stack_b, 1, block);
	recn_b(stack_a, stack_b, block, var[SIZE] - var[PSHD]);
	while (var[PSHD]--)
		make_pb(stack_a, stack_b, 1, block);
}

int					main(int ar, char **av)
{
	t_block	block;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	init_var(&block, &stack_a, &stack_b);
	i = read_flags(&block, av, ar, PUSH_SWAP);
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
	optimization(&block);
	print_operation(&block.copy_a, &stack_b, &block);
	free_memory(&stack_a, &stack_b, &block);
	return (0);
}
