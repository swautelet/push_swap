/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:28:39 by swautele          #+#    #+#             */
/*   Updated: 2022/03/25 16:54:51 by swautele         ###   ########.fr       */
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
		while (stack.a[++i] != EMPTY && i < size - 1)
			if (stack.a[i] < mina)
				mina = stack.a[i];
		if (stack.a[0] > stack.a[1] && stack.b[0] < stack.b[1])
			do_and_write(stack, size, 0);
		else if (stack.a[0] <= limits.mid && stack.a[2] != EMPTY)
			do_and_write(stack, size, 1);
		else if (stack.a[0] > limits.mid && stack.a[2] != EMPTY)
			do_and_write(stack, size, 2);
	}
	if (stack.a[2] != EMPTY)
	{
		limits.ipiv += (size - limits.ipiv) / 4;
		limits.mid = sorted.b[limits.ipiv];
		firstdivide(stack, size, limits, sorted);
		bigsort(stack, size, limits);
	}
}

static t_last	init_last(t_stack stack, int size, int flag)
{
	t_last	last;

	if (flag == 1)
		do_write(stack, size, 9);
	last.b = 0;
	while (stack.b[last.b + 1] != EMPTY && last.b + 2 < size)
		last.b++;
	last.a = 0;
	while (stack.a[last.a + 1] != EMPTY && last.a + 2 < size)
		last.a++;
	return (last);
}

void	bigsort(t_stack stack, int size, t_lim limits)
{
	t_last	last;

	last = init_last(stack, size, 0);
	while (stack.b[0] >= limits.mid || stack.b[last.b] >= limits.mid)
	{
		if (stack.b[last.b] > stack.b[0] && stack.b[last.b] < stack.a[last.a]
			&& stack.a[last.a] < stack.a[0])
			do_and_write(stack, size, 3);
		else if (stack.b[0] < stack.b[1] && stack.b[0] > stack.a[0])
			do_and_write(stack, size, 4);
		else if (stack.b[0] < stack.b[1] && stack.b[1] != EMPTY)
			do_write(stack, size, 5);
		else if (stack.b[0] < stack.b[last.b] && stack.b[0] != EMPTY)
			do_write(stack, size, 6);
		else if (stack.b[0] < stack.a[0] && stack.b[0] < stack.a[last.a]
			&& stack.a[last.a] < stack.a[0])
			do_write(stack, size, 7);
		else if (stack.b[0] > stack.a[0])
			do_write(stack, size, 8);
		else if (stack.b[0] < stack.a[0] && (stack.b[0] > stack.a[last.a]
				|| stack.a[0] < stack.a[last.a]))
			last = init_last(stack, size, 1);
		else
			break ;
	}
}
