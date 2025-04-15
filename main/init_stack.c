/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:09:06 by esir              #+#    #+#             */
/*   Updated: 2025/04/15 15:21:23 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "unistd.h"

static int	expand_result_buffer(char ***result, int *k, int *cap)
{
	char	**new;
	int		j;

	*cap *= 2;
	new = malloc(sizeof(char *) * (*cap));
	if (!new)
		return (0);
	j = 0;
	while (j < *k)
	{
		new[j] = (*result)[j];
		j++;
	}
	free(*result);
	*result = new;
	return (1);
}

static int	append_to_result(char ***result, char **split, int *k, int *cap)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (*k >= *cap && !expand_result_buffer(result, k, cap))
			return (0);
		(*result)[*k] = ft_strdup(split[i]);
		if (!(*result)[*k])
			return (0);
		(*k)++;
		i++;
	}
	return (1);
}

static char	**flatten_args(int argc, char **argv, int *allocated)
{
	char	**result;
	char	**split;
	int		i;
	int		k;
	int		cap;

	*allocated = 1;
	cap = 16;
	result = malloc(sizeof(char *) * cap);
	if (!result)
		return (NULL);
	i = 1;
	k = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !append_to_result(&result, split, &k, &cap))
			return (free_split(split), free_args(result), NULL);
		free_split(split);
		i++;
	}
	result[k] = NULL;
	return (result);
}

t_node	*init_stack(int argc, char **argv, int *allo, char ***args_ptr)
{
	t_node	*stack_a;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	*args_ptr = flatten_args(argc, argv, allo);
	if (!*args_ptr)
		return (NULL);
	if (!checker(*args_ptr))
	{
		write(2, "Error\n", 6);
		if (*allo)
			free_args(*args_ptr);
		return (NULL);
	}
	stack_a = create_list(*args_ptr);
	if (!stack_a)
	{
		if (*allo)
			free_args(*args_ptr);
		return (write(2, "Error\n", 6), NULL);
	}
	return (stack_a);
}
