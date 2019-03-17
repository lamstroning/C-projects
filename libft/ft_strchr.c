/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:32:28 by tdontos-          #+#    #+#             */
/*   Updated: 2018/11/28 14:33:47 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*arr;

	c = (unsigned char)c;
	arr = (char*)str;
	i = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] == c)
			return (&arr[i]);
		i++;
	}
	if (c == 0)
		return (&arr[i]);
	return (NULL);
}
