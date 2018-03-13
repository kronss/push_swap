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

static void	two_to_three(t_oper *curr, char *s1, char *s2)
{
	t_oper	*del;

	del = curr->next;
	curr->next = curr->next->next;
	curr->next->data = s1;
	curr->next->next->data = s2;
	ft_memdel((void **)&del);
}

int			opt_is_extra_oper(t_oper *oper)
{
	t_oper	*curr;
	int		res;

	curr = oper;
	res = FALSE;
	while (curr && curr->next && curr->next->next)
	{
		if (!ft_strcmp(curr->data, "ra") && 
			!ft_strcmp(curr->next->data, "pb") &&
			!ft_strcmp(curr->next->next->data, "rra"))
		{
			two_to_three(curr, "sa", "pb");
		}
		else if (!ft_strcmp(curr->data, "rb") &&
				 !ft_strcmp(curr->next->data, "pa") &&
				 !ft_strcmp(curr->next->next->data, "rrb"))
		{
			two_to_three(curr, "sb", "pa");
		}
		curr = curr->next;
	}
	return (res);
}

void		optimization(t_block *block)
{
	int is_running;

	is_running = TRUE;
	while (is_running)
	{
		is_running = FALSE;
		is_running = opt_is_have_anti_oper(block->oper) ? TRUE : is_running;
		is_running = opt_is_double_node(block->oper) ? TRUE : is_running;
		// is_running = opt_is_extra_oper(block->oper) ? TRUE : is_running;       //RECODE AND CHECK
	}
}
