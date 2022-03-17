/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:58:48 by swautele          #+#    #+#             */
/*   Updated: 2022/03/17 15:49:54 by swautele         ###   ########.fr       */
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
# define EMPTY LONG_MAX

typedef struct s_stack{
	ssize_t	*a;
	ssize_t	*b;
}	t_stack;

int		check_error(ssize_t *stacka, int imax);
void	sort(t_stack stack, int size);
int		issorted(t_stack stack, int imax);
int		sortlittle(t_stack stack, int size);
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
t_stack	copy_and_try(t_stack stack, int size, size_t i);
void	try(t_stack temp, int size, size_t i);

#endif
