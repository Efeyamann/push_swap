/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:44:58 by esir              #+#    #+#             */
/*   Updated: 2025/04/16 13:03:10 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_a(t_node *stack_a, t_node *stack_b)
{
	assign_indices(stack_a);
	assign_indices(stack_b);
	assign_target_a(stack_a, stack_b);
	evaluate_costs(stack_a, stack_b);
	mark_cheapest_node(stack_a);
}

void	process_b(t_node *stack_a, t_node *stack_b)
{
	assign_indices(stack_a);
	assign_indices(stack_b);
	assign_target_b(stack_a, stack_b);
}
