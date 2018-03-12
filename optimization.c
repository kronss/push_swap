/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:33:45 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/27 20:33:46 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void					dellete_two_nodes(t_oper *curr)
{
	t_oper *del1;
	t_oper *del2;

	del1 = curr->next;
	del2 = curr->next->next;
	curr->next = curr->next->next->next;
	ft_memdel((void **)&del2);
	ft_memdel((void **)&del1);
}

static  int		compare_anti(char *str1, char *str2)
{
	if (!ft_strcmp(str1, "pb"))
		if (!ft_strcmp(str2, "pa"))
			return (1);
	if (!ft_strcmp(str1, "pa"))
		if (!ft_strcmp(str2, "pb"))
			return (1);
	if (!ft_strcmp(str1, "rra"))
		if (!ft_strcmp(str2, "ra"))
			return (1);
	if (!ft_strcmp(str1, "ra"))
		if (!ft_strcmp(str2, "rra"))
			return (1);
	if (!ft_strcmp(str1, "rb"))
		if (!ft_strcmp(str2, "rrb"))
			return (1);
	if (!ft_strcmp(str1, "rrb"))
		if (!ft_strcmp(str2, "rb"))
			return (1);
	if (!ft_strcmp(str1, "sa"))
		if (!ft_strcmp(str2, "sa"))
			return (1);
	if (!ft_strcmp(str1, "sb"))
		if (!ft_strcmp(str2, "sb"))
			return (1);
	return (0);
}


static int	opt_is_have_anti_oper(t_oper *oper)
{
	t_oper *curr;
	int res;

	curr = oper;
	res = FALSE;
	while (curr && curr->next && curr->next->next)
	{
		if (compare_anti(curr->next->data, curr->next->next->data))
		{
			dellete_two_nodes(curr);
			res = TRUE;
		}
		curr = curr->next;
	}
	return res;
}


static int compare_ss(char *str1, char *str2)
{
	if (!ft_strcmp(str1, "sa"))
		if (!ft_strcmp(str2, "sb"))
			return (1);
	if (!ft_strcmp(str1, "sb"))
		if (!ft_strcmp(str2, "sa"))
			return (1);
	return (0);
}

static int compare_rr(char *str1, char *str2)
{
	if (!ft_strcmp(str1, "ra"))
		if (!ft_strcmp(str2, "rb"))
			return (1);
	if (!ft_strcmp(str1, "rb"))
		if (!ft_strcmp(str2, "ra"))
			return (1);
	return (0);
}

static int compare_rrr(char *str1, char *str2)
{
	if (!ft_strcmp(str1, "rra"))
		if (!ft_strcmp(str2, "rrb"))
			return (1);
	if (!ft_strcmp(str1, "rrb"))
		if (!ft_strcmp(str2, "rra"))
			return (1);
	return (0);
}

static void merge_two_nodes(t_oper *curr, char *str)
{
	t_oper *del;

	del = curr->next;
	curr->next = curr->next->next;
	curr->next->data = str;
	ft_memdel((void **)&del);
}


static int optimization_merge(t_oper *oper)
{
	t_oper *curr;
	int res;

	curr = oper;
	res = FALSE;
	while (curr && curr->next && curr->next->next)
	{
		if (compare_ss(curr->next->data, curr->next->next->data))
		{
			merge_two_nodes(curr, "ss");
			res = TRUE;
		}
		else if (compare_rr(curr->next->data, curr->next->next->data))
		{
			merge_two_nodes(curr, "rr");
			res = TRUE;
		}
		else if (compare_rrr(curr->next->data, curr->next->next->data))
		{
			merge_two_nodes(curr, "rrr");
			res = TRUE;
		}
		curr = curr->next;
	}
	return res;
}





void		optimization(t_block *block)
{
	int is_running;


	is_running = TRUE;
	while (is_running)
	{
		is_running = FALSE;
		is_running = opt_is_have_anti_oper(block->oper) ? TRUE : is_running;
		is_running = optimization_merge(block->oper) ? TRUE : is_running;
		// is_running = opt_is_have_anti_oper(block->oper) ? TRUE : is_running;



	}
}
