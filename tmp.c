	// for (int j = 0; j < max_size; ++j)
	// {
	// 	printf("arr[%u] == [%u]\n", j, (arr[j]));
	// }



char		check_ss(t_stack *stack_b, t_block *block)
{
	if (!(block->curr_size_b > 1) || !(block->curr_size_a > 1))
		return (0);
	return (stack_b->data < stack_b->next->data) ? (1) : (0);
}

char		check_rr_or_rrr(t_stack *stack_b, t_block *block)
{
	int top;
	int bottom;

	if (!(block->curr_size_b > 1) || !(block->curr_size_a > 1))
		return (0);
	top = stack_b->data;
	while (stack_b->next)
		stack_b = stack_b->next;
	bottom = stack_b->data;
	return (top < bottom) ? (1) : (0);
}