/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:37:13 by marvin            #+#    #+#             */
/*   Updated: 2025/03/23 20:51:29 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}

int	qselect(int *arr, int low, int high, int n)
{
	int	pivot_index;

	while (low < high)
	{
		pivot_index = partition(arr, low, high);
		if (pivot_index == n)
			return (arr[pivot_index]);
		else if (pivot_index > n)
			high = pivot_index - 1;
		else
			low = pivot_index + 1;
	}
	return (arr[low]);
}

int	*find_smallest_chunks(t_node *stack, int chunk_count)
{
	int	*arr;
	int	*limits;
	int	size;
	int	i;

	size = stack_len(stack);
	if (chunk_count < 1 || chunk_count > size)
		return (NULL);
	arr = malloc(sizeof(int) * size);
	limits = malloc(sizeof(int) * chunk_count);
	if (!arr || !limits)
		return (free(arr), free(limits), NULL);
	t_node *temp = stack;
	i = 0;
	while (temp)
	{
		arr[i++] = temp->value;
		temp = temp->next;
	}
	i = 0;
	while (i < chunk_count)
	{
		limits[i] = qselect(arr, 0, size - 1, (size * (i + 1)) / chunk_count);
		i++;
	}
	limits[chunk_count-1] = INT_MAX;
	free(arr);
	return (limits);
}
