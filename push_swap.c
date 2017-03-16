/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:55:02 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/16 17:55:02 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void				validate(t_stack *list)
{
	t_stack 		*tmp;
	int				cmp;

	cmp = list->a;
	tmp = list->next;
	while (tmp)
	{
		cmp == tmp->a ? ps_error(1) : 0;
		tmp = tmp->next;
	}
	if (list->next == NULL)
		return ;
	else
		validate(list->next);
}

int							main(int ar, char **av)
{
	t_stack			*list;
	int				i;

	i = 0;
	list = NULL;
	while (++i < ar)
	{
		list_push_front(&list, ft_atoi(av[i]));
	}
	(ar > 2) ? validate(list) : 0;





	t_stack *tmp;							//debug
	tmp = list;
	i = 0;
	while (tmp)
	{
		ft_printf("[%d] -- [%d]\n", i, tmp->a);
		tmp = tmp->next;
		i++;
	}

	return (0);
}
