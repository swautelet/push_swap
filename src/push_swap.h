/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:58:48 by swautele          #+#    #+#             */
/*   Updated: 2022/03/22 18:28:35 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# define EMPTY LONG_MIN

typedef struct s_stack{
	ssize_t	*a;
	ssize_t	*b;
}	t_stack;

typedef struct s_lim{
	ssize_t	mid;
	ssize_t	min;
	ssize_t	max;
	int		ipiv;
}	t_lim;

int		check_error(ssize_t *stacka, int size);
void	sort(t_stack stack, int size);
int		issorted(t_stack stack, int size);
int		sortlittle(t_stack stack, int size, int i);
void	do_sa(t_stack stack, int size);
void	do_sb(t_stack stack, int size);
void	do_ss(t_stack stack, int size);
void	do_pa(t_stack stack, int size);
void	do_pb(t_stack stack, int size);
void	do_ra(t_stack stack, int size);
void	do_rb(t_stack stack, int size);
void	do_rr(t_stack stack, int size);
void	do_rra(t_stack stack, int size);
void	do_rrb(t_stack stack, int size);
void	do_rrr(t_stack stack, int size);
t_stack	copy_stack(t_stack stack, int size);
t_stack	copy_and_try(t_stack stack, int size, int i);
void	try(t_stack temp, int size, int i);
void	sortbig(t_stack stack, int size);
void	bigsort(t_stack stack, int size, t_lim limits);
void	sort_stacka(t_stack stack, int size, t_lim limits);
void	firstdivide(t_stack stack, int size, t_lim limits, t_stack sorted);
void	secondsort(t_stack stack, int size, t_lim limits);
int		mini_stacka_issorted(t_stack stack, int size, t_lim limits);
t_stack	virtualsort(t_stack stack, int size, t_lim limits);
void	very_big_sort(t_stack stack, int size);
void	convertstack(t_stack stack, int size, t_stack sorted);

#endif
