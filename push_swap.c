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

static inline void	init_var_array(int *variable, int cnt)
{
	variable[PUSHED_CNT] = 0;
	variable[PIVOT] = 0;
	variable[SIZE] = cnt;
	variable[ROTATE_CNT] = 0;
}

void		recn_a(t_stack **stack_a, t_stack **stack_b, t_block *block, int cnt)
{
	int		variable[MAX_VAR];
	// int		variable[PUSHED_CNT];
	// int		variable[PIVOT];
	// int		variable[SIZE];
	// int		variable[ROTATE_CNT];

	init_var_array(variable, cnt);
	if (cnt < 3)
		return (sort_3_elem_a(stack_a, stack_b, block, cnt));
	variable[PIVOT] = find_pivot(*stack_a, cnt);
	while (cnt >= 0)
	{
		if (!rem_less_then_pivot(*stack_a, variable[PIVOT], cnt))
			break;	
		if ((*stack_a)->data < variable[PIVOT] && ++variable[PUSHED_CNT])
			make_pb(stack_a, stack_b, 1, block);
		else
		{
			make_ra(stack_a, stack_b, 1, block);
			variable[ROTATE_CNT]++;
		}
		cnt--;
	}
	while (variable[ROTATE_CNT]-- && linked_list_len(*stack_a) != variable[SIZE] - variable[PUSHED_CNT])
		make_rra(stack_a, stack_b, 1, block);
	recn_a(stack_a, stack_b, block, variable[SIZE] - variable[PUSHED_CNT]);	
	recn_b(stack_a, stack_b, block, variable[PUSHED_CNT]);
	while (variable[PUSHED_CNT]--)
		make_pa(stack_a, stack_b, 1, block);
}

void		recn_b(t_stack **stack_a, t_stack **stack_b, t_block *block, int cnt)
{
	int		variable[MAX_VAR];

	init_var_array(variable, cnt);
	if (cnt < 3)
		return (sort_3_elem_b(stack_a, stack_b, block, cnt));
	variable[PIVOT] = find_pivot(*stack_b, cnt);
	while (cnt >= 0)
	{
		if (!rem_more_then_pivot(*stack_b, variable[PIVOT], cnt))
			break;
		if ((*stack_b)->data > variable[PIVOT] && ++variable[PUSHED_CNT])
			make_pa(stack_a, stack_b, 1, block);
		else
		{
			make_rb(stack_a, stack_b, 1, block);
			variable[ROTATE_CNT]++;
		}
		cnt--;
	}
	recn_a(stack_a, stack_b, block, variable[PUSHED_CNT]);
	while (variable[ROTATE_CNT]-- && linked_list_len(*stack_b) != variable[SIZE] - variable[PUSHED_CNT])
		make_rrb(stack_a, stack_b, 1, block);
	recn_b(stack_a, stack_b, block, variable[SIZE] - variable[PUSHED_CNT]);
	while (variable[PUSHED_CNT]--)
		make_pb(stack_a, stack_b, 1, block);
}

int			main(int ar, char **av)
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
