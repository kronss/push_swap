
#include "push_swap.h"


static int compare_ss(char *str1, char *str2)
{
	if (!ft_strcmp(str1, "sa"))
		if (!ft_strcmp(str2, "sb"))
			return (1);
	if (!ft_strcmp(str1, "sb"))
		if (!ft_strcmp(str2, "sa"))
			return (1);
	return (0);
}

static int compare_rr(char *str1, char *str2)
{
	if (!ft_strcmp(str1, "ra"))
		if (!ft_strcmp(str2, "rb"))
			return (1);
	if (!ft_strcmp(str1, "rb"))
		if (!ft_strcmp(str2, "ra"))
			return (1);
	return (0);
}

static int compare_rrr(char *str1, char *str2)
{
	if (!ft_strcmp(str1, "rra"))
		if (!ft_strcmp(str2, "rrb"))
			return (1);
	if (!ft_strcmp(str1, "rrb"))
		if (!ft_strcmp(str2, "rra"))
			return (1);
	return (0);
}

static int merge_two_nodes(t_oper *curr, char *str)
{
	t_oper *del;

	del = curr->next;
	curr->next = curr->next->next;
	curr->next->data = str;
	ft_memdel((void **)&del);
}


int opt_is_double_node(t_oper *oper)
{
	t_oper *curr;
	int res;

	curr = oper;
	res = FALSE;
	while (curr && curr->next && curr->next->next)
	{
		if (compare_ss(curr->next->data, curr->next->next->data))
		{
			merge_two_nodes(curr, "ss");
			res = TRUE;
		}
		// else if (compare_rr(curr->next->data, curr->next->next->data))
		// {
		// 	merge_two_nodes(curr, "rr");
		// 	res = TRUE;
		// }
		// else if (compare_rrr(curr->next->data, curr->next->next->data))
		// {
		// 	merge_two_nodes(curr, "rrr");
		// 	res = TRUE;
		// }
		curr = curr->next;
	}
	return res;
}
