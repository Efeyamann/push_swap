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

static void	sort_three(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	if (!stack || !*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if ((a > b && b > c) || (b > c && c > a) || (c > a && a > b))
	{
		sa(stack);
		sort_three(stack);
	}
	else if ((a > c && c > b) || (c > b && b > a))
		ra(stack);
	else if ((b > a && a > c))
		rra(stack);
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

    while (stack_len(*a) > to_keep && curr_chunk < chunk_count)
    {
        if ((*a)->value <= limits[curr_chunk])
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
