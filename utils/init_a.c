/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:40:07 by heret             #+#    #+#             */
/*   Updated: 2025/04/15 15:26:26 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	current_index(t_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	set_target_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*current_b;
	t_node	*best_target;

	while (stack_a)
	{
		best_target = NULL;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->value < stack_a->value)
			{
				if (!best_target || current_b->value > best_target->value)
					best_target = current_b;
			}
			current_b = current_b->next;
		}
		if (!best_target)
			stack_a->target_node = max_node(stack_b);
		else
			stack_a->target_node = best_target;
		stack_a = stack_a->next;
	}
}

void	cost_analysis_a(t_node *stack_a, t_node *stack_b)
{
	int	a_len;
	int	b_len;

	if (!stack_a || !stack_b)
		return ;
	a_len = stack_len(stack_a);
	b_len = stack_len(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = a_len - (stack_a->index);
		if (stack_a->target_node)
		{
			if (stack_a->target_node->above_median)
				stack_a->push_cost += stack_a->target_node->index;
			else
				stack_a->push_cost += b_len - (stack_a->target_node->index);
		}
		stack_a = stack_a->next;
	}
}

void	set_cheapest(t_node *stack)
{
	long	cheapest_value;
	t_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = INT_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}
