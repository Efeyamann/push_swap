/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heret <heret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:24:35 by efe               #+#    #+#             */
/*   Updated: 2025/04/01 18:57:56 by heret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "unistd.h"

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

static char	**split_args(char *argv, int *allocated)
{
	char	**args;

	*allocated = 0;
	if (ft_strchr(argv, ' ') == NULL)
		args = &argv;
	else
	{
		args = ft_split(argv, ' ');
		*allocated = 1;
	}
	return (args);
}

static t_node	*init_stack(int argc, char *argv[], int *allocated, char ***args_ptr)
{
	t_node	*stack_a;

	stack_a = NULL;
	*allocated = 0;
	if (argc < 2)
		return (write(2, "Error\n", 6), NULL);
	if (argc == 2)
	{
		*args_ptr = split_args(argv[1], allocated);
	}
	else
		*args_ptr = argv + 1;
	if (!validate_args(*args_ptr, *allocated))
		return (NULL);
	stack_a = create_list(*args_ptr);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		if (*allocated)
			free_args(*args_ptr);
		return (NULL);
	}
	return (stack_a);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		allocated;
	char	**args;

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
