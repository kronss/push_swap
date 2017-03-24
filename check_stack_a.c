/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:36:00 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/24 15:36:01 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		check_stack_a(t_stack *stack_a)
{
	int		tmp;

	tmp = stack_a->data;
	if (stack_a)
	{
		while (stack_a)
		{
			// ft_printf("cheker %d\n", tmp);
			if (tmp > stack_a->data)
			{
				return (0) ;
			}
			tmp = stack_a->data;
			stack_a = stack_a->next;
		}
	}
	return (1);
}

char		check_stack_b(t_stack *stack_b)
{
	int		tmp;

	tmp = stack_b->data;
	if (stack_b)
	{
		while (stack_b)
		{
			// ft_printf("cheker %d\n", tmp);
			if (tmp < stack_b->data)
			{
				return (0) ;
			}
			tmp = stack_b->data;
			stack_b = stack_b->next;
		}
	}
	return (1);
}

void		ultimate(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	ft_printf("================================================ULTIMATE================================================\n");
	while (block->curr_size_b)
	{
		make_pa(stack_a, stack_b, 1);
		block->curr_size_a++ && block->curr_size_b--;
	}
}