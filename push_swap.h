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
	int					a;
	struct	s_stack		*next;
}						t_stack;

// typedef struct	s_stack_b
// {
// 	int					b;
// 	struct	s_stack_a	next;
// 	struct	s_stack_a	prev;
// }						t_stack_b;







void				list_push_back(t_stack **begin_list, int a);
void				list_push_front(t_stack **begin_list, int a);
void				ps_error(char i);

#endif
