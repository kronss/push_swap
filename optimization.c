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


void	compare(t_oper *oper)
{


}

int	optimization(t_block *block, t_oper **oper)
{
	t_oper *tmp;

	tmp = (*oper);
	printf("==================\n");
	if (tmp && tmp->next)
	{
		printf("--\n");
		while (tmp && tmp->next)
		{
			printf("%s\n", tmp->data);
			tmp = tmp->next;
		}
	}
	return (0);
}
