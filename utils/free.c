/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:51:54 by marvin            #+#    #+#             */
/*   Updated: 2025/03/19 21:51:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_args(char **args)
{
    int i;

    i = 0;
    while (args[i])
    {
        free(args[1]);
        i++;
    }
    free(args);
}

void    free_stack(t_node **stack)
{
    t_node  *temp;

    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}