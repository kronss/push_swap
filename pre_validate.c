/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:52:56 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/19 18:52:57 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			validate(t_stack *stack_a, int *size)
{
	t_stack		*tmp;
	int			cmp;

	cmp = stack_a->data;
	tmp = stack_a->next;
	while (tmp)
	{
		cmp == tmp->data ? ps_error(1) : 0;
		tmp = tmp->next;
	}
	if (stack_a->next == NULL)
		return ;
	else
	{
		validate(stack_a->next, size);
		(*size)++;
	}
}

void			pre_validate()
{
	t_stack		*tmp;

	if (g_stack_head_a)
	{
		validate(g_stack_head_a, &g_block.max_size);
		g_block.pivot_i = 0;
		g_block.rra = 0;
	}
	else
		exit(0);
	tmp = g_stack_head_a;
	while (tmp)
	{
		tmp->p = g_block.max_size - 1;
		tmp = tmp->next;
	}
}
