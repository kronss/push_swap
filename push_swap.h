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
*/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdlib.h> //dell
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"




typedef struct			s_stack
{
	int					data;
	struct	s_stack		*next;
}						t_stack;

// typedef struct	s_stack_b
// {
// 	int					b;
// 	struct	s_stack_a	next;
// 	struct	s_stack_a	prev;
// }						t_stack_b;







void				list_push_back(t_stack **begin_list, int a, char *str);
// void				list_push_front(t_stack **begin_list, int a);
void				ps_error(char i);
void				print_stacks(t_stack *tmp, t_stack *stack_b);


void				make_sa(t_stack **head);
void				make_sb(t_stack **head);
void				make_ss(t_stack **stack_a, t_stack **stack_b);
void				make_pb(t_stack **stack_a, t_stack **stack_b);
void				make_pa(t_stack **stack_a, t_stack **stack_b);
void				make_ra(t_stack **head);
void				make_rb(t_stack **head);
void				make_rr(t_stack **stack_a, t_stack **stack_b);
#endif
