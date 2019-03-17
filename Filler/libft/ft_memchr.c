/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:48:31 by tdontos-          #+#    #+#             */
/*   Updated: 2018/11/26 16:48:45 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*arr;

	arr = (unsigned char*)s;
	i = 0;
	c = (unsigned char)c;
	while (i < n)
	{
		if (arr[i] == c)
			return (&arr[i]);
		i++;
	}
	return (NULL);
}
