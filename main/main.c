/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efe <efe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:24:35 by efe               #+#    #+#             */
/*   Updated: 2025/03/19 23:31:11 by efe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *initialize_stack(int argc, char *argv[], int *allocated)
{
	t_node *stack_a;
	char **args;

	stack_a = NULL;
	*allocated = 0;
	if (argc < 1)
		return (ft_printf("Error\n"), 1);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		*allocated = 1;
	}
	else
		args = argv + 1;
	checker(args);
	stack_a = create_list(args);
	if (!stack_a)
	{
		ft_printf("Error\n");
		if (*allocated)
			free_args(args);
		return (NULL);
	}
	return (stack_a);
}

int main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		allocated;

	stack_b = NULL;
	stack_a = initialize_stack(argc, argv, &allocated);
	if (!stack_a)
		return (1);
	main_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (allocated)
		free_args(argv + 1);
	return (0);
}
