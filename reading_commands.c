/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:51:18 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/20 15:51:18 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	choose_operation(t_stack **stack_a, t_stack **stack_b,
													t_block *block, char *line)
{
	if (!ft_strcmp(line, "sa"))
		return (make_sa(stack_a, stack_b, 0, block));
	else if (!ft_strcmp(line, "sb"))
		return (make_sb(stack_a, stack_b, 0, block));
	else if (!ft_strcmp(line, "ss"))
		return (make_ss(stack_a, stack_b, 0, block));
	else if (!ft_strcmp(line, "pa"))
		return (make_pa(stack_a, stack_b, 0, block));
	else if (!ft_strcmp(line, "pb"))
		return (make_pb(stack_a, stack_b, 0, block));
	else if (!ft_strcmp(line, "ra"))
		return (make_ra(stack_a, stack_b, 0, block));
	else if (!ft_strcmp(line, "rb"))
		return (make_rb(stack_a, stack_b, 0, block));
	else if (!ft_strcmp(line, "rr"))
		return (make_rr(stack_a, stack_b, 0, block));
	else if (!ft_strcmp(line, "rra"))
		return (make_rra(stack_a, stack_b, 0, block));
	else if (!ft_strcmp(line, "rrb"))
		return (make_rrb(stack_a, stack_b, 0, block));
	else if (!ft_strcmp(line, "rrr"))
		return (make_rrr(stack_a, stack_b, 0, block));
	else
		return (ps_error(4));
}

void			reading_commands(t_stack **stack_a, t_stack **stack_b,
															t_block *block)
{
	char		*line;

	while ((get_next_line(STDIN, &line)) > 0)
		choose_operation(stack_a, stack_b, block, line);
	ft_strdel(&line);
}
