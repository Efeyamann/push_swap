/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:48:40 by esir              #+#    #+#             */
/*   Updated: 2025/04/16 22:54:21 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "unistd.h"

int	validate_arg(char *arg)
{
	char	*trimmed;

	trimmed = ft_strtrim(arg, " \t\n\v\f\r");
	if (trimmed[0] == '\0')
	{
		free(trimmed);
		write(2, "Error\n", 6);
		return (0);
	}
	free(trimmed);
	return (1);
}
