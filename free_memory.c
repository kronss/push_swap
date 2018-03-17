/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 12:34:51 by ochayche          #+#    #+#             */
/*   Updated: 2018/03/17 12:35:13 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *head)
{
	t_stack	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		ft_memdel((void **)&tmp);
	}
}

static void	free_oper(t_oper *head)
{
	t_oper	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		ft_memdel((void **)&tmp);
	}
}

void		free_memory(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	free_stack(*stack_a);
	free_stack(*stack_b);
	free_stack(block->copy_a);
	free_oper(block->oper);
}
