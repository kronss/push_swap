/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:56:28 by ochayche          #+#    #+#             */
/*   Updated: 2018/03/17 15:56:49 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

# define TRUE  1
# define FALSE 0
# define CHECKER 1
# define PUSH_SWAP 2

/*
** PSHD  == pushed count
** PIVOT == pivot
** ROTAT == rotate count
*/

typedef unsigned int	t_uint;

enum	e_enum
{
	PSHD = 0,
	PIVOT,
	SIZE,
	ROTAT,
	MAX_VAR
};

typedef struct		s_stack
{
	int				data;
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
	t_stack			*copy_a;

	t_uint			size_a;
	t_uint			size_b;
	t_uint			max_a_operation;
	t_uint			max_b_operation;
	int				program;
}					t_block;

void				list_push_back(t_stack **begin_list, long a, char *str);
int					ps_error(char i);
void				pre_validate(t_stack *s_a, t_block *bk);
int					read_flags(t_block *bk, char **av, int ar, int program);
void				init_var(t_block *b, t_stack **s_a, t_stack **s_b);
void				frst_sort_3_a(t_stack **s_a, t_stack **s_b, t_block *bk);
void				next_sort_3_a(t_stack **s_a, t_stack **s_b, t_block *bk);
void				last_sort_3_b(t_stack **s_a, t_stack **s_b, t_block *bk);
void				next_sort_3_b(t_stack **s_a, t_stack **s_b, t_block *bk);
char				check_ss(t_stack *s_b, t_block *bk);
char				check_rr_or_rrr(t_stack *s_b, t_block *bk);
int					find_pivot(t_stack *tmp, int max_size);
void				sort_2_elem_a(t_stack **s_a, t_stack **s_b, t_block *bk);
void				sort_2_elem_b(t_stack **s_a, t_stack **s_b, t_block *bk);
void				recn_a(t_stack **s_a, t_stack **s_b, t_block *bk, int cnt);
void				recn_b(t_stack **s_a, t_stack **s_b, t_block *bk, int cnt);
int					rem_less_then_pivot(t_stack *curr, int pivot, int max);
int					rem_more_then_pivot(t_stack *curr, int pivot, int max);
int					linked_list_len(t_stack *tmp);
void				optimization(t_block *bk);
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
int					is_sorted(t_stack *curr);
void				sort_3_elem_a(t_stack **stack_a, t_stack **stack_b,
												t_block *block, int cnt);
void				sort_3_elem_b(t_stack **stack_a, t_stack **stack_b,
												t_block *block, int max_size);
t_stack				*create_elem(int a);
void				create_dirty_copy_a(t_stack *stack_a, t_block *block);
void				optimization(t_block *block);
void				print_operation(t_stack **copy_a, t_stack **stack_b,
																t_block *block);
void				free_memory(t_stack **stack_a, t_stack **stack_b,
																t_block *block);
int					opt_is_have_anti_oper(t_oper **oper);
int					opt_is_double_node(t_oper **oper);

#endif
