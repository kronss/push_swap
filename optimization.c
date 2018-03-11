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

static inline void					dellete_two_nodes(t_oper *curr)
{
	t_oper *del1;
	t_oper *del2;

	del1 = curr->next;
	del2 = curr->next->next;
	curr->next = curr->next->next->next;
	ft_memdel((void **)&del2);
	ft_memdel((void **)&del1);
}

static  int		compare(char *str1, char *str2)
{
	// printf("str1 == %s\nstr2 == %s\n", str1, str2);


	if (!ft_strcmp(str1, "pb"))
		if (!ft_strcmp(str2, "pa"))
			return (1);
	if (!ft_strcmp(str1, "pa"))
		if (!ft_strcmp(str2, "pb"))
			return (1);
	if (!ft_strcmp(str1, "rra"))
		if (!ft_strcmp(str2, "ra"))
			return (1);
	if (!ft_strcmp(str1, "ra"))
		if (!ft_strcmp(str2, "rra"))
			return (1);
	if (!ft_strcmp(str1, "rb"))
		if (!ft_strcmp(str2, "rrb"))
			return (1);
	if (!ft_strcmp(str1, "rrb"))
		if (!ft_strcmp(str2, "rb"))
			return (1);
	if (!ft_strcmp(str1, "sa"))
		if (!ft_strcmp(str2, "sa"))
			return (1);
	if (!ft_strcmp(str1, "sb"))
		if (!ft_strcmp(str2, "sb"))
			return (1);
	return (0);
}



// int optimization_del(t_actions **op)
// {
// 	t_actions *cur;
// 	t_actions *head;
// 	int len;

// 	head = *op;
// 	len = count_operations(*op);
// 	while (*op)
// 	{
// 		cur = (*op)->next;
// 		if (!cur || !cur->next)
// 			break;
// 		if ((!ft_strcmp(cur->action, "ra") && !ft_strcmp(cur->next->action, "rra")) ||
// 			(!ft_strcmp(cur->action, "rb") && !ft_strcmp(cur->next->action, "rrb")) ||
// 			(!ft_strcmp(cur->action, "rra") && !ft_strcmp(cur->next->action, "ra")) ||
// 			(!ft_strcmp(cur->action, "rrb") && !ft_strcmp(cur->next->action, "rb")) ||
// 			(!ft_strcmp(cur->action, "sa") && !ft_strcmp(cur->next->action, "sa")) ||
// 			(!ft_strcmp(cur->action, "sb") && !ft_strcmp(cur->next->action, "sb")) ||
// 			(!ft_strcmp(cur->action, "pa") && !ft_strcmp(cur->next->action, "pb")) ||
// 			(!ft_strcmp(cur->action, "pb") && !ft_strcmp(cur->next->action, "pa")))
// 			del_two_elements(op);
// 		*op = (*op)->next;
// 	}
// 	*op = head;
// 	return (len - count_operations(*op));
// }


static int	opt_is_have_anti_oper(t_oper *oper)
{
	t_oper *curr;
	int res;

	curr = oper;
	res = FALSE;
	while (curr && curr->next && curr->next->next)
	{
		// printf("=======\n");
		if (compare(curr->next->data, curr->next->next->data))
		{
			dellete_two_nodes(curr);
			res = TRUE;
		}

		curr = curr->next;
	}

	// printf("res ====== %d\n", res);
	return res;
}


void		optimization(t_block *block)
{
	int is_running;


	is_running = TRUE;
	while (is_running)
	{
		is_running = FALSE;
		is_running = opt_is_have_anti_oper(block->oper);



	}
}
