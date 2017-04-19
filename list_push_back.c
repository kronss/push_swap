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

static t_stack	*create_elem(int a)
{
	t_stack		*new;

	if (!(new = malloc(sizeof(t_stack *))))
		return (NULL);
	new->data = a;
	new->p = 0;
	new->next = NULL;
	return (new);
}

void			check_value(char *str)
{
	int			i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		check_value(str + 1);
	else if (str[0] == '\0')
		ps_error(3);
	else
	{
		while (str[i] != '\0')
		{
			if (!('0' <= *str && *str <= '9') || i > 10)
				ps_error(2);
			i++;
		}
	}
}

void			list_push_back(t_stack **begin_list, long a, char *str)
{
	t_stack		*list;

	list = *begin_list;
	check_value(str);
	if (!(-2147483648 <= a && a <= 2147483647))
		ps_error(5);
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = create_elem((int)a);
	}
	else
		*begin_list = create_elem((int)a);
}
