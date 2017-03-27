/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:34:08 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/27 11:34:09 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_oper		*create_operation(char *str)
{
	t_oper			*new;
	if (!(new = malloc(sizeof(t_oper *))))
		return (NULL);
	new->data = str;
	new->next = NULL;

}

void 				operation_push_back(t_oper *oper, char *str)
{
	t_oper *tmp;

	tmp = oper;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_operation(str);
	}
	else
	{
		oper = create_operation(str);
	}
}
