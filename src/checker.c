/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:31:25 by swautele          #+#    #+#             */
/*   Updated: 2022/03/23 13:37:16 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_on_stack(t_stack stack, int size, char buffer[10])
{
	if (ft_strncmp(buffer, "sa\n", 3) == 0)
		do_sa(stack, size);
	else if (ft_strncmp(buffer, "sb\n", 3) == 0)
		do_sb(stack, size);
	else if (ft_strncmp(buffer, "ss\n", 3) == 0)
		do_ss(stack, size);
	else if (ft_strncmp(buffer, "pa\n", 3) == 0)
		do_pa(stack, size);
	else if (ft_strncmp(buffer, "pb\n", 3) == 0)
		do_pb(stack, size);
	else if (ft_strncmp(buffer, "ra\n", 3) == 0)
		do_ra(stack, size);
	else if (ft_strncmp(buffer, "rb\n", 3) == 0)
		do_rb(stack, size);
	else if (ft_strncmp(buffer, "rr\n", 3) == 0)
		do_rr(stack, size);
	else if (ft_strncmp(buffer, "rra\n", 4) == 0)
		do_rra(stack, size);
	else if (ft_strncmp(buffer, "rrb\n", 4) == 0)
		do_rrb(stack, size);
	else if (ft_strncmp(buffer, "rrr\n", 4) == 0)
		do_rrr(stack, size);
	else
		return (1);
	return (0);
}

static void	read_and_do(t_stack stack, int size)
{
	int		len;
	char	buffer[10];

	len = 1;
	while (len)
	{
		len = read(0, buffer, len);
		if (do_on_stack(stack, size, buffer) != 0)
		{
			write (1, "Error\n", 6);
			break ;
		}
	}
	if (issorted(stack, size) == 0)
		write(1, "ok\n", 3);
	else
		write(1, "ko\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc <= 2)
		return (0);
	stack.a = ft_calloc((argc - 1), sizeof(ssize_t));
	if (stack.a == NULL)
	{
		write(1, "Error\nCan't allocate space", 27);
		exit (1);
	}
	stack.b = ft_calloc((argc - 1), sizeof(ssize_t));
	if (stack.b == NULL)
	{
		free (stack.a);
		write(1, "Error\nCan't allocate space", 27);
		exit (1);
	}
	if (init_stack(stack, argv, argc) == 0)
	{
		if (check_error(stack.a, argc - 2) == 0)
			read_and_do(stack, argc - 1);
	}
	free(stack.a);
	free(stack.b);
	return (0);
}
