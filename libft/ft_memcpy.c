/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:28:04 by tdontos-          #+#    #+#             */
/*   Updated: 2018/11/26 14:28:22 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *in;
	unsigned char *out;

	in = (unsigned char *)src;
	out = (unsigned char *)dst;
	while (n--)
		*out++ = *in++;
	return (dst);
}
