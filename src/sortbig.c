/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:04:26 by swautele          #+#    #+#             */
/*   Updated: 2022/03/23 15:29:05 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	virtualsort(t_stack stack, int size, t_lim limits)
{
	t_stack	sorted;
	int		i;
	int		towr;

	sorted = copy_stack(stack, size);
	towr = 0;
	limits.mid = limits.min;
	sorted.b[towr] = limits.mid;
	while (limits.mid != limits.max)
	{
		limits.mid = limits.max;
		i = -1;
		while (++i < size)
		{
			if (sorted.a[i] < limits.mid && sorted.a[i] != EMPTY
				&& sorted.a[i] != limits.min)
				limits.mid = sorted.a[i];
		}
		i = -1;
		while (++i < size)
		{
			if (sorted.a[i] == limits.mid)
				sorted.a[i] = EMPTY;
		}
		towr++;
		sorted.b[towr] = limits.mid;
	}
	return (sorted);
}

void	sortbig(t_stack stack, int size)
{
	t_lim	limits;
	int		i;
	t_stack	sorted;

	i = -1;
	limits.min = stack.a[0];
	limits.max = stack.a[0];
	while (++i < size)
	{
		if (stack.a[i] < limits.min)
			limits.min = stack.a[i];
		if (stack.a[i] > limits.max)
			limits.max = stack.a[i];
	}
	sorted = virtualsort(stack, size, limits);
	limits.ipiv = size / 2;
	limits.mid = sorted.b[limits.ipiv];
	firstdivide(stack, size, limits, sorted);
	bigsort(stack, size, limits);
	while (limits.ipiv != 1)
	{
		limits.ipiv = limits.ipiv / 2;
		limits.mid = sorted.b[limits.ipiv];
		bigsort(stack, size, limits);
	}
	limits.mid = limits.min -1;
	bigsort(stack, size, limits);
	free (sorted.a);
	free (sorted.b);
}
