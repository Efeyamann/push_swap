/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:09:40 by esir              #+#    #+#             */
/*   Updated: 2025/03/08 13:20:59 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (!stack_b || !(*stack_b))
		return ;
	temp = *stack_b;
	*stack_b = temp->next;
	
	temp->next = *stack_a;
	*stack_a = temp;
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (!stack_a || !(*stack_a))
		return ;
	temp = *stack_a;
	*stack_a = temp->next;
	
	temp->next = *stack_b;
	*stack_b = temp;	
}