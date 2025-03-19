/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efe <efe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:53:38 by marvin            #+#    #+#             */
/*   Updated: 2025/03/19 23:53:34 by efe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_node	*last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

t_node	*min_node(t_node *stack)
{
	t_node	*min;

	if (!stack)
	{
		return (NULL);
	}
	min = stack;
	while (stack)
	{
		if (stack->value < min->value)
		{
			min = stack->next;
		}
		stack = stack->next;
	}
	return (min);
}

t_node	*max_node(t_node *stack)
{
	t_node	*max;

	if (!stack)
	{
		return (NULL);
	}
	max = stack;
	while (stack)
	{
		if (stack->value > max->value)
		{
			max = stack->next;
		}
		stack = stack->next;
	}
	return (max);
}

void	push_min(t_node **stack_a, t_node **stack_b)
{
	t_node	*min;

	min = min_node(*stack_a);
	while (*stack_a != min)
		ra(stack_a);
	pb(stack_a, stack_b);
}
