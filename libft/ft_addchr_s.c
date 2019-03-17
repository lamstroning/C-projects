/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchr_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:40:29 by tdontos-          #+#    #+#             */
/*   Updated: 2019/02/10 16:40:30 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addchr_s(char *str, char c)
{
	char	*tmp;
	char	*buf;
	int		i;

	if (str == NULL)
		return (NULL);
	i = ft_strlen(str);
	tmp = ft_strnew(i + 1);
	tmp[0] = c;
	buf = ft_strcpy(&tmp[1], str);
	tmp[i + 1] = '\0';
	return (tmp);
}
