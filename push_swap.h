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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
// # include "ft_printf/ft_printf.h"
#include <stdio.h>

# define ft_printf printf

# define TRUE 1l
# define FALSE 0l

typedef struct		s_stack
{
	int				data;
	int				p;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_oper
{
	char			*data;
	struct s_oper	*next;
}					t_oper;

typedef struct		s_block
{
	char			debug;
	char			color;
	char			file;
	int				max_size;
	int				pivot_i;
	int				rra;
	t_oper			*oper;
	int				(*is_a_sort)(t_stack *);
	int				(*is_b_empty)(t_stack *);	
}					t_block;


t_block			g_block;
t_stack			*g_stack_head_a;
t_stack			*g_stack_head_b;

void				list_push_back(long a, char *str);
void				ps_error(char i);
void				pre_validate();
int					read_flags(char **av, int ar);
void				init_g_var();
void				frst_sort_3_a(t_stack **s_a, t_stack **s_b, t_block *bk);
void				next_sort_3_a(t_stack **s_a, t_stack **s_b, t_block *bk);
void				last_sort_3_b(t_stack **s_a, t_stack **s_b, t_block *bk);
void				next_sort_3_b(t_stack **s_a, t_stack **s_b, t_block *bk);
char				check_ss(t_stack *s_b, t_block *bk);
char				check_rr_or_rrr(t_stack *s_b, t_block *bk);
int					find_pivot(t_stack *s_a, int max_size);
void				sort_2_elem_a(t_stack **s_a, t_stack **s_b, t_block *bk);
void				sort_2_elem_b(t_stack **s_a, t_stack **s_b, t_block *bk);
void				recn_a(t_stack **s_a, t_stack **s_b, t_block *bk, int p);
void				recn_b(t_stack **s_a, t_stack **s_b, t_block *bk, int p);
char				find_rem_a(t_stack *s_a, int pivot, int push_a);
char				find_rem_b(t_stack *s_b, int pivot, int push_b);
int					find_pivot(t_stack *s_a, int max_size);
int					linked_list_len(t_stack *tmp);
int					optimization(t_block *bk, t_oper **oper);
void				operation_push_back(t_oper **oper, char *str);
void				reading_commands(t_stack **s_a, t_stack **s_b, t_block *bk);
void				make_sa(t_stack **s_a, t_stack **s_b, char c, t_block *bk);
void				make_sb(t_stack **s_a, t_stack **s_b, char c, t_block *bk);
void				make_ss(t_stack **s_a, t_stack **s_b, char c, t_block *bk);
void				make_pa(t_stack **s_a, t_stack **s_b, char c, t_block *bk);
void				make_pb(t_stack **s_a, t_stack **s_b, char c, t_block *bk);
void				make_ra(t_stack **s_a, t_stack **s_b, char c, t_block *bk);
void				make_rb(t_stack **s_a, t_stack **s_b, char c, t_block *bk);
void				make_rr(t_stack **s_a, t_stack **s_b, char c, t_block *bk);
void				make_rra(t_stack **s_a, t_stack **s_b, char c, t_block *bk);
void				make_rrb(t_stack **s_a, t_stack **s_b, char c, t_block *bk);
void				make_rrr(t_stack **s_a, t_stack **s_b, char c, t_block *bk);
int					print_stacks(t_stack *s_a, t_stack *s_b);
void				backtrack_stack_a(t_stack **stack_a, t_stack **stack_b,
													t_block *block, int rra);
void				backtrack_stack_b(t_stack **stack_a, t_stack **stack_b,
													t_block *block, int rrb);
#endif
