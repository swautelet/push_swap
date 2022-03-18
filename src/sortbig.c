/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:04:26 by swautele          #+#    #+#             */
/*   Updated: 2022/03/18 12:24:24 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	firstdivide(t_stack stack, int size, t_lim limits)
{
	ssize_t	last;

	last = stack.a[size - 1];
	while (stack.a[0] != last)
	{
		if (stack.a[0] < limits.mid)
		{
			do_pb(stack, size);
			write(1, "pb\n", 3);
		}
		if (stack.a[0] >= limits.mid)
		{
			do_ra(stack, size);
			write(1, "ra\n", 3);
		}
	}
	// printf("%zd\n", mid);
	if (stack.b[2] != EMPTY)
	{
		limits.mid = (limits.mid + limits.max) / 2;
		firstdivide(stack, size, limits);
	}
	//bigsort(stack, size, mid);
}

void	sort_stacka(t_stack stack, int size)
{
	int	i;
	int	t;

	i = -1;
	while (stack.a[++i + 1] != EMPTY)
	{
		if (stack.a[i] > stack.a[i + 1])
		{
			t = 0;
			while (t <= i)
			{
				do_ra(stack, size);
				write(1, "ra\n", 3);
				t++;
			}
			do_sa(stack, size);
			write(1, "sa\n", 3);
			while (t >= 0)
			{
				do_rra(stack, size);
				write(1, "rra\n", 4);
				t--;
			}
			i = -1;
		}
	}
}

void	bigsort(t_stack stack, int size, ssize_t mid)
{
	while (stack.b[0] > mid)
	{
		do_pa(stack, size);
		write(1, "pa\n", 3);
	}
	// sort_stacka(stack, size);
}

void	sortbig(t_stack stack, int size)
{
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
	limits.mid = (limits.min + limits.max) / 2;
	firstdivide(stack, size, limits);
	i = -1;
	while (++i < size)
	{
		printf("stacka[%d] = %zd				stackb[%d] = %zd\n", i, stack.a[i], i, stack.b[i]);
	}
}