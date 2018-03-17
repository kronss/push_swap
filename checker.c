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

static void		checker(t_stack **stack_a, t_stack **stack_b)
{
	int			prev_value;
	t_stack		*curr;

	if (!(*stack_a) || *stack_b)
	{
		ft_printf("KO\n");
		return ;
	}
	curr = *stack_a;
	prev_value = curr->data;
	if (curr)
	{
		while (curr)
		{
			if (prev_value > curr->data)
			{
				ft_printf("KO\n");
				return ;
			}
			prev_value = curr->data;
			curr = curr->next;
		}
	}
	ft_printf("OK\n");
}

int				main(int ar, char **av)
{
	t_block		block;
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			i;

	init_var(&block, &stack_a, &stack_b);
	i = read_flags(&block, av, ar, CHECKER);
	while (i < ar)
	{
		list_push_back(&stack_a, ft_atol(av[i]), av[i]);
		i++;
	}
	pre_validate(stack_a, &block);
	reading_commands(&stack_a, &stack_b, &block);
	checker(&stack_a, &stack_b);
	free_memory(&stack_a, &stack_b, &block);
	return (0);
}
