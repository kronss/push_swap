/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 22:25:58 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/16 22:25:59 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void				validate(t_stack *list)
{
	t_stack 		*tmp;
	int				cmp;

	cmp = list->data;
	tmp = list->next;
	while (tmp)
	{
		cmp == tmp->data ? ps_error(1) : 0;
		tmp = tmp->next;
	}
	if (list->next == NULL)
		return ;
	else
		validate(list->next);
}

void		checker(t_stack *list)
{
	int		tmp;

	tmp = list->data;
	while (list)
	{
		if (!(tmp >= list->data))
		{
			ft_printf("KO\n");
			return ;
		}		
		list = list->next;
	}
	ft_printf("OK\n");
}

int							main(int ar, char **av)
{
	int				i;
	t_stack			*list;

	i = 0;
	list = NULL;
	while (++i < ar)
	{
		list_push_back(&list, ft_atoi(av[i]), av[i]);
	}
	(ar > 2) ? validate(list) : 0;


	




	t_stack *tmp;							//debug
	tmp = list;
	i = 0;
	ft_printf("   stack A | stack B \n");
	ft_printf("-----------|---------\n");
	while (tmp)
	{
		ft_printf("% -11d|\n", tmp->data);
		tmp = tmp->next;
		i++;
	}
	checker(list);
	return (0);
}
