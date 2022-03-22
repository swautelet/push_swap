/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:04:26 by swautele          #+#    #+#             */
/*   Updated: 2022/03/22 20:25:22 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	firstdivide(t_stack stack, int size, t_lim limits, t_stack sorted)
{
	ssize_t	mina;
	int		i;

	mina = limits.mid - 1;
	while (mina < limits.mid && stack.a[2] != EMPTY)
	{
		i = -1;
		mina = stack.a[0];
		while (stack.a[++i] != EMPTY)
		{
			if (stack.a[i] < mina)
				mina = stack.a[i];
		}
		if (stack.a[0] > stack.a[1] && stack.a[0] < limits.mid
			&& stack.a[1] < limits.mid && stack.b[0] < stack.b[1])
		{
			do_ss(stack, size);
			write(1, "ss\n", 3);
		}
		if (stack.a[0] <= limits.mid && stack.a[2] != EMPTY)
		{
			do_pb(stack, size);
			write(1, "pb\n", 3);
		}
		else if (stack.a[0] > limits.mid && stack.a[2] != EMPTY)
		{
			do_ra(stack, size);
			write(1, "ra\n", 3);
		}
	}
	if (stack.a[2] != EMPTY)
	{
		limits.ipiv = (limits.ipiv + size) / 2;
		limits.mid = sorted.b[limits.ipiv];
		firstdivide(stack, size, limits, sorted);
		bigsort(stack, size, limits);
	}
}

// int	mini_stacka_issorted(t_stack stack, int size, t_lim limits)
// {
// 	int	i;

// 	i = 0;
// 	while (stack.a[i] != EMPTY && stack.a[i + 1] != EMPTY && i + 1 < size
// 		&& stack.a[i + 1] < limits.max)
// 	{
// 		if (stack.a[i] > stack.a[i + 1])
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// void	sort_stacka(t_stack stack, int size, t_lim limits)
// {
// 	if (stack.a[0] > stack.a[1])
// 	{
// 		do_sa(stack, size);
// 		write(1, "sa\n", 3);
// 	}
// 	if (mini_stacka_issorted(stack, size, limits) != 0)
// 	{
// 		do_ra(stack, size);
// 		write(1, "ra\n", 3);
// 		sort_stacka(stack, size, limits);
// 		if (stack.a[0] > stack.a[1])
// 		{
// 			do_sa(stack, size);
// 			write(1, "sa\n", 3);
// 		}
// 		do_rra(stack, size);
// 		write(1, "rra\n", 4);
// 		if (mini_stacka_issorted(stack, size, limits) != 0)
// 			sort_stacka(stack, size, limits);
// 	}
// }

void	bigsort(t_stack stack, int size, t_lim limits)
{
	int	lastb;
	int	lasta;

	lastb = 0;
	while (stack.b[lastb + 1] != EMPTY)
		lastb++;
	lasta = 0;
	while (stack.a[lasta + 1] != EMPTY)
		lasta++;
	while (stack.b[0] >= limits.mid || stack.b[lastb] >= limits.mid)
	{
		if (stack.b[lastb] > stack.b[0] && stack.b[lastb] < stack.a[lasta]
			&& stack.a[lasta] < stack.a[0])
		{
			do_rrr(stack, size);
			write(1, "rrr\n", 4);
		}
		else if (stack.b[0] < stack.b[1] && stack.b[0] > stack.a[0])
		{
			do_rr(stack, size);
			write(1, "rr\n", 3);
		}
		else if (stack.b[0] < stack.b[1] && stack.b[1] != EMPTY)
		{
			do_rb(stack, size);
			write(1, "rb\n", 3);
		}
		else if (stack.b[0] < stack.b[lastb] && stack.b[0] != EMPTY)
		{
			do_rrb(stack, size);
			write(1, "rrb\n", 4);
		}
		else if (stack.b[0] < stack.a[0] && stack.b[0] < stack.a[lasta]
			&& stack.a[lasta] < stack.a[0])
		{
			do_rra(stack, size);
			write(1, "rra\n", 4);
		}
		else if (stack.b[0] > stack.a[0])
		{
			do_ra(stack, size);
			write(1, "ra\n", 3);
		}
		else if (stack.b[0] < stack.a[0] && (stack.b[0] > stack.a[lasta]
				|| stack.a[0] < stack.a[lasta]))
		{
			do_pa(stack, size);
			write(1, "pa\n", 3);
			lastb--;
			lasta++;
		}
		else
			break ;
	}
}

// void	secondsort(t_stack stack, int size, t_lim limits)
// {
// 	ssize_t	last;
// 	int		lastb;

// 	limits.mid -= (limits.mid - limits.min) / 2;
// 	lastb = 0;
// 	while (stack.b[lastb + 1] != EMPTY)
// 		lastb++;
// 	last = stack.b[lastb];
// 	while (stack.b[0] != last)
// 	{
// 		if (stack.b[0] > limits.mid)
// 		{
// 			do_pa(stack, size);
// 			write(1, "pa\n", 3);
// 		}
// 		else
// 		{
// 			do_rb(stack, size);
// 			write(1, "rb\n", 3);
// 		}
// 	}
// 	if (stack.b[0] > limits.mid)
// 	{
// 		do_pa(stack, size);
// 		write(1, "pa\n", 3);
// 	}
// 	if ((limits.mid - limits.min) / 2 > 0)
// 	{
// 		sort_stacka(stack, size, limits);
// 		limits.mid -= (limits.mid - limits.min) / 2;
// 		secondsort(stack, size, limits);
// 	}
// }

t_stack	virtualsort(t_stack stack, int size, t_lim limits)
{
	t_stack	sorted;
	int		i;
	int		towr;

	sorted = copy_stack(stack, size);
	towr = 0;
	limits.mid = limits.min;
	sorted.b[towr] = limits.mid;
	while (limits.mid != limits.max)
	{
		limits.mid = limits.max;
		i = -1;
		while (++i < size)
		{
			if (sorted.a[i] < limits.mid && sorted.a[i] != EMPTY
				&& sorted.a[i] != limits.min)
				limits.mid = sorted.a[i];
		}
		i = -1;
		while (++i < size)
		{
			if (sorted.a[i] == limits.mid)
				sorted.a[i] = EMPTY;
		}
		towr++;
		sorted.b[towr] = limits.mid;
	}
	return (sorted);
}

void	sortbig(t_stack stack, int size)
{
	t_lim	limits;
	int		i;
	t_stack	sorted;

	i = -1;
	limits.min = stack.a[0];
	limits.max = stack.a[0];
	while (++i < size)
	{
		if (stack.a[i] < limits.min)
			limits.min = stack.a[i];
		if (stack.a[i] > limits.max)
			limits.max = stack.a[i];
	}
	sorted = virtualsort(stack, size, limits);
	limits.ipiv = size / 2;
	limits.mid = sorted.b[limits.ipiv];
	firstdivide(stack, size, limits, sorted);
	bigsort(stack, size, limits);
	while (limits.ipiv != 1)
	{
		limits.ipiv = limits.ipiv / 2;
		limits.mid = sorted.b[limits.ipiv];
		bigsort(stack, size, limits);
	}
	limits.mid = limits.min -1;
	bigsort(stack, size, limits);
	free (sorted.a);
	free (sorted.b);
}
