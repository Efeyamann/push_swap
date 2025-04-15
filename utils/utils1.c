/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:56:56 by heret             #+#    #+#             */
/*   Updated: 2025/04/15 14:55:48 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

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

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
