/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heret <heret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:53:38 by marvin            #+#    #+#             */
/*   Updated: 2025/04/01 18:52:08 by heret            ###   ########.fr       */
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
		return (NULL);
	min = stack;
	while (stack)
	{
		if (stack->value < min->value)
		{
			min = stack;
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
			max = stack;
		}
		stack = stack->next;
	}
	return (max);
}
