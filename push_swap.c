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

static	void				validate(t_stack *stack_a)
{
	t_stack 		*tmp;
	int				cmp;

	cmp = stack_a->data;
	tmp = stack_a->next;
	while (tmp)
	{
		cmp == tmp->data ? ps_error(1) : 0;
		tmp = tmp->next;
	}
	if (stack_a->next == NULL)
		return ;
	else
		validate(stack_a->next);
}



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
	make_sa(&stack_a);
	print_stacks(stack_a, stack_b);
	make_pb(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	make_pb(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	make_pb(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	make_pa(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	make_pa(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	make_pa(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	make_pa(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);


	// make_ra(&stack_a);
	// print_stacks(stack_a, stack_b);
	// make_ss(&stack_a, &stack_b);
	// print_stacks(stack_a, stack_b);
	

	// sleep(500);
	return (0);
}
