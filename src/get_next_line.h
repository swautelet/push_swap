/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:01:20 by simonwautel       #+#    #+#             */
/*   Updated: 2022/03/23 14:56:21 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# if BUFFER_SIZE < -1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE -1
# endif
# if BUFFER_SIZE > 2147483646
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 2147483646
# endif

char	*get_next_line(int fd);
char	*ft_straddback(char *result, char *buffer, ssize_t size);
size_t	ft_strlengnl(char *str);
int		ft_end_of_line(char *str);
char	*ft_initialize(char *buffer);
char	*gnl(char *result, char *buffer, int size, int fd);
void	ft_straddback2(char *newresult, char *buffer, ssize_t i, ssize_t size);

#endif
