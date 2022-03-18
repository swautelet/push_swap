/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:04:26 by swautele          #+#    #+#             */
/*   Updated: 2022/03/18 19:35:36 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	firstdivide(t_stack stack, int size, t_lim limits)
{
	ssize_t	mina;
	int		i;

	mina = limits.mid - 1;
	while (mina < limits.mid && stack.a[2] != EMPTY)
	{
		i = -1;
		mina = stack.a[0];
		while (stack.a[++i] != EMPTY)
		{
			if (stack.a[i] < mina)
				mina = stack.a[i];
		}
		if (stack.a[0] > stack.a[1] && stack.a[0] < limits.mid)
		{
			do_sa(stack, size);
			write(1, "sa\n", 3);
		}
		if (stack.a[0] < limits.mid && stack.a[2] != EMPTY)
		{
			// i = -1;
			// while (++i < size)
			// {
				// printf("stacka[%d] = %zd				stackb[%d] = %zd	mina = %zd limits.mid = %zd\n", i, stack.a[i], i, stack.b[i], mina, limits.mid);
			// }
			do_pb(stack, size);
			write(1, "pb\n", 3);
		}
		else if (stack.a[0] >= limits.mid && stack.a[2] != EMPTY)
		{
			do_ra(stack, size);
			write(1, "ra\n", 3);
		}
	}
	// printf("limits.mid = %zd limits.max = %zd\n", limits.mid, limits.max);
	if (stack.a[2] != EMPTY)
	{
		limits.mid += (limits.max - limits.mid) / 3;
		firstdivide(stack, size, limits);
		bigsort(stack, size, limits);
	}
}

void	sort_stacka(t_stack stack, int size, t_lim limits)
{
	while (stack.a[0] != limits.min)
	{
		do_ra(stack, size);
		write(1, "ra\n", 3);
	}
}

void	bigsort(t_stack stack, int size, t_lim limits)
{
	int	lastb;
	int	lasta;
	// int	i;

	lastb = 0;
	while (stack.b[lastb + 1] != EMPTY)
		lastb++;
	lasta = 0;
	while (stack.a[lasta + 1] != EMPTY)
		lasta++;
	// printf("limits.mid = %zd lasta = %d	lastb = %d stackb[0] = %zd stackb[lastb] = %zd\n", limits.mid, lasta, lastb, stack.b[0], stack.b[lastb]);
	while (stack.b[0] >= limits.mid || stack.b[lastb] >= limits.mid)
	{
		// i = -1;
		// while (++i < size)
		// {
			// printf("stacka[%d] = %zd				stackb[%d] = %zd\n", i, stack.a[i], i, stack.b[i]);
		// }
		if (stack.b[lastb] > stack.b[0] && stack.b[lastb] < stack.a[lasta] && stack.a[lasta] < stack.a[0])
		{
			do_rrr(stack, size);
			write(1, "rrr\n", 4);
		}
		else if (stack.b[0] < stack.b[1] && stack.b[0] > stack.a[0])
		{
			do_rr(stack, size);
			write(1, "rr\n", 3);
		}
		else if (stack.b[0] < stack.b[1] && stack.b[1] != EMPTY)
		{
			do_rb(stack, size);
			write(1, "rb\n", 3);
		}
		else if (stack.b[0] < stack.b[lastb] && stack.b[0] != EMPTY)
		{
			do_rrb(stack, size);
			write(1, "rrb\n", 4);
		}
		else if (stack.b[0] < stack.a[0] && stack.a[0] < stack.a[lasta])
		{
			do_pa(stack, size);
			write(1, "pa\n", 3);
			lastb--;
			lasta++;
		}
		else if (stack.b[0] < stack.a[0] && stack.b[0] < stack.a[lasta] && stack.a[lasta] < stack.a[0])
		{
			do_rra(stack, size);
			write(1, "rra\n", 4);
		}
		else if (stack.b[0] > stack.a[0])
		{
			// printf("test\n");
			do_ra(stack, size);
			write(1, "ra\n", 3);
		}
		else if (stack.b[0] < stack.a[0] && stack.b[0] > stack.a[lasta])
		{
			do_pa(stack, size);
			write(1, "pa\n", 3);
			lastb--;
			lasta++;
		}
		else
			break ;
	}
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
	limits.mid = (limits.min + limits.max) / 3;
	firstdivide(stack, size, limits);
	bigsort(stack, size, limits);
	while (limits.mid != (limits.mid + limits.min) / 3)
	{
		limits.mid = (limits.mid + limits.min) / 3;
		bigsort(stack, size, limits);
	}
	// sort_stacka(stack, size, limits);
	limits.mid = limits.min -1;
	bigsort(stack, size, limits);
	// printf("limits.mid = %zd  stackb[0] = %zd\n", limits.mid, stack.b[0]);
	// i = -1;
	// while (++i < size)
	// {
		// printf("stacka[%d] = %zd				stackb[%d] = %zd\n", i, stack.a[i], i, stack.b[i]);
	// }
}