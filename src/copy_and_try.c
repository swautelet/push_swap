/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_and_try.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:50:19 by swautele          #+#    #+#             */
/*   Updated: 2022/03/17 15:15:08 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	copy_stack(t_stack stack, int size)
{
	t_stack	temp;
	int		i;

	temp.a = ft_calloc((size), sizeof(ssize_t));
	if (temp.a == NULL)
	{
		write(2, "Error\nCan't allocate space", 27);
		exit (1);
	}
	temp.b = ft_calloc((size), sizeof(ssize_t));
	if (temp.b == NULL)
	{
		free (temp.a);
		write(2, "Error\nCan't allocate space", 27);
		exit (1);
	}
	i = -1;
	while (++i < size)
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
	// int	j;

	temp = copy_stack(stack, size);
	try (temp, size, i);
	// j = -1;
	// while (++j <= 3)
	// {
		// printf("stack.a[%d] = %zd	stack.b[%d] = %zd\n", j, temp.a[j], j, temp.b[j]);
	// }
	return (temp);
}
