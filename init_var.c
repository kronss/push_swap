/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_g_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 21:16:13 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/21 21:16:14 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		func_is_a_sort(t_stack *stack_a)
{
	int		tmp;

	tmp = stack_a->data;
	if (!stack_a->next)
		return (TRUE);
	stack_a =stack_a->next;
	if (stack_a)
	{
		while (stack_a)
		{
			// ft_printf("cheker %d\n", tmp);
			if (tmp > stack_a->data)
			{
				return (FALSE) ;
			}
			tmp = stack_a->data;
			stack_a = stack_a->next;
		}
	}
	return (TRUE);
}

int		func_is_b_empty()
{
	if (g_stack_head_b)
	{
		return (FALSE);
	}
	return (TRUE);
}


void		init_g_var()
{
	g_block.debug = 0;
	g_block.file = 0;
	g_block.color = 0;
	g_block.max_size = 1;
	g_stack_head_a = NULL;
	g_stack_head_b = NULL;
	g_block.oper = NULL;
	g_block.pivot_i = 0;

	g_block.is_a_sort = &func_is_a_sort;
	g_block.is_b_empty = &func_is_b_empty;

}
