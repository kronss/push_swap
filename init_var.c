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



void 		init_tmp_var(t_block *b, t_block *tmp_block)
{
	tmp_block->debug = b->debug;
	tmp_block->file = b->file;
	tmp_block->color = b->color;
	tmp_block->max_size = b->max_size;
	tmp_block->oper = b->oper;
	tmp_block->pivot_i = b->pivot_i;


	tmp_block->size_a = 0;
	tmp_block->size_b = 0;
}


void		init_var(t_block *b, t_stack **s_a, t_stack **s_b)
{
	*s_a = NULL;
	*s_b = NULL;

	b->debug = 0;
	b->file = 0;
	b->color = 0;
	b->max_size = 1;
	b->oper = NULL;
	b->pivot_i = 0;

	b->size_a = 0;
	b->size_b = 0;
}
