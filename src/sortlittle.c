/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortlittle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:58:47 by swautele          #+#    #+#             */
/*   Updated: 2022/03/17 17:13:43 by swautele         ###   ########.fr       */
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

int	sortlittle(t_stack stack, int size)
{
	int		i;
	t_stack	temp;
	// int		j;

	i = -1;
	while (++i < INT_MAX)
	{
		temp = copy_and_try(stack, size, i);
		if (issorted(temp, size - 1) == 0)
		{
			// j = -1;
			// while (++j < size)
			// {
				// printf("stack.a[%d] = %zd stack.b[%d] = %zd\n", j, temp.a[j], j, temp.b[j]);
			// }
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
	if (size <= 5)
	{
		sol = sortlittle(stack, size);
		print_soluce(sol);
	}
}
