/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efe <efe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:18:24 by efe               #+#    #+#             */
/*   Updated: 2025/03/21 21:26:32 by efe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static int	is_valid_number(char *str)
{
	int		i;
	char	temp[2];

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		temp[0] = str[i];
		temp[1] = '\0';
		if (!is_number(temp))
			return (0);
		i++;
	}
	return (1);
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

	if (*head == NULL)
	{
		*head = new_node(value);
		if (!*head)
			exit(1);
		return ;
	}
	if (is_duplicate(*head, value))
	{
		if (*head)
			free_list(*head);
		write(2, "Error\n", 6);
		exit(0);
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new_node(value);
	if (!current->next)
	{
		free_list(*head);
		exit(0);
	}
}

t_node	*create_list(char *argv[])
{
	int		i;
	int		value;
	t_node	*head;

	head = NULL;
	i = 0;
	while (argv[i])
	{
		if (!is_valid_number(argv[i]))
		{
			write(2, "Error\n", 6);
			free_list(head);
			exit(1);
		}
		value = ft_atoi(argv[i]);
		append_to_list(&head, value);
		i++;
	}
	return (head);
}
