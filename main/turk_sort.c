/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heret <heret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:20:04 by efe               #+#    #+#             */
/*   Updated: 2025/03/29 15:31:28 by heret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack_a)
{
	t_node	*max_value;

	max_value = max_node(stack_a);
	if (max_value == *stack_a)
		ra(stack_a);
	else if ((*stack_a)->next == max_value)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	turk_sort(t_node **stack_a, t_node **stack_b)
{
	int a_len;

	a_len =stack_len(*stack_a);
	if (a_len-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a);
	if (a_len-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a);
	while (a_len-- > 3 && !stack_sorted(*stack_a))
	{
		init_node_
	}
}