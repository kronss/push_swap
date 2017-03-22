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

static	void	checker(t_stack *stack_a, t_stack *stack_b)
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

int				main(int ar, char **av)
{
	t_block			block;
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				i;

	init_var(&block, &stack_a, &stack_b);
	i = read_flags(&block, av, ar);
	while (i < ar)
	{
		list_push_back(&stack_a, ft_atol(av[i]), av[i]);
		i++;
	}
	pre_validate(stack_a, &block);
	/*========================================*/
	print_stacks(stack_a, stack_b); //bonus
	reading_commands(&stack_a, &stack_b);
	checker(stack_a, stack_b);
	return (0);
}
