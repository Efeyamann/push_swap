/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:34:44 by heret             #+#    #+#             */
/*   Updated: 2025/04/16 13:04:40 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_target_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*a_cursor;
	t_node	*target;

	while (stack_b)
	{
		target = NULL;
		a_cursor = stack_a;
		while (a_cursor)
		{
			if (a_cursor->value > stack_b->value)
			{
				if (target == NULL || a_cursor->value < target->value)
					target = a_cursor;
			}
			a_cursor = a_cursor->next;
		}
		if (target == NULL)
			stack_b->target_node = min_node(stack_a);
		else
			stack_b->target_node = target;
		stack_b = stack_b->next;
	}
}
