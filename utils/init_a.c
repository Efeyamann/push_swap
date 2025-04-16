/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:40:07 by heret             #+#    #+#             */
/*   Updated: 2025/04/16 23:20:57 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indices(t_node *stack)
{
	int		position;
	int		halfway;

	position = 0;
	if (!stack)
		return ;
	halfway = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = position;
		if (position <= halfway)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		position++;
	}
}

void	assign_target_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*b_cursor;
	t_node	*optimal_match;

	while (stack_a)
	{
		optimal_match = NULL;
		b_cursor = stack_b;
		while (b_cursor)
		{
			if (b_cursor->value < stack_a->value)
			{
				if (!optimal_match || b_cursor->value > optimal_match->value)
					optimal_match = b_cursor;
			}
			b_cursor = b_cursor->next;
		}
		if (optimal_match == NULL)
			stack_a->target_node = max_node(stack_b);
		else
			stack_a->target_node = optimal_match;
		stack_a = stack_a->next;
	}
}

void	evaluate_costs(t_node *src_stack, t_node *target_stack)
{
	int	src_size;
	int	tgt_size;

	if (!src_stack || !target_stack)
		return ;
	src_size = stack_len(src_stack);
	tgt_size = stack_len(target_stack);
	while (src_stack)
	{
		if (src_stack->above_median)
			src_stack->push_cost = src_stack->index;
		else
			src_stack->push_cost = src_size - src_stack->index;
		if (src_stack->target_node)
		{
			if (src_stack->target_node->above_median)
				src_stack->push_cost += src_stack->target_node->index;
			else
				src_stack->push_cost
					+= tgt_size - src_stack->target_node->index;
		}
		src_stack = src_stack->next;
	}
}

void	mark_cheapest_node(t_node *stack)
{
	long	lowest_cost;
	t_node	*min_node;

	if (!stack)
		return ;
	lowest_cost = INT_MAX;
	min_node = NULL;
	while (stack)
	{
		if (stack->push_cost < lowest_cost)
		{
			lowest_cost = stack->push_cost;
			min_node = stack;
		}
		stack = stack->next;
	}
	if (min_node != NULL)
		min_node->cheapest = true;
}
