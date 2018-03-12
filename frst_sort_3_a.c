/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frst_sort_3_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:12:14 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/22 21:12:15 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_biger_then_b(t_stack **stk_a, t_stack **stk_b, t_block *block)
{
	if ((*stk_a)->next->data < (*stk_a)->next->next->data)
	{
		if ((*stk_a)->data < (*stk_a)->next->next->data)
		{
			make_sa(stk_a, stk_b, 1, block);
		}
		else if ((*stk_a)->data > (*stk_a)->next->next->data)
			make_ra(stk_a, stk_b, 1, block);
	}
	else
	{
		make_sa(stk_a, stk_b, 1, block);
		make_rra(stk_a, stk_b, 1, block);
	}
}

static void	a_less_then_b(t_stack **stk_a, t_stack **stk_b, t_block *block)
{
	if ((*stk_a)->next->data > (*stk_a)->next->next->data)
	{
		if ((*stk_a)->data < (*stk_a)->next->next->data)
		{
			make_rra(stk_a, stk_b, 1, block);
			make_sa(stk_a, stk_b, 1, block);
		}
		else if ((*stk_a)->data > (*stk_a)->next->next->data)
			make_rra(stk_a, stk_b, 1, block);
	}
}

/*
** 
**
**
*/
void		frst_sort_3_a(t_stack **stk_a, t_stack **stk_b, t_block *block)
{
	if ((*stk_a)->data < (*stk_a)->next->data)
		a_less_then_b(stk_a, stk_b, block);
	else if ((*stk_a)->data > (*stk_a)->next->data)
		a_biger_then_b(stk_a, stk_b, block);
}
