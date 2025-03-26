/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:20:04 by efe               #+#    #+#             */
/*   Updated: 2025/03/23 21:00:14 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void sort_three(t_node **stack)
{
    int top = (*stack)->value;
    int mid = (*stack)->next->value;
    int bottom = (*stack)->next->next->value;

    if (top > mid && top > bottom)
    {
        ra(stack);
        if (mid > bottom)
            sa(stack);
    }
    else if (mid > top && mid > bottom)
    {
        rra(stack);
        if (top > bottom)
            sa(stack);
    }
    else if (top < mid && mid > bottom)
    {
        rra(stack);
        sa(stack);
    }
    else if (top > mid && top < bottom)
    {
        sa(stack);
    }
}

static void	sort_five(t_node **stack_a, t_node **stack_b)
{
	while (stack_len(*stack_a) > 3)
		push_min(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

static void push_to_b(t_node **a, t_node **b, int *limits, int chunk_count)
{
    int stack_size = stack_len(*a);
    int to_keep = 3;
    int chunk_size = stack_size / chunk_count;
    int curr_chunk = 0;
    int pushed = 0;
    int rotations = 0;

    int largest[3];
    find_three_largest(*a, largest);
    while (stack_len(*a) > to_keep && curr_chunk < chunk_count)
    {
        int current = (*a)->value;
        if (current == largest[0] || current == largest[1] || current == largest[2])
        {
            ra(a);
            rotations++;
            continue;
        }
        if (current <= limits[curr_chunk])
        {
            pb(a, b);
            pushed++;
            if (*b && (*b)->value < limits[curr_chunk]/2)
                rb(b);
        }
        else if ((*a)->next && (*a)->next->value <= limits[curr_chunk])
        {
            sa(a);
            continue;
        }
        else
        {
            ra(a);
            rotations++;
        }
        if (pushed >= chunk_size || rotations >= stack_len(*a))
        {
            curr_chunk++;
            pushed = 0;
            rotations = 0;
        }
    }
    if (stack_len(*a) > to_keep)
    {
        while (stack_len(*a) > to_keep)
        {
            if (!is_among_largest(*a, largest))
                pb(a, b);
            else
                ra(a);
        }
    }
}

static void push_to_a(t_node **a, t_node **b)
{
    while (*b)
    {
        t_node *max = max_node(*b);
        int pos = node_position(*b, max);
        int len = stack_len(*b);
        
        if (pos <= len/2)
            while (*b != max) rb(b);
        else
            while (*b != max) rrb(b);
            
        pa(a, b);
    }
}

void turk_sort(t_node **stack_a, t_node **stack_b)
{
    int stack_size = stack_len(*stack_a);
    int chunk_count = 5; 
    int *chunk_limits;
    
	if (stack_size <= 3)
	{
		sort_three(stack_a);
		return ;
	}
	if (stack_size <= 5)
	{
		sort_five(stack_a, stack_b);
		return ;
	}
    chunk_limits = find_smallest_chunks(*stack_a, chunk_count);
    if (!chunk_limits)
        return;
    push_to_b(stack_a, stack_b, chunk_limits, chunk_count);
    sort_three(stack_a);
    push_to_a(stack_a, stack_b);
    free(chunk_limits);
} 
