/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:33:22 by swautele          #+#    #+#             */
/*   Updated: 2022/03/23 18:05:49 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(ssize_t *stacka, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < i)
		{
			if (stacka[i] == stacka[j])
			{
				write(2, "Error\nThere's a double", 23);
				return (-1);
			}
		}
	}
	return (0);
}
