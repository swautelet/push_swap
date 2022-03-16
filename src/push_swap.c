/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:58:51 by swautele          #+#    #+#             */
/*   Updated: 2022/03/16 14:18:48 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stacka(int *stacka, char **argv, int argc)
{
	int	i;

	i = 0;
	while (++i <= argc - 1)
	{
		stacka[i] = ft_atoi(argv[i]);
	}
}

int	main(int argc, char **argv)
{
	int	*stacka;
	int	*stackb;

	if (argc <= 2)
		return (0);
	stacka = ft_calloc((argc - 1), sizeof(int));
	stackb = ft_calloc((argc - 1), sizeof(int));
	if (stacka == NULL || stackb == NULL)
		exit (1);
	init_stacka(stacka, argv, argc);
	free(stacka);
	free(stackb);
}
