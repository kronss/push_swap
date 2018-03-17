/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_is_double_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 12:44:19 by ochayche          #+#    #+#             */
/*   Updated: 2018/03/17 12:44:25 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		compare_ss(char *str1, char *str2)
{
	if (!ft_strcmp(str1, "sa"))
		if (!ft_strcmp(str2, "sb"))
			return (1);
	if (!ft_strcmp(str1, "sb"))
		if (!ft_strcmp(str2, "sa"))
			return (1);
	return (0);
}

static int		compare_rr(char *str1, char *str2)
{
	if (!ft_strcmp(str1, "ra"))
		if (!ft_strcmp(str2, "rb"))
			return (1);
	if (!ft_strcmp(str1, "rb"))
		if (!ft_strcmp(str2, "ra"))
			return (1);
	return (0);
}
	 
static int		compare_rrr(char *str1, char *str2)
{
	if (!ft_strcmp(str1, "rra"))
		if (!ft_strcmp(str2, "rrb"))
			return (1);
	if (!ft_strcmp(str1, "rrb"))
		if (!ft_strcmp(str2, "rra"))
			return (1);
	return (0);
}

static void		merge_two_nodes(t_oper *curr, char *str)
{
	t_oper		*del;

	del = curr->next;
	curr->next = curr->next->next;
	curr->next->data = str;
	ft_memdel((void **)&del);
}

int				opt_is_double_node(t_oper **oper)
{
	t_oper		*curr;
	int			res;

	curr = *oper;
	res = FALSE;
	while (curr && curr->next && curr->next->next)
	{
		if (compare_ss(curr->next->data, curr->next->next->data))
		{
			// ft_printf("ss %s , %s\n", curr->next->data, curr->next->next->data);
			merge_two_nodes(curr, "ss");
			res = TRUE;
			// ft_printf("-- %s , %s\n", curr->next->data, curr->next->next->data);
			// sleep(3);
		}
		// else if (compare_rr(curr->next->data, curr->next->next->data))
 	// 	{
		// 	ft_printf("rr %s , %s\n", curr->next->data, curr->next->next->data);
 	// 		merge_two_nodes(curr, "rr");
 	// 		res = TRUE;
		// 	ft_printf("-- %s , %s\n", curr->next->data, curr->next->next->data);
		// 	sleep(3);
 	// 	}
 	// 	else if (compare_rrr(curr->next->data, curr->next->next->data))
 	// 	{
 	// 		merge_two_nodes(curr, "rrr");
 	// 		res = TRUE;
 	// 	}
 		curr = curr->next;
	}
	return (res);
}
