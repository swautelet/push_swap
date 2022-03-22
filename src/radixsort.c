/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:54:57 by swautele          #+#    #+#             */
/*   Updated: 2022/03/22 19:07:43 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	convertstack(t_stack stack, int size, t_stack sorted)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (stack.a[i] == sorted.b[j])
			{
				stack.a[i] = j;
				break ;
			}
		}
	}
}

void	radix_sort(t_stack stack, int size, int decal)
{
	int	i;

	while (issorted(stack, size) != 0)
	{
		i = 0;
		while (i < size)
		{
			if ((((stack.a[0] >> decal) & 1) % 2) == 0)
			{
				do_pb(stack, size);
				write(1, "pb\n", 3);
			}
			else
			{
				do_ra(stack, size);
				write(1, "ra\n", 3);
			}
			i++;
		}
		while (stack.b[0] != EMPTY)
		{
			do_pa(stack, size);
			write(1, "pa\n", 3);
		}
		i = -1;
		while (++i < size)
		{
			printf("stack.a[%d] = %zd		stack.b[%d] = %zd issorted = %d size = %d\n", i, stack.a[i], i, stack.b[i], issorted(stack, size - 1), size);
		}
		decal++;
	}
	return ;
}

void	very_big_sort(t_stack stack, int size)
{
	t_stack	sorted;
	t_lim	limits;
	int		i;

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
	// while (++i < size)
		// printf("sorted.b = %zd\n", sorted.b[i]);
	convertstack(stack, size, sorted);
	radix_sort(stack, size, 0);
	i = -1;
	while (++i < size)
	i = -1;
	{
		printf("stack.a[%d] = %zd		stack.b[%d] = %zd\n", i, stack.a[i], i, stack.b[i]);
	}
	free (sorted.a);
	free (sorted.b);
}
