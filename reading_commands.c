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

static	int	choose_operation(char *line)
{
	if (!ft_strcmp(line, "sa"))
		return (1);
	else if (!ft_strcmp(line, "sb"))
		return (2);
	else if (!ft_strcmp(line, "ss"))
		return (3);
	else if (!ft_strcmp(line, "pa"))
		return (4);
	else if (!ft_strcmp(line, "pb"))
		return (5);
	else if (!ft_strcmp(line, "ra"))
		return (6);
	else if (!ft_strcmp(line, "rb"))
		return (7);
	else if (!ft_strcmp(line, "rr"))
		return (8);
	else if (!ft_strcmp(line, "rra"))
		return (9);
	else if (!ft_strcmp(line, "rrb"))
		return (10);
	else if (!ft_strcmp(line, "rrr"))
		return (11);
	// else if (!ft_strcmp(line, "")) //bonus
	// 	return (0);
	return (-1);
}

static	void	make_operation(int cmd, t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	cmd == 1 ? make_sa(stack_a, stack_b, 0, block) : 0;
	cmd == 2 ? make_sb(stack_a, stack_b, 0, block) : 0;
	cmd == 3 ? make_ss(stack_a, stack_b, 0, block) : 0;
	cmd == 4 ? make_pa(stack_a, stack_b, 0, block) : 0;
	cmd == 5 ? make_pb(stack_a, stack_b, 0, block) : 0;
	cmd == 6 ? make_ra(stack_a, stack_b, 0, block) : 0;
	cmd == 7 ? make_rb(stack_a, stack_b, 0, block) : 0;
	cmd == 8 ? make_rr(stack_a, stack_b, 0, block) : 0;
	cmd == 9 ? make_rra(stack_a, stack_b, 0, block) : 0;
	cmd == 10 ? make_rrb(stack_a, stack_b, 0, block) : 0;
	cmd == 11 ? make_rrr(stack_a, stack_b, 0, block) : 0;
}

void			reading_commands(t_stack **stack_a, t_stack **stack_b, t_block *block)
{
	char		*line;
	int 		cmd;

	while ((get_next_line(STDIN, &line)) > 0)
	{
		cmd = choose_operation(line);
		if (cmd > 0)
		{
			make_operation(cmd, stack_a, stack_b, block);
		}
		else
			ps_error(4);
	}
	ft_strdel(&line);
}
