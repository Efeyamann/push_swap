/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efe <efe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:16:38 by efe               #+#    #+#             */
/*   Updated: 2025/03/01 15:28:34 by efe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	is_over_under_flow(const char *str)
{
	int	b;
	int	i;
	int	a;

	i = 0;
	a = 1;
	b = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		a = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		b = (b * 10) + (str[i] - '0');
		i++;
	}
	if (b < -2147483647 || b > 2147483647)
	{
		return (0);
	}
	return (a * b);
}

int	is_duplicate(t_node *stack, int num)
{
	while (stack)
	{
		if (stack->value == num)
		{
			return (1);
		}
		stack = stack->next;
	}
	return (0);
}

int	checker(char **argv)
{
	int	i;
	int	result;

	i = 0;
	while (argv[i])
	{
		if (!is_number(argv[i] || !is_over_under_flow(argv[i])))
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}
