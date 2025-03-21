/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efe <efe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:24:50 by efe               #+#    #+#             */
/*   Updated: 2025/03/21 21:27:53 by efe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

t_node	*create_list(char *argv[]);
t_node	*last_node(t_node *stack);
t_node	*min_node(t_node *stack);
t_node	*max_node(t_node *stack);
int		stack_len(t_node *stack);
int		checker(char **argv);
int		is_number(char *str);
int		is_duplicate(t_node *stack, int num);
int		find_smallest(t_node *stack, int n);
int		node_position(t_node *stack, t_node *target);
void	main_sort(t_node **stack_a, t_node **stack_b);
void	free_args(char **args);
void	free_stack(t_node **stack);
void	push_min(t_node **stack_a, t_node **stack_b);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

#endif