/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:39:09 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/17 20:39:10 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("–––––––––––––––––––––––\n");
	ft_printf("   stack A | stack B   \n");
	ft_printf("–––––––––––––––––––––––\n");
	while (stack_a || stack_b)
	{
		stack_a ? ft_printf("% -11d|", stack_a->data) : ft_printf("%12c", '|');
		stack_b ? ft_printf("% 11d\n", stack_b->data) : ft_printf("\n");
		stack_a ? stack_a = stack_a->next : 0;
		stack_b ? stack_b = stack_b->next : 0;
	}
	ft_printf("–––––––––––––––––––––––\n");
	// sleep(1);
	return (0);
}
