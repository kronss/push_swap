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
	int 				p;
	struct	s_stack		*next;
}						t_stack;

typedef struct			s_oper
{
	char				*data;
	struct	s_oper		*next;
}						t_oper;


typedef struct			s_block
{
	char				debug;
	char				color;
	char				file;
	int					max_size;
	int 				pivot_i;
	int 				rra;
	t_oper				*oper; 

}						t_block;





/* ===== general ====== */
void				list_push_back(t_stack **begin_list, long a, char *str);
// void				list_push_front(t_stack **begin_list, int a);
void				ps_error(char i);

void				pre_validate(t_stack *stack_a, t_block *block);
int					read_flags(t_block *block, char **av, int ar);
void				init_var(t_block *b, t_stack **s_a, t_stack **s_b);


/* === push_swap ================== */
void				frst_sort_3_elem_a(t_stack **stack_a, t_stack **stack_b, t_block *block);
void				next_sort_3_elem_a(t_stack **stack_a, t_stack **stack_b, t_block *block);
void				last_sort_3_elem_b(t_stack **stack_a, t_stack **stack_b, t_block *block);
void				next_sort_3_elem_b(t_stack **stack_a, t_stack **stack_b, t_block *block);

char				check_ss(t_stack *stack_b, t_block *block);
char				check_rr_or_rrr(t_stack *stack_b, t_block *block);

void			push_from_a(t_stack **stack_a, t_stack **stack_b, int *arr, t_block *block);
void			push_from_b(t_stack **stack_a, t_stack **stack_b, int *arr, t_block *block);
int 			find_pivot(t_stack *stack_a, int max_size);
void			sort_2_elem_a(t_stack **stack_a, t_stack **stack_b, t_block *block);
void			sort_2_elem_b(t_stack **stack_a, t_stack **stack_b, t_block *block);
void			recursion_a(t_stack **stack_a, t_stack **stack_b, t_block *block, int max_size);
void			recursion_b(t_stack **stack_a, t_stack **stack_b, t_block *block, int max_size);
char			find_rem_a(t_stack *stack_a, int pivot);
char			find_rem_b(t_stack *stack_b, int pivot);
int				find_pivot(t_stack *stack_a, int max_size);
int 			linked_list_len(t_stack *tmp);

void 			operation_push_back(t_oper *oper, char *str);
/*==== checker =====================*/
void				reading_commands(t_stack **stack_a, t_stack **stack_b, t_block *block);

/*=== operartion and dispalay =======*/
void		make_sa(t_stack **stack_a, t_stack **stack_b, char c, t_block *block);	//	1
void		make_sb(t_stack **stack_a, t_stack **stack_b, char c, t_block *block);	//	2
void		make_ss(t_stack **stack_a, t_stack **stack_b, char c, t_block *block);	//	3
void		make_pa(t_stack **stack_a, t_stack **stack_b, char c, t_block *block);	//	4
void		make_pb(t_stack **stack_a, t_stack **stack_b, char c, t_block *block);	//	5
void		make_ra(t_stack **stack_a, t_stack **stack_b, char c, t_block *block);	//	6
void		make_rb(t_stack **stack_a, t_stack **stack_b, char c, t_block *block);	//	7
void		make_rr(t_stack **stack_a, t_stack **stack_b, char c, t_block *block);	//	8
void		make_rra(t_stack **stack_a, t_stack **stack_b, char c, t_block *block);	//	9
void		make_rrb(t_stack **stack_a, t_stack **stack_b, char c, t_block *block);	//	10
void		make_rrr(t_stack **stack_a, t_stack **stack_b, char c, t_block *block);	//	11
int			print_stacks(t_stack *stack_a, t_stack *stack_b);


#endif
