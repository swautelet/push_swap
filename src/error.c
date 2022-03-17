/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:33:22 by swautele          #+#    #+#             */
/*   Updated: 2022/03/17 13:37:36 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(ssize_t *stacka, int imax)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= imax)
	{
		j = -1;
		while (++j < i)
		{
			if (stacka[i] == stacka[j])
				return (-1);
		}
	}
	return (0);
}
