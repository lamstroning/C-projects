/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:55:31 by tdontos-          #+#    #+#             */
/*   Updated: 2018/11/28 14:55:33 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*arr;
	int		ch;

	c = (unsigned char)c;
	ch = -1;
	arr = (char*)str;
	i = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] == c)
			ch = i;
		i++;
	}
	if (ch != -1)
		return (&arr[ch]);
	else if (c == 0)
		return (&arr[i]);
	return (NULL);
}
