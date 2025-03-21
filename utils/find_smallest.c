/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efe <efe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:37:13 by marvin            #+#    #+#             */
/*   Updated: 2025/03/21 21:25:53 by efe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	node_position(t_node *stack, t_node *target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == target)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

static	void bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	find_smallest(t_node *stack, int n)
{
	int		*arr;
	int		size;
	int		i;
	int		result;
	t_node	*temp;

	size = stack_len(stack);
	if (n < 1 || n > size)
		return (-1);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (-1);
	temp = stack;
	i = 0;
	while (temp)
	{
		arr[i++] = temp->value;
		temp = temp->next;
	}
	bubble_sort(arr, size);
	result = arr[n - 1];
	free(arr);
	return (result);
}
