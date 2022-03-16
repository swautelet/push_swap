/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:36:19 by swautele          #+#    #+#             */
/*   Updated: 2022/03/16 17:07:20 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pa(t_stack stack, int size)
{
	int		i;

	if (stack.b[0] == EMPTY)
		return ;
	i = 0;
	while (stack.a[i] != EMPTY && i < size)
		i++;
	while (i > 0)
	{
		stack.a[i] = stack.a[i - 1];
		i--;
	}
	stack.a[0] = stack.b[0];
	while (stack.b[i] != EMPTY && i + 1 < size)
	{
		stack.b[i] = stack.b[i + 1];
		i++;
	}
}

void	do_pb(t_stack stack, int size)
{
	int		i;

	if (stack.a[0] == EMPTY)
		return ;
	i = 0;
	while (stack.b[i] != EMPTY && i < size)
		i++;
	while (i > 0)
	{
		stack.b[i] = stack.b[i - 1];
		i--;
	}
	stack.b[0] = stack.a[0];
	while (stack.a[i] != EMPTY && i + 1 < size)
	{
		stack.a[i] = stack.a[i + 1];
		i++;
	}
}
