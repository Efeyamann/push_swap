/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:24:35 by efe               #+#    #+#             */
/*   Updated: 2025/04/14 17:25:51 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "unistd.h"

static int	add_to_result(char ***result, char **split, int *k, int *cap)
{
	int		i;
	char	**new;

	i = 0;
	while (split[i])
	{
		if (*k >= *cap)
		{
			*cap *= 2;
			new = realloc(*result, sizeof(char *) * (*cap));
			if (!new)
				return (0);
			*result = new;
		}
		(*result)[*k] = split[i];
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
		if (!split || !add_to_result(&result, split, &k, &cap))
			return (NULL);
		free(split);
		i++;
	}
	result[k] = NULL;
	return (result);
}

static int	validate_args(char **args, int allocated)
{
	if (!checker(args))
	{
		write(2, "Error\n", 6);
		if (allocated)
			free_args(args);
		exit(1);
	}
	return (1);
}

static t_node	*init_stack(int argc, char **argv, int *allo, char ***args_ptr)
{
	t_node	*stack_a;

	stack_a = NULL;
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	*args_ptr = flatten_args(argc, argv, allo);
	if (!*args_ptr || !validate_args(*args_ptr, *allo))
		return (NULL);
	stack_a = create_list(*args_ptr);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		if (*allo)
			free_args(*args_ptr);
		return (NULL);
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		allocated;
	char	**args;

	if (argc == 1)
		return (0);
	stack_b = NULL;
	stack_a = init_stack(argc, argv, &allocated, &args);
	if (!stack_a)
		return (1);
	if (!stack_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			turk_sort(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (allocated)
		free_args(args);
	return (0);
}
