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


static t_stack		*create_elem(int a)
{
	t_stack			*new;
	if (!(new = malloc(sizeof(t_stack *))))
		return (NULL);
	new->a = a;
	new->next = NULL;
	return (new);
}

// void				list_push_back(t_stack **begin_list, int a)
// {
// 	t_stack			*list;

// 	list = *begin_list;
// 	if (list)
// 	{
// 		while (list->next)
// 			list = list->next;
// 		list->next = create_elem(a);
// 	}
// 	else
// 		*begin_list = create_elem(a);
// }

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


// static	void				validate(t_stack *list)
// {
// 	t_stack 		*tmp;
// 	int				cmp;

// 	cmp = list->a;
// 	tmp = list->next;
// 	while (tmp)
// 	{
// 		cmp == tmp->a ? ps_error(1) : 0;
// 		tmp = tmp->next;
// 	}
// 	if (list->next == NULL)
// 		return ;
// 	else
// 		validate(list->next);
// }


void		checker(t_stack *list)
{
	// ft_printf("dick\n" );
	int		tmp;

	tmp = list->a;
	while (list)
	{
		if (!(tmp >= list->a))
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
		list_push_front(&list, ft_atoi(av[i]));
	}
	// (ar > 2) ? validate(list) : 0;


	checker(list);




	t_stack *tmp;							//debug
	tmp = list;
	while (tmp)
	{
		ft_printf("[%d]\n", tmp->a);
		tmp = tmp->next;
		i++;
	}

	return (0);
}
