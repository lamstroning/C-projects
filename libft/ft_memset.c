/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:43:16 by tdontos-          #+#    #+#             */
/*   Updated: 2018/11/26 12:47:57 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*arr;

	arr = (unsigned char *)b;
	c = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		arr[i] = c;
		i++;
	}
	return (arr);
}
