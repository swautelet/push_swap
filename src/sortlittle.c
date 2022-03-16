/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortlittle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:58:47 by swautele          #+#    #+#             */
/*   Updated: 2022/03/16 16:42:59 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(t_stack stack, int imax)
{
	int	i;

	i = -1;
	while (++i < imax)
	{
		if (stack.a[i] > stack.a[i + 1])
			return (1);
		if (stack.b != INT_MAX + 1)
			return (2);
	}
	return (0);
}

int	sortlittle(t_stack stack, int size)
{
	int	i;

	i = -1;
	while (++i < INT_MAX)
	{
		if (issorted(stack, size - 1))
			return (i);
	}
	return (-1);
}

void	sort(t_stack stack, int size)
{
	int	sol;

	if (issorted(stack, size - 1) == 0)
		return ;
	if (size <= 5)
	{
		sol = sortlittle(stack, size);
	}
}
