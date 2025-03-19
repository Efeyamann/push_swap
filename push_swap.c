/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efe <efe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:24:35 by efe               #+#    #+#             */
/*   Updated: 2025/03/01 15:21:30 by efe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**args;
	int		allocated;

	stack_a = NULL;
	stack_b = NULL;
	allocated = 0;
	if (argc < 2)
		return (ft_printf("Error\n"), 1);
	if (argc == 2)
	{
		args == ft_split(argv[1], ' ');
		allocated = 1;
	}
	else
		args = argv + 1;
	stack_a = create_list(args);
	if (!stack_a)
	{
		ft_printf("Error\n");
		if (allocated)
			free_args(args);
		return (1);
	}
	push_swap_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (allocated)
		free_args(args);
	return (0);
}
