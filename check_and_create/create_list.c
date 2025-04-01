/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heret <heret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:18:24 by efe               #+#    #+#             */
/*   Updated: 2025/04/01 19:40:24 by heret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

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

static void	free_list(t_node *head)
{
	t_node	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

static void	append_to_list(t_node **head, int value)
{
	t_node	*current;
	t_node	*new;

	if (*head == NULL)
	{
		*head = new_node(value);
		if (!*head)
			exit(1);
		return ;
	}
	if (is_duplicate(*head, value))
	{
		free_list(*head);
		write(2, "Error\n", 6);
		exit(1);
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	new = new_node(value);
	if (!new)
	{
		free_list(*head);
		exit(1);
	}
	current->next = new;
	new->prev = current;
}

t_node	*create_list(char *argv[])
{
	int		i;
	int		value;
	t_node	*head;

	if (!checker(argv))
		exit(1);
	head = NULL;
	i = 0;
	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		append_to_list(&head, value);
		i++;
	}
	return (head);
}
