/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:23:42 by tdontos-          #+#    #+#             */
/*   Updated: 2018/12/11 16:57:52 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		save_next_line(char **arr, char **line, int fd)
{
	int		len;
	char	*tmp;

	if (arr[fd] == NULL)
		return (0);
	len = 0;
	while (arr[fd][len] != '\n' && arr[fd][len] != '\0')
		len++;
	if (arr[fd][len] == '\n')
	{
		tmp = ft_strdup(arr[fd] + len + 1);
		*line = ft_strsub(arr[fd], 0, len);
		free(arr[fd]);
		arr[fd] = tmp;
		if (arr[fd][0] == '\0')
			ft_strdel(&arr[fd]);
	}
	else if (arr[fd][len] == '\0')
	{
		*line = ft_strsub(arr[fd], 0, len);
		ft_strdel(&arr[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char static		*arr[255];
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*copy;

	if ((fd < 0 || read(fd, buf, 0) < 0) || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (arr[fd] == NULL)
			arr[fd] = ft_strnew(1);
		copy = ft_strjoin(arr[fd], buf);
		free(arr[fd]);
		arr[fd] = copy;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (save_next_line(arr, line, fd));
}
