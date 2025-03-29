/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heret <heret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:24:50 by efe               #+#    #+#             */
/*   Updated: 2025/03/29 15:43:48 by heret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdbool.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*prev;
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
int		node_position(t_node *stack, t_node *target);
bool	stack_sorted(t_node *stack);
void	turk_sort(t_node **stack_a, t_node **stack_b);
void	init_nodes_a(t_node *stack_a, t_node *stack_b);
void	current_index(t_node *stack);
void	free_args(char **args);
void	free_stack(t_node **stack);
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