/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:20:04 by efe               #+#    #+#             */
/*   Updated: 2025/03/23 21:00:14 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	sort_three(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	if (!stack || !*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if ((a > b && b > c) || (b > c && c > a) || (c > a && a > b))
	{
		sa(stack);
		sort_three(stack);
	}
	else if ((a > c && c > b) || (c > b && b > a))
		ra(stack);
	else if ((b > a && a > c))
		rra(stack);
}

static void	sort_five(t_node **stack_a, t_node **stack_b)
{
	while (stack_len(*stack_a) > 3)
		push_min(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

static void push_to_b(t_node **stack_a, t_node **stack_b, int *c_limits, int total_to_push)
{
    int curr_chunk = 0;
    int stack_size = stack_len(*stack_a);
    int pushed_count = 0;

    while (total_to_push > 0 && *stack_a)
    {
        if ((*stack_a)->value <= c_limits[curr_chunk])
        {
            pb(stack_a, stack_b);
            total_to_push--;
            pushed_count++;
            if (*stack_b && (*stack_b)->value < c_limits[curr_chunk] / 2)
                rb(stack_b);
        }
        else
        {
            ra(stack_a);
        }
        if (pushed_count >= (curr_chunk + 1) * stack_size / (5))
        {
            curr_chunk++;
            pushed_count = 0;
        }
    }
}

static void	push_to_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*highest_node;
	int		pos;
	int		len;

	while (*stack_b)
	{
		highest_node = max_node(*stack_b);
		if (!highest_node)
			break;
		pos = node_position(*stack_b, highest_node);
		len = stack_len(*stack_b);

		if (pos <= len / 2)
			while (*stack_b != highest_node)
				rb(stack_b);
		else
			while (*stack_b != highest_node)
				rrb(stack_b);
		pa(stack_a, stack_b);
	}
}

void	turk_sort(t_node **stack_a, t_node **stack_b)
{
	int	*chunk_limits;
	int	total_to_push;
	int	stack_size;

	stack_size = stack_len(*stack_a);
	if (stack_size <= 3)
	{
		sort_three(stack_a);
		return ;
	}
	if (stack_size <= 5)
	{
		sort_five(stack_a, stack_b);
		return ;
	}
	total_to_push = stack_size - 3;
	chunk_limits = find_smallest_chunks(*stack_a, 5);
	if (!chunk_limits)
		return ;
	push_to_b(stack_a, stack_b, chunk_limits, total_to_push);
	sort_three(stack_a);
	push_to_a(stack_a, stack_b);
	free(chunk_limits);
}
