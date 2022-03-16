/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rerotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:36:33 by swautele          #+#    #+#             */
/*   Updated: 2022/03/16 17:22:18 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra(t_stack stack, int size)
{
	int		i;
	ssize_t	temp;

	if (stack.a[0] == EMPTY)
		return ;
	i = 0;
	while (stack.a[i] != EMPTY && i < size - 1)
		i++;
	if (stack.a[i] == EMPTY)
	{
		i--;
		temp = stack.a[i];
	}
	else
		temp = stack.a[i];
	while (i > 0)
	{
		stack.a[i] = stack.a[i - 1];
		i--;
	}
	stack.a[0] = temp;
}

void	do_rrb(t_stack stack, int size)
{
	int		i;
	ssize_t	temp;

	if (stack.b[0] == EMPTY)
		return ;
	i = 0;
	while (stack.b[i] != EMPTY && i < size - 1)
		i++;
	if (stack.b[i] == EMPTY)
	{
		i--;
		temp = stack.b[i];
	}
	else
		temp = stack.b[i];
	while (i > 0)
	{
		stack.b[i] = stack.b[i - 1];
		i--;
	}
	stack.b[0] = temp;
}

void	do_rrr(t_stack stack, int size)
{
	do_rra(stack, size);
	do_rrb(stack, size);
}
