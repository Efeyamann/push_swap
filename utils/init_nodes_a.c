/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heret <heret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:40:07 by heret             #+#    #+#             */
/*   Updated: 2025/03/29 15:56:13 by heret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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

static void	set_target_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*current_b;
	t_node	*target_node;
	long	best_mach_index;

	while (stack_a)
	{
		best_mach_index = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->value < stack_a->value
				&& current_b->value > best_mach_index)
			{
				best_mach_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_mach_index == LONG_MIN)
			stack_a->target_node = find_max(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

static void	corst_analysis_a(t_node *stack_a, t_node *stack_b)
{
	int	a_len;
	int	b_len;

}

void	init_nodes_a(t_node *stack_a, t_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}
