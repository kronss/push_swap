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

static	int		read_flags(t_block *block, char **av, int ar)
{
	int i;
	int j;

	i = 1;
	
	while (i < ar && av[i][0] == '-' && ft_strchr_f("vcf", av[i][1]))
	{
		j = 1;
		while (av[i][j] != '\0')
		{
			if (av[i][j] == 'v')
				block->debug = 1;
			else if (av[i][j] == 'c')
				block->color = 1;
			else if (av[i][j] == 'f')
				block->file = 1;
			j++;
		}
		i++;
	}
	// ft_printf("block->debug == %d\nblock->color == %d\nblock->file == %d\n", block->debug, block->color, block->file);
	return (i);
}

static	void		init_var(t_block *b, t_stack **s_a, t_stack **s_b)
{
	b->debug = 0;
	b->file = 0;
	b->color = 0;
	*s_a = NULL;
	*s_b = NULL;
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
	pre_validate(stack_a);
	/*========================================*/
	print_stacks(stack_a, stack_b); //bonus
	reading_commands(&stack_a, &stack_b);
	checker(stack_a, stack_b);
	return (0);
}
