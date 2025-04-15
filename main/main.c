/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:24:35 by efe               #+#    #+#             */
/*   Updated: 2025/04/15 15:13:00 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "unistd.h"
#include <stdio.h>

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
