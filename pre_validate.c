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

void				validate(t_stack *stack_a)
{
	t_stack 		*tmp;
	int				cmp;

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
		validate(stack_a->next);
}

void				pre_validate(t_stack *stack_a)
{
	if (stack_a)
		validate(stack_a);
	else
		exit(0);
}