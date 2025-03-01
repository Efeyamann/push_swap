/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efe <efe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:16:38 by efe               #+#    #+#             */
/*   Updated: 2025/03/01 14:53:33 by efe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_overflow(const char *str)
{
	int	b;
	int	i;
	int	a;

	i = 0;
	a = 1;
	b = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		a = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		b = (b * 10) + (str[i] - '0');
		i++;
	}
	if (b < -2147483647 || b > 2147483647)
	{
		ft_printf("Error\n");
		return (0);
	}
	return (a * b);
}
