/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 21:16:13 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/21 21:16:14 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		init_var(t_block *b, t_stack **s_a, t_stack **s_b)
{
	b->debug = 0;
	b->file = 0;
	b->color = 0;
	b->max_size = 1;
	*s_a = NULL;
	*s_b = NULL;
	b->oper = NULL;
	b->pivot_i = 0;
}
