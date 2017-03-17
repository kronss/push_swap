/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 21:35:11 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/16 21:35:12 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack		*create_elem(int a)
{
	t_stack			*new;
	if (!(new = malloc(sizeof(t_stack *))))
		return (NULL);
	new->a = a;
	new->next = NULL;
	return (new);
}

void				list_push_front(t_stack **begin_list, int a)
{
	t_stack *tmp;

	if (*begin_list)
	{
		tmp = create_elem(a);
		tmp->next = *begin_list;
		*begin_list = tmp;
	}
	else
		*begin_list = create_elem(a);
}

void				list_push_back(t_stack **begin_list, int a)
{
	t_stack			*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = create_elem(a);
	}
	else
		*begin_list = create_elem(a);
}
