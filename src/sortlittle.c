/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortlittle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:58:47 by swautele          #+#    #+#             */
/*   Updated: 2022/03/18 11:56:16 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(t_stack stack, int imax)
{
	int	i;

	i = -1;
	while (++i <= imax)
	{
		if (stack.a[i] > stack.a[i + 1])
			return (1);
		if (stack.b[i] != EMPTY)
			return (2);
	}
	return (0);
}

int	sortlittle(t_stack stack, int size, int i)
{
	t_stack	temp;

	while (++i < INT_MAX)
	{
		if ((i % 12 == 1 && (i / 12) % 12 == 2) || (i % 12 == 4
				&& (i / 12) % 12 == 5) || (i % 12 == 6 && (i / 12) % 12 == 9)
			|| (i % 12 == 7 && (i / 12) % 12 == 10) || (i % 12 == 8
				&& (i / 12) % 12 == 11))
			i++;
		temp = copy_and_try(stack, size, i);
		if (issorted(temp, size - 1) == 0)
		{
			free(temp.a);
			free(temp.b);
			return (i);
		}
		free(temp.a);
		free(temp.b);
	}
	return (-1);
}

void	print_soluce(int sol)
{
	if (sol % 12 == 1)
		write(1, "sa\n", 3);
	if (sol % 12 == 2)
		write(1, "sb\n", 3);
	if (sol % 12 == 3)
		write(1, "ss\n", 3);
	if (sol % 12 == 4)
		write(1, "pa\n", 3);
	if (sol % 12 == 5)
		write(1, "pb\n", 3);
	if (sol % 12 == 6)
		write(1, "ra\n", 3);
	if (sol % 12 == 7)
		write(1, "rb\n", 3);
	if (sol % 12 == 8)
		write(1, "rr\n", 3);
	if (sol % 12 == 9)
		write(1, "rra\n", 4);
	if (sol % 12 == 10)
		write(1, "rrb\n", 4);
	if (sol % 12 == 11)
		write(1, "rrr\n", 4);
	if (sol / 12 > 0)
		print_soluce(sol / 12);
}

void	sort(t_stack stack, int size)
{
	int	sol;

	if (issorted(stack, size - 1) == 0)
		return ;
	if (size < 5)
	{
		sol = sortlittle(stack, size, -1);
		print_soluce(sol);
	}
	else if (size == 5)
	{
		do_pb(stack, size);
		write(1, "pb\n", 3);
		do_pb(stack, size);
		write(1, "pb\n", 3);
		sol = sortlittle(stack, size, 1728);
		print_soluce(sol);
	}
	else
		sortbig(stack, size);
}
