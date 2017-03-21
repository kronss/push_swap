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

int				look_mediana(t_stack *stack_a, int min, int max)
{
	t_stack *tmp;
	int pvt;
	int tmp_pvt;

	tmp = stack_a;
	while (tmp)
	{
		tmp->data > max ? max = tmp->data : 0;
		tmp->data < min ? min = tmp->data : 0;
		tmp = tmp->next;
	}
	tmp_pvt = (max + min) / 2;
	ft_printf("min = %d\n", min);
	ft_printf("max = %d\n", max);
	// tmp = stack_a;
	ft_printf("mediana = %d\n", tmp_pvt);

	return (tmp_pvt);
}


int								main(int ar, char **av)
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
	pre_validate(stack_a, &block.size);
	ft_printf("size %u\n", block.size);
	/*=====================================================*/
	print_stacks(stack_a, stack_b); //bonus
	look_mediana(stack_a, stack_a->data, stack_a->next->data);


	return (0);
}
