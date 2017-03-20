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

static	void				checker(t_stack *stack_a, t_stack *stack_b)
{
	int		tmp;

	tmp = stack_a->data;
	if (stack_a)
	{
		while (stack_a)
		{
			// ft_printf("cheker %d\n", tmp);
			if (tmp > stack_a->data)
			{
				ft_printf("KO\n");
				return ;
			}
			tmp = stack_a->data;
			stack_a = stack_a->next;
		}
	}
	if (!stack_b && !stack_a)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}


char	read_command_line(char **line, t_stack **stack_a, t_stack **stack_b)
{
	ft_strlowcase(*line);
	return (1);
}

int							main(int ar, char **av)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	// t_operat		*operation;
	int				i;
	char 			*line;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	while (++i < ar)
	{
		list_push_back(&stack_a, ft_atoi(av[i]), av[i]);
	}
	(ar > 2) ? validate(stack_a) : exit(0);

	// read(int fildes, void *line, size_t nbyte);
	print_stacks(stack_a, stack_b);
	while ((get_next_line(STDIN, &line)) > 0)
	{
		ft_strlowcase(line);
		// read_command_line(&line, &stack_a, &stack_b);
		// ft_printf("line: [%s]\nstrlen line [%d]\n", line, ft_strlen(line));
	}
	
// ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

	
	make_ra(&stack_a);
	print_stacks(stack_a, stack_b);
	make_ra(&stack_a);
	print_stacks(stack_a, stack_b);
	make_pb(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	make_pb(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	make_ss(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	make_pa(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	make_pa(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	// make_sa(&stack_a);
	// print_stacks(stack_a, stack_b);
	checker(stack_a, stack_b);
	return (0);
}
