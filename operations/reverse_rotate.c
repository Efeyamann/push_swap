/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:41:25 by esir              #+#    #+#             */
/*   Updated: 2025/03/08 14:01:56 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **stack_a)
{
	t_node	*temp;
	t_node	*last;
	t_node	*prev;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return ; 
	temp = *stack_a;
	prev = NULL;
	last = *stack_a;
	while (last > prev)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = temp;
	*stack_a = last;
}

void	rrb(t_node **stack_b)
{
	t_node	*temp;
	t_node	*last;
	t_node	*prev;

	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return ; 
	temp = *stack_b;
	prev = NULL;
	last = *stack_b;
	while (last > prev)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = temp;
	*stack_b = last;
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
