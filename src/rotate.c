/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:36:39 by swautele          #+#    #+#             */
/*   Updated: 2022/03/16 17:13:20 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_stack stack, int size)
{
	ssize_t	temp;
	int		i;

	if (stack.a[0] == EMPTY)
		return ;
	i = -1;
	temp = stack.a[0];
	while (stack.a[++i] != EMPTY && i < size - 1)
	{
		stack.a[i] = stack.a[i + 1];
	}
	stack.a[i] = temp;
}

void	do_rb(t_stack stack, int size)
{
	ssize_t	temp;
	int		i;

	if (stack.b[0] == EMPTY)
		return ;
	i = -1;
	temp = stack.b[0];
	while (stack.b[++i] != EMPTY && i < size - 1)
	{
		stack.b[i] = stack.b[i + 1];
	}
	stack.b[i] = temp;
}

void	do_rr(t_stack stack, int size)
{
	do_ra(stack, size);
	do_rb(stack, size);
}