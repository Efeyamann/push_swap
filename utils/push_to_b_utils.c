/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:07:21 by esir              #+#    #+#             */
/*   Updated: 2025/03/23 19:02:13 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_to_array(t_node *stack)
{
	int	size;
	int	*arr;
	int	i;

	i = 0;
	size = stack_len(stack);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (stack)
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}
	return (arr);
}

int	*ccl(t_node *stack, int *chunks_count)
{
	int	stck_size;
	int	chunks;
	int	*c_limits;
	int	i;
	int	chunk_id;

	stck_size = stack_len(stack);
	i = 0;
	if (stck_size <= 100)
		chunks = 5;
	else
		chunks = 11;
	c_limits = malloc(sizeof(int) * chunks);
	if (!c_limits)
		return (NULL);
	while (i < chunks)
	{
		chunk_id = (i * stck_size) / chunks;
		c_limits[i] = qselect(copy_to_array(stack), 0, stck_size - 1, chunk_id);
		i++;
	}
	*chunks_count = chunks;
	return (c_limits);
}

void	pbc(t_node **stack_a, t_node **stack_b, int *c_limits, int tto_push)
{
	int	curr_chunk;
	int	total_pushed;

	curr_chunk = 0;
	total_pushed = 0;
	while (total_pushed < tto_push)
	{
		if ((*stack_a)->value <= c_limits[curr_chunk])
		{
			pb(stack_a, stack_b);
			total_pushed++;
			if (total_pushed >= (curr_chunk + 1) * tto_push / (curr_chunk + 1))
				curr_chunk++;
		}
		else
			ra(stack_a);
	}
}
