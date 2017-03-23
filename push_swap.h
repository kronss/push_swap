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
# include <stdio.h> //dell
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

// # define ft_printf printf;
// # define STDIN 0

typedef struct			s_stack
{
	int					data;
	struct	s_stack		*next;
}						t_stack;

typedef struct			s_block
{
	char				debug;
	char				color;
	char				file;
	int					max_size;
	int 				curr_size_a;
	int 				curr_size_b;
	int 				pivot_i;

	// struct	s_stack		*stack_a;
	// struct	s_stack		*stack_b;
}						t_block;





/* ===== general ====== */
void				list_push_back(t_stack **begin_list, long a, char *str);
// void				list_push_front(t_stack **begin_list, int a);
void				ps_error(char i);
void				print_stacks(t_stack *tmp, t_stack *stack_b);
void				pre_validate(t_stack *stack_a, t_block *block);
int					read_flags(t_block *block, char **av, int ar);
void				init_var(t_block *b, t_stack **s_a, t_stack **s_b);

/* === push_swap ================== */


void				frst_sort_3_elem(t_stack **stack_a, t_stack **stack_b, t_block *block);
char				check_ss(t_stack *stack_b, t_block *block);

/*==== checker =====================*/

void				reading_commands(t_stack **stack_a, t_stack **stack_b);

/*=== operartion and dispalay =======*/
void				make_sa(t_stack **head, char c);				//	1
void				make_sb(t_stack **head, char c);				//	2
void				make_ss(t_stack **stack_a, t_stack **stack_b, char c);	//	3
void				make_pa(t_stack **stack_a, t_stack **stack_b, char c);	//	4
void				make_pb(t_stack **stack_a, t_stack **stack_b, char c);	//	5
void				make_ra(t_stack **head, char c);				//	6
void				make_rb(t_stack **head, char c);				//	7
void				make_rr(t_stack **stack_a, t_stack **stack_b, char c);	//	8
void				make_rra(t_stack **head, char c);						//	9
void				make_rrb(t_stack **head, char c);						//	10
void				make_rrr(t_stack **stack_a, t_stack **stack_b, char c);	//	11



#endif
