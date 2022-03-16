/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:58:51 by swautele          #+#    #+#             */
/*   Updated: 2022/03/16 14:51:06 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_stacka(int *stacka, char **argv, int argc)
{
	int		i;
	char	err;

	i = 0;
	while (++i <= argc - 2)
	{
		stacka[i] = ft_atoi(argv[i], &err);
		if (err == -1)
		{
			write(stderr, "Error\nA number is not an int", 29);
			return (-1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	*stacka;
	int	*stackb;

	if (argc <= 2)
		return (0);
	stacka = ft_calloc((argc - 1), sizeof(int));
	if (stacka == NULL)
	{
		write(stderr, "Error\nCan't allocate space", 27);
		exit (1);
	}
	stackb = ft_calloc((argc - 1), sizeof(int));
	if (stackb == NULL)
	{
		free (stacka);
		write(stderr, "Error\nCan't allocate space", 27);
		exit (1);
	}
	if (init_stacka(stacka, argv, argc) == 0)
	{
		check_error(stacka, argc - 2);
	}
	free(stacka);
	free(stackb);
	return (0);
}
