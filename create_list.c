/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efe <efe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:18:24 by efe               #+#    #+#             */
/*   Updated: 2025/03/01 15:30:26 by efe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_to_list(t_node **stack, int value)
{
	t_node	*new;
	t_node	*temp;

	new = new_mode(value);
}

static t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

static int	is_duplicate(t_node *stack, int num)
{
	while (stack)
	{
		if (stack->value == num)
		{
			return (1);
		}
		stack = stack->next;
	}
	return (0);
}

static void	free_list(t_node *head)
{
	t_node	*temp;

	while (temp != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

t_node	*create_list(int argc, char *argv[])
{
	int	i;

	

}