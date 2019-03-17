/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:36:48 by tdontos-          #+#    #+#             */
/*   Updated: 2018/11/26 15:36:50 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*in;
	unsigned char	*out;

	in = (unsigned char *)src;
	out = (unsigned char *)dst;
	c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		out[i] = in[i];
		if (in[i] == c)
			return (&out[i + 1]);
		i++;
	}
	return (NULL);
}
