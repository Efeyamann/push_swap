/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_n_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:07:26 by marvin            #+#    #+#             */
/*   Updated: 2025/03/26 17:07:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void find_three_largest(t_node *stack, int largest[3])
{
    largest[0] = INT_MIN;
    largest[1] = INT_MIN;
    largest[2] = INT_MIN;

    t_node *current = stack;
    while (current)
    {
        if (current->value > largest[0])
        {
            largest[2] = largest[1];
            largest[1] = largest[0];
            largest[0] = current->value;
        }
        else if (current->value > largest[1])
        {
            largest[2] = largest[1];
            largest[1] = current->value;
        }
        else if (current->value > largest[2])
        {
            largest[2] = current->value;
        }
        current = current->next;
    }
}

bool is_among_largest(t_node *node, int largest[3])
{
    return (node->value == largest[0] || 
            node->value == largest[1] || 
            node->value == largest[2]);
}