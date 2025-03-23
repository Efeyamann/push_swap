/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:24:35 by efe               #+#    #+#             */
/*   Updated: 2025/03/23 16:58:47 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "unistd.h"
#include <stdio.h>

int	validate_args(char **args, int allocated)
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

char	**split_args(char *argv, int *allocated)
{
	char **args;

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

t_node *initialize_stack(int argc, char *argv[], int *allocated, char ***args_ptr)
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

void print_stack(t_node *stack)
{
    while (stack)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		allocated;
	char	**args;

	stack_b = NULL;
	stack_a = initialize_stack(argc, argv, &allocated, &args);
	if (!stack_a)
		return (1);
	main_sort(&stack_a, &stack_b);
	print_stack(stack_a);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (allocated)
		free_args(args);
	return (0);
}
