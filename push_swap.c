/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:55:02 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/16 17:55:02 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int							main(int ar, char **av)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				i;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	while (++i < ar)
	{
		list_push_back(&stack_a, ft_atoi(av[i]), av[i]);
	}
	(ar > 2) ? validate(stack_a) : 0;

	print_stacks(stack_a, stack_b);
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

	return (0);
}
