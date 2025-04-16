/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:18:24 by efe               #+#    #+#             */
/*   Updated: 2025/04/16 23:22:06 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->cheapest = 0;
	node->above_median = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

static void	append_to_list(t_node **head, t_node *new_node)
{
	t_node	*current;

	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
}

static int	parse_and_append(t_node **head, char *arg)
{
	long	tmp;
	int		value;
	t_node	*node;

	tmp = ft_atol(arg);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (0);
	value = (int)tmp;
	if (is_duplicate(*head, value))
		return (0);
	node = new_node(value);
	if (!node)
		return (0);
	append_to_list(head, node);
	return (1);
}

t_node	*build_list(char *argv[])
{
	int		i;
	t_node	*head;

	i = 0;
	head = NULL;
	while (argv[i])
	{
		if (!parse_and_append(&head, argv[i]))
		{
			free_list(head);
			return (NULL);
		}
		i++;
	}
	return (head);
}

t_node	*create_list(char *argv[])
{
	if (!checker(argv))
		return (NULL);
	return (build_list(argv));
}
