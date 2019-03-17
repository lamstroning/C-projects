/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:49:34 by tdontos-          #+#    #+#             */
/*   Updated: 2019/01/14 14:49:37 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_ndigits(unsigned long long int num)
{
	int c;

	c = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / 10;
		c++;
	}
	return (c);
}

char		*ft_unitoa(unsigned long long int n)
{
	int		digits;
	char	*ret;

	digits = get_ndigits(n);
	if (!(ret = ft_strnew((size_t)(digits))))
		return (ret);
	else if (n > 0)
		digits--;
	else
		ret[0] = '0';
	while (n)
	{
		if (n > 0)
			ret[digits] = '0' + (n % 10);
		else
			ret[digits] = '0' + -(n % 10);
		n = n / 10;
		digits--;
	}
	return (ret);
}
