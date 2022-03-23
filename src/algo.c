/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:28:39 by swautele          #+#    #+#             */
/*   Updated: 2022/03/23 15:28:57 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_and_write(t_stack stack, int size, int flag)
{
	if (flag == 0)
	{
		do_ss(stack, size);
		write(1, "ss\n", 3);
	}
	else if (flag == 1)
	{
		do_pb(stack, size);
		write(1, "pb\n", 3);
	}
	else if (flag == 2)
	{
		do_ra(stack, size);
		write(1, "ra\n", 3);
	}
	else if (flag == 3)
	{
		do_rrr(stack, size);
		write(1, "rrr\n", 4);
	}
	else if (flag == 4)
	{
		do_rr(stack, size);
		write(1, "rr\n", 3);
	}
}

static void	do_write(t_stack stack, int size, int flag)
{
	if (flag == 5)
	{
		do_rb(stack, size);
		write(1, "rb\n", 3);
	}
	else if (flag == 6)
	{
		do_rrb(stack, size);
		write(1, "rrb\n", 4);
	}
	else if (flag == 7)
	{
		do_rra(stack, size);
		write(1, "rra\n", 4);
	}
	else if (flag == 8)
	{
		do_ra(stack, size);
		write(1, "ra\n", 3);
	}
	else if (flag == 9)
	{
		do_pa(stack, size);
		write(1, "pa\n", 3);
	}
}

void	firstdivide(t_stack stack, int size, t_lim limits, t_stack sorted)
{
	ssize_t	mina;
	int		i;

	mina = limits.mid - 1;
	while (mina < limits.mid && stack.a[2] != EMPTY)
	{
		i = -1;
		mina = stack.a[0];
		while (stack.a[++i] != EMPTY)
			if (stack.a[i] < mina)
				mina = stack.a[i];
		if (stack.a[0] > stack.a[1] && stack.b[0] < stack.b[1])
			do_and_write(stack, size, 0);
		if (stack.a[0] <= limits.mid && stack.a[2] != EMPTY)
			do_and_write(stack, size, 1);
		else if (stack.a[0] > limits.mid && stack.a[2] != EMPTY)
			do_and_write(stack, size, 2);
	}
	if (stack.a[2] != EMPTY)
	{
		limits.ipiv = (limits.ipiv + size) / 2;
		limits.mid = sorted.b[limits.ipiv];
		firstdivide(stack, size, limits, sorted);
		bigsort(stack, size, limits);
	}
}

void	bigsort(t_stack stack, int size, t_lim limits)
{
	int	lastb;
	int	lasta;

	lastb = 0;
	while (stack.b[lastb + 1] != EMPTY)
		lastb++;
	lasta = 0;
	while (stack.a[lasta + 1] != EMPTY)
		lasta++;
	while (stack.b[0] >= limits.mid || stack.b[lastb] >= limits.mid)
	{
		if (stack.b[lastb] > stack.b[0] && stack.b[lastb] < stack.a[lasta]
			&& stack.a[lasta] < stack.a[0])
			do_and_write(stack, size, 3);
		else if (stack.b[0] < stack.b[1] && stack.b[0] > stack.a[0])
			do_and_write(stack, size, 4);
		else if (stack.b[0] < stack.b[1] && stack.b[1] != EMPTY)
			do_write(stack, size, 5);
		else if (stack.b[0] < stack.b[lastb] && stack.b[0] != EMPTY)
			do_write(stack, size, 6);
		else if (stack.b[0] < stack.a[0] && stack.b[0] < stack.a[lasta]
			&& stack.a[lasta] < stack.a[0])
			do_write(stack, size, 7);
		else if (stack.b[0] > stack.a[0])
			do_write(stack, size, 8);
		else if (stack.b[0] < stack.a[0] && (stack.b[0] > stack.a[lasta]
				|| stack.a[0] < stack.a[lasta]))
		{
			do_write(stack, size, 9);
			lastb--;
			lasta++;
		}
		else
			break ;
	}
}