/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_and_try.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:50:19 by swautele          #+#    #+#             */
/*   Updated: 2022/03/28 13:42:49 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack stack)
{
	free (stack.a);
	free (stack.b);
}

t_stack	copy_stack(t_stack stack, int size)
{
	t_stack	temp;
	int		i;

	temp.a = ft_calloc((size + 1), sizeof(ssize_t));
	if (temp.a == NULL)
	{
		write(2, "Error\nCan't allocate space", 27);
		free_stack(stack);
		exit (1);
	}
	temp.b = ft_calloc((size + 1), sizeof(ssize_t));
	if (temp.b == NULL)
	{
		free_stack(stack);
		free (temp.a);
		write(2, "Error\nCan't allocate space", 27);
		exit (1);
	}
	i = -1;
	while (++i < size + 1)
	{
		temp.a[i] = stack.a[i];
		temp.b[i] = stack.b[i];
	}
	return (temp);
}

void	try(t_stack temp, int size, int i)
{
	if (i % 12 == 1)
		do_sa(temp, size);
	if (i % 12 == 2)
		do_sb(temp, size);
	if (i % 12 == 3)
		do_ss(temp, size);
	if (i % 12 == 4)
		do_pa(temp, size);
	if (i % 12 == 5)
		do_pb(temp, size);
	if (i % 12 == 6)
		do_ra(temp, size);
	if (i % 12 == 7)
		do_rb(temp, size);
	if (i % 12 == 8)
		do_rr(temp, size);
	if (i % 12 == 9)
		do_rra(temp, size);
	if (i % 12 == 10)
		do_rrb(temp, size);
	if (i % 12 == 11)
		do_rrr(temp, size);
	if (i / 12 > 0)
		try(temp, size, i / 12);
}

t_stack	copy_and_try(t_stack stack, int size, int i)
{
	t_stack	temp;

	temp = copy_stack(stack, size);
	try (temp, size, i);
	return (temp);
}
