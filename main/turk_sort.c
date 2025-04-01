/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heret <heret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:20:04 by efe               #+#    #+#             */
/*   Updated: 2025/04/01 23:51:27 by heret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sort_three(t_node **stack_a)
{
	t_node	*max_value;

	max_value = max_node(*stack_a);
	if (max_value == *stack_a)
		ra(stack_a);
	else if ((*stack_a)->next == max_value)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

static void	move_a_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
	{
		rotate_both(stack_a, stack_b, cheapest_node);
	}
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
	{
		rev_rotate_both(stack_a, stack_b, cheapest_node);
	}
	prep_for_push(stack_a, cheapest_node, "stack_a");
	prep_for_push(stack_b, cheapest_node->target_node, "stack_b");
	pb(stack_b, stack_a);
}

static void	move_b_to_a(t_node **stack_a, t_node **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target_node, "stack_a");
	pa(stack_a, stack_b);
}

static void	min_on_top(t_node **stack_a)
{
	t_node	*min;

	min = min_node(*stack_a);
	while ((*stack_a)->value != min->value)
	{
		if (min->above_median)
			rra(stack_a);
		else
			ra(stack_a);
	}
}

void	turk_sort(t_node **stack_a, t_node **stack_b)
{
	int	a_len;

	a_len = stack_len(*stack_a);
	if (a_len-- > 3 && !stack_sorted(*stack_a))
	{
		pb(stack_b, stack_a);
	}
	if (a_len-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a);
	while (a_len-- > 3 && !stack_sorted(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	min_on_top(stack_a);
}
