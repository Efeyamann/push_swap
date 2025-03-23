/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:21:18 by esir              #+#    #+#             */
/*   Updated: 2025/03/23 15:41:39 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ra(t_node **stack_a)
{
	t_node	*temp;
	t_node	*last;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return ;
	temp = *stack_a;
	*stack_a = temp->next;
	temp->next = NULL;
	last = *stack_a;
	while (last->next)
	{
		last = last->next;
	}
	last->next = temp;
	write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	t_node	*temp;
	t_node	*last;

	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return ;
	temp = *stack_b;
	*stack_b = temp->next;
	temp->next = NULL;
	last = *stack_b;
	while (last->next)
	{
		last = last->next;
	}
	last->next = temp;
	write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
