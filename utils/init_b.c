/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:34:44 by heret             #+#    #+#             */
/*   Updated: 2025/04/15 15:10:41 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*best_target;

	while (b)
	{
		best_target = NULL;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value)
			{
				if (!best_target || current_a->value < best_target->value)
					best_target = current_a;
			}
			current_a = current_a->next;
		}
		if (!best_target)
			b->target_node = min_node(a);
		else
			b->target_node = best_target;
		b = b->next;
	}
}
