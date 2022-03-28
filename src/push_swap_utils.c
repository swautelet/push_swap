/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:34:44 by swautele          #+#    #+#             */
/*   Updated: 2022/03/28 13:30:32 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_stack stack, char **argv, int argc)
{
	int		i;
	char	err;

	i = 0;
	while (++i <= argc - 1)
	{
		stack.a[i - 1] = ft_atoi(argv[i], &err);
		if (err == -1)
		{
			write(2, "Error\nA number is not an int", 29);
			return (-1);
		}
		stack.b[i - 1] = EMPTY;
	}
	stack.a[i - 1] = EMPTY;
	stack.b[i - 1] = EMPTY;
	return (0);
}

int	issorted(t_stack stack, int size)
{
	int	i;

	i = 0;
	while (++i < size)
	{
		if (stack.a[i - 1] > stack.a[i])
			return (1);
		if (stack.b[i] != EMPTY)
			return (2);
	}
	return (0);
}
