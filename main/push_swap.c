/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efe <efe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:20:04 by efe               #+#    #+#             */
/*   Updated: 2025/03/21 20:59:35 by efe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && a > c)
		ra(stack);
	if (b > a && b > c)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

static void	sort_five(t_node **stack_a, t_node **stack_b)
{
	while (stack_len(*stack_a) > 3)
		push_min(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

static void	push_to_b(t_node **stack_a, t_node **stack_b, int size)
{
	int	swap_size;
	int	n_smallest;
	int	count;
	int	total_pushed;

	swap_size = size / 4;
	if (swap_size == 0)
		swap_size = 1;
	n_smallest = find_smallest(*stack_a, swap_size);
	count = 0;
	total_pushed = 0;
	while (*stack_a && total_pushed < size - 3)
	{
		if ((*stack_a)->value <= n_smallest)
		{
			pb(stack_a, stack_b);
			count++;
			total_pushed++;
			if (count % swap_size == 0 && *stack_a)
				n_smallest = find_smallest(*stack_a, swap_size);
		}
		else
			ra(stack_a);
	}
}

static void	push_to_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*highest_node;
	int		pos;
	int		len;

	while (*stack_b)
	{
		highest_node = max_node(*stack_b);
		pos = node_position(*stack_b, highest_node);
		len = stack_len(*stack_b);
		if (*stack_b != highest_node)
		{
			if (pos <= len / 2)
			{
				while (*stack_b != highest_node)
					rb(stack_b);
			}
			else
			{
				while (*stack_b != highest_node)
					rrb(stack_b);
			}
		}
		pa(stack_a, stack_b);
	}
}

void	main_sort(t_node **stack_a, t_node **stack_b)
{
	int	len;

	len = stack_len(*stack_a);
	if (len <= 3)
		sort_three(stack_a);
	else if (len <= 5)
		sort_five(stack_a, stack_b);
	else
	{
		push_to_b(stack_a, stack_b, len);
		push_to_a(stack_a, stack_b);
	}
}
