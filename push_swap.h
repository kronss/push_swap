/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:56:28 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/16 17:56:30 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	write
**	read
**	malloc
**	free
**	exit
**
**	
**
**
**
*/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdlib.h> //dell
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

// # define ft_printf printf;
// # define STDIN 0

typedef struct			s_stack
{
	int					data;
	struct	s_stack		*next;
}						t_stack;

typedef struct			s_operat
{
	int					data;
	struct	s_operat	*next;
}						t_operat;







void					list_push_back(t_stack **begin_list, int a, char *str);
// void					list_push_front(t_stack **begin_list, int a);
void					ps_error(char i);
void					print_stacks(t_stack *tmp, t_stack *stack_b);
void					validate(t_stack *stack_a);

void					make_sa(t_stack **head);						//	1
void					make_sb(t_stack **head);						//	2
void					make_ss(t_stack **stack_a, t_stack **stack_b);	//	3
void					make_pa(t_stack **stack_a, t_stack **stack_b);	//	4
void					make_pb(t_stack **stack_a, t_stack **stack_b);	//	5
void					make_ra(t_stack **head);						//	6
void					make_rb(t_stack **head);						//	7
void					make_rr(t_stack **stack_a, t_stack **stack_b);	//	8
void					make_rra(t_stack **head);						//	9
void					make_rrb(t_stack **head);						//	10
void					make_rrr(t_stack **stack_a, t_stack **stack_b);	//	11




#endif
