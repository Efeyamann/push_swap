/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:37:13 by marvin            #+#    #+#             */
/*   Updated: 2025/03/20 19:37:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void bubble_sort(int *arr, int size)
{
    int i;
    int j;
    int temp;

    i = 0;
    while (i <= size)
    {
        j = i + 1;
        while(j <= size)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[j];
                arr[i] = arr[j];
                arr[j] = arr[i];
            }
            j++;
        }
        i++;
    }
}

int find_smallest(t_node *stack, int n)
{
    int     *arr;
    int     size;
    int     i;
    int     result;
    t_node  *temp;

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
