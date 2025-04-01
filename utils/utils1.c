/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heret <heret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:56:56 by heret             #+#    #+#             */
/*   Updated: 2025/04/01 19:29:14 by heret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

t_node	*get_cheapest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
		{
			return (stack);
		}
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_node **stack, t_node *top_node, char *stack_name)
{
	while (*stack != top_node)
	{
		if (ft_strcmp(stack_name, "stack_a") == 0)
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (ft_strcmp(stack_name, "stack_b") == 0)
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
