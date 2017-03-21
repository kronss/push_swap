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

int							look_mediana(stack_a, stack_b, int min, int max)
{
	int pvt;

	while (stack_a)
	{
		stack_a->data > max
		

	}

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
		list_push_back(&stack_a, ft_atol(av[i]), av[i]);
	}
	pre_validate(stack_a);
	/*=====================================================*/
	print_stacks(stack_a, stack_b); //bonus
	look_mediana(stack_a, stack_b, stack_a->data, stack_a->data);

	return (0);
}
