/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:39:12 by chajeon           #+#    #+#             */
/*   Updated: 2024/03/20 15:06:28 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*get_read(int fd, char *backup);
char	*get_one(char *backup);
char	*set_next(char *backup);
void	*gnl_ft_calloc(size_t count, size_t size);
void	*free_null(char *str);
int		gnl_ft_strlen(char *str);
char	*gnl_ft_strjoin(char *str, char *add);
char	*gnl_ft_strrchr(const char *s, int c);

#endif