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

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!is_number(str[i]))
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

	while (temp != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

static void	append_to_list(t_node **head, int value)
{
	t_node	*current;

	if (is_duplicate(*head, value))
	{
		free_list(*head);
		ft_printf("Error\n");
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
	i = 1;
	while (argv[i])
	{
		if (!is_valid_number(argv[i]))
		{
			ft_printf("Error");
			free_list(head);
			exit(1);
		}
		value = ft_atoi(argv[i]);
		append_to_list(&head, ft_atoi(argv[i]));
		i++;
	}
	return (head);
}
