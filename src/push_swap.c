/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:58:51 by swautele          #+#    #+#             */
/*   Updated: 2022/03/17 13:37:27 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_stack(t_stack stack, char **argv, int argc)
{
	int		i;
	char	err;

	i = 0;
	while (++i <= argc - 1)
	{
		stack.a[i - 1] = ft_atoi(argv[i], &err);
		if (err == -1)
		{
			write(2, "Error\nA number is not an int", 29);
			return (-1);
		}
		stack.b[i - 1] = EMPTY;
	}
	return (0);
}

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
		if (check_error(stack.a, argc - 2) == 0)
			sort(stack, argc - 1);
	}
	free(stack.a);
	free(stack.b);
	return (0);
}
