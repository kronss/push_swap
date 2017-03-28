/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:33:45 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/27 20:33:46 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int		compare(char *str1, char *str2)
{
	if (!strcmp(str1, "pa"))
	{
		if (!strcmp(str2, "pb"))
			return (1);
	}
	if (!strcmp(str1, "pb"))
	{
		if (!strcmp(str2, "pa"))
			return (1);
	}
	if (!strcmp(str1, "rra"))
	{
		if (!strcmp(str2, "ra"))
			return (1);
	}
	if (!strcmp(str1, "ra"))
	{
		if (!strcmp(str2, "rra"))
			return (1);
	}
	if (!strcmp(str1, "rb"))
	{
		if (!strcmp(str2, "rrb"))
			return (1);
	}
	if (!strcmp(str1, "rrb"))
	{
		if (!strcmp(str2, "rb"))
			return (1);
	}
	return (0);
}

int	optimization(t_block *block, t_oper **oper)
{
	t_oper *tmp;
	t_oper *tmp2;

	tmp = (*oper);
	// printf("=========optimization=========\n");
	while (tmp->next && tmp->next->next)
	{
		if (compare(tmp->next->data, tmp->next->next->data))
		{
			tmp2 = tmp->next->next->next;
			// free(tmp->next);
			// free(tmp->next->next);
			tmp->next = tmp2;
			return (1);
		}
		tmp = tmp->next;

	}



	tmp = (*oper);
	while (tmp)
	{
		printf("%s\n",tmp->data);		
		tmp = tmp->next;
	}
	return (0);
}
