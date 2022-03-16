/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:32:23 by swautele          #+#    #+#             */
/*   Updated: 2022/03/16 17:09:02 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_stack stack, int size)
{
	size_t	temp;

	if (stack.a[0] == EMPTY || stack.a[1] == EMPTY)
		return ;
	temp = stack.a[0];
	stack.a[0] = stack.a[1];
	stack.a[1] = temp;
}

void	do_sb(t_stack stack, int size)
{
	size_t	temp;

	if (stack.b[0] == EMPTY || stack.b[1] == EMPTY)
		return ;
	temp = stack.b[0];
	stack.b[0] = stack.b[1];
	stack.b[1] = temp;
}

void	do_ss(t_stack stack, int size)
{
	do_sa(stack, size);
	do_sb(stack, size);
}
