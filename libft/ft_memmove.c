/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:02:37 by tdontos-          #+#    #+#             */
/*   Updated: 2018/11/26 16:02:39 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *in;
	unsigned char *out;

	in = (unsigned char *)src;
	out = (unsigned char *)dst;
	if (out <= in || out >= (in + len))
	{
		while (len--)
			*out++ = *in++;
	}
	else
	{
		out += len - 1;
		in += len - 1;
		while (len--)
			*out-- = *in--;
	}
	return (dst);
}
