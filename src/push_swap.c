/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:58:51 by swautele          #+#    #+#             */
/*   Updated: 2022/03/23 18:07:00 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc <= 2)
		return (0);
	stack.a = ft_calloc((argc - 1), sizeof(ssize_t));
	if (stack.a == NULL)
	{
		write(2, "Error\nCan't allocate space", 27);
		exit (1);
	}
	stack.b = ft_calloc((argc - 1), sizeof(ssize_t));
	if (stack.b == NULL)
	{
		free (stack.a);
		write(2, "Error\nCan't allocate space", 27);
		exit (1);
	}
	if (init_stack(stack, argv, argc) == 0)
	{
		if (check_error(stack.a, argc - 1) == 0)
			sort(stack, argc - 1);
	}
	free(stack.a);
	free(stack.b);
	return (0);
}
