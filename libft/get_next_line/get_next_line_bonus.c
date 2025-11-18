/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:52:02 by chajeon           #+#    #+#             */
/*   Updated: 2024/01/10 11:03:45 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/get_next_line_bonus.h"

char	*get_read(int fd, char *backup)
{
	char	*buf;
	int		check;

	buf = gnl_ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buf)
		return (NULL);
	if (!backup)
		backup = gnl_ft_calloc(1, 1);
	check = 1;
	while (check > 0)
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check == -1)
		{
			buf = free_null(buf);
			backup = free_null(backup);
			return (NULL);
		}
		buf[check] = '\0';
		backup = gnl_ft_strjoin(backup, buf);
		if (gnl_ft_strrchr(backup, '\n'))
			break ;
	}
	buf = free_null(buf);
	return (backup);
}

char	*get_one(char *backup)
{
	int		i;
	char	*res;

	i = 0;
	if (!backup[i])
		return (NULL);
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	if (backup[i] == '\n')
		res = gnl_ft_calloc(i + 2, 1);
	else
		res = gnl_ft_calloc(i + 1, 1);
	i = 0;
	while (backup[i] != '\n' && backup[i] != '\0')
	{
		res[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
		res[i] = backup[i];
	return (res);
}

char	*set_next(char *backup)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	if (backup[i] == '\0')
		return (free_null(backup));
	temp = gnl_ft_calloc(gnl_ft_strlen(backup) - i, 1);
	i++;
	j = 0;
	while (backup[i] != '\0')
		temp[j++] = backup[i++];
	backup = free_null(backup);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*backup[1024];
	char		*oneline;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	backup[fd] = get_read(fd, backup[fd]);
	if (!backup[fd])
		return (NULL);
	oneline = get_one(backup[fd]);
	backup[fd] = set_next(backup[fd]);
	return (oneline);
}
