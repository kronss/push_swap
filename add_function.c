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

/*
** rem_less_then_pivot
** used for recn_a
** if any number less then pivot
*/

int			rem_less_then_pivot(t_stack *curr, int pivot, int max)
{
	int		i;

	i = 0;
	while (curr && (i < max))
	{
		if (curr->data <= pivot)
			return (1);
		curr = curr->next;
		i++;
	}
	return (0);
}

/*
** rem_more_then_pivot
** used for recn_b
** if any number more then pivot
*/

int			rem_more_then_pivot(t_stack *curr, int pivot, int max)
{
	int		i;

	i = 0;
	while (curr && (i < max))
	{
		if (curr->data >= pivot)
			return (1);
		curr = curr->next;
		i++;
	}
	return (0);
}

int			find_pivot(t_stack *tmp, int max_size)
{
	int		arr[max_size];
	int		i;

	i = 0;
	while (tmp && i < max_size)
	{
		arr[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	i--;
	q_sort(arr, 0, i);
	return (arr[(i + 1) / 2]);
}

int			linked_list_len(t_stack *tmp)
{
	int		i;

	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int			is_sorted(t_stack *curr)
{
	int		previos_nbr;

	previos_nbr = curr->data;
	curr = curr->next;
	while (curr)
	{
		if (previos_nbr > curr->data)
		{
			return (FALSE);
		}
		previos_nbr = curr->data;
		curr = curr->next;
	}
	return (TRUE);
}
