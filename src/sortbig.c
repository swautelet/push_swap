/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:04:26 by swautele          #+#    #+#             */
/*   Updated: 2022/03/17 23:12:15 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	firstdivide(t_stack stack, int size, ssize_t mid)
{
	ssize_t	last;

	last = stack.a[size - 1];
	while (stack.a[0] != last)
	{
		if (stack.a[0] < mid)
		{
			do_pb(stack, size);
			write(1, "pb\n", 3);
		}
		if (stack.a[0] >= mid)
		{
			do_ra(stack, size);
			write(1, "ra\n", 3);
		}
	}
	printf("%zd\n", mid);
	if ((mid + INT_MAX) / 3 != mid)
		firstdivide(stack, size, (mid + INT_MAX) / 3);
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
	ssize_t	mid;
	int		i;

	i = 0;
	mid = 0;
	firstdivide(stack, size, mid);
	i = -1;
	while (++i < size)
	{
		printf("stacka[%d] = %zd				stackb[%d] = %zd\n", i, stack.a[i], i, stack.b[i]);
	}
}