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

// static	void	ft_usage_checker(void)
// {
// 	ft_printf("usage:\n");
// 	ft_printf("[sa]:\nswap the first 2 elements at the top of stack A\n");
// 	ft_printf("[sb]:\nswap the first 2 elements at the top of stack B\n");
// 	ft_printf("[ss]:\nsa and sb at the same time\n");
// 	ft_printf("[pa]:\ntake the first element at the top of B and put it at the top of A\n");
// 	ft_printf("[pb]:\ntake the first element at the top of A and put it at the top of B\n");
// 	ft_printf("[ra]:\nrotate A - shift up all elements of stack a by 1. The first element becomes the last one.\n");
// 	ft_printf("[rb]:\nrotate B - shift up all elements of stack b by 1. The first element becomes the last one.\n");
// 	ft_printf("[rr]:\nra and rb at the same time.\n");
// 	ft_printf("[rra]:\nreverse rotate A - shift down all elements of stack A by 1. The last element becomes the first one.\n");
// 	ft_printf("[rrb]:\nreverse rotate B - shift down all elements of stack B by 1. The last element becomes the first one.\n");
// 	ft_printf("[rrr]:\nrra and rrb at the same time.\n");
// }

static	char	choose_operation(char *line)
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

static	void	make_operation(char cmd, t_stack **stack_a, t_stack **stack_b)
{
	cmd == 1 ? make_sa(stack_a, 0) : 0;
	cmd == 2 ? make_sb(stack_b, 0) : 0;
	cmd == 3 ? make_ss(stack_a, stack_b, 0) : 0;
	cmd == 4 ? make_pa(stack_a, stack_b, 0) : 0;
	cmd == 5 ? make_pb(stack_a, stack_b, 0) : 0;
	cmd == 6 ? make_ra(stack_a, 0) : 0;
	cmd == 7 ? make_rb(stack_b, 0) : 0;
	cmd == 8 ? make_rr(stack_a, stack_b, 0) : 0;
	cmd == 9 ? make_rra(stack_a, 0) : 0;
	cmd == 10 ? make_rrb(stack_b, 0) : 0;
	cmd == 11 ? make_rrr(stack_a, stack_b, 0) : 0;
}

void			reading_commands(t_stack **stack_a, t_stack **stack_b)
{
	char		*line;
	char 		cmd;

	while ((get_next_line(STDIN, &line)) > 0)
	{
		ft_strlowcase(line);
		cmd = choose_operation(line);
		if (cmd > 0)
		{
			make_operation(cmd, stack_a, stack_b);
			print_stacks(*stack_a, *stack_b);
		}
		// else if (cmd == -1) //for bonus
			// ft_usage_checker();
		//else if (!cmp && ) // bonus
		else
			ps_error(4);
	}
	ft_strdel(&line);
}
