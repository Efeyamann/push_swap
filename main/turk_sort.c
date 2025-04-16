/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:20:04 by efe               #+#    #+#             */
/*   Updated: 2025/04/16 23:21:25 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_cheapest_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*node;

	node = get_cheapest(*stack_a);
	if (node->above_median && node->target_node->above_median)
		rotate_both(stack_a, stack_b, node);
	else if (!node->above_median && !node->target_node->above_median)
		rev_rotate_both(stack_a, stack_b, node);
	position_for_push(stack_a, node, "stack_a");
	position_for_push(stack_b, node->target_node, "stack_b");
	pb(stack_b, stack_a);
}

static void	push_top_to_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*target;

	target = (*stack_b)->target_node;
	position_for_push(stack_a, target, "stack_a");
	pa(stack_a, stack_b);
}

static void	align_min_to_top(t_node **stack_a)
{
	t_node	*min;

	min = min_node(*stack_a);
	while ((*stack_a)->value != min->value)
	{
		if (min->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

static void	pre_sort_push_to_b(t_node **stack_a, t_node **stack_b)
{
	int	len;

	len = stack_len(*stack_a);
	if (len > 3 && !stack_sorted(*stack_a))
	{
		pb(stack_b, stack_a);
		len--;
	}
	if (len > 3 && !stack_sorted(*stack_a))
	{
		pb(stack_b, stack_a);
		len--;
	}
	while (len > 3 && !stack_sorted(*stack_a))
	{
		process_a(*stack_a, *stack_b);
		push_cheapest_to_b(stack_a, stack_b);
		len--;
	}
}

void	turk_sort(t_node **stack_a, t_node **stack_b)
{
	pre_sort_push_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		process_b(*stack_a, *stack_b);
		push_top_to_a(stack_a, stack_b);
	}
	assign_indices(*stack_a);
	align_min_to_top(stack_a);
}
