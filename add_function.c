/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_function.c                                     :+:      :+:    :+:   */
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
		if (pivot > stack_a->data)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

char			find_rem_b(t_stack *stack_b, int pivot)
{
	while (stack_b)
	{
		if (pivot <= stack_b->data)
			return (1);
		stack_b = stack_b->next;
	}
	return (0);
}


int				find_pivot(t_stack *stack_a, int max_size)
{
	int arr[max_size];
	int i;

	i = 0;
	while (stack_a && i < max_size)
	{
		arr[i] = stack_a->data;
		stack_a = stack_a->next;
		i++;
	}
	i--;
	q_sort(arr, 0, i);
	return (arr[(0 + i) / 2]);
}

int				linked_list_len(t_stack *tmp)
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