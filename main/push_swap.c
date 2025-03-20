/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efe <efe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:20:04 by efe               #+#    #+#             */
/*   Updated: 2025/03/19 23:58:12 by efe              ###   ########.fr       */
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
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

static void	push_to_b(t_node **stack, t_node **stack_b, int size)
{
	int swap_size;
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
