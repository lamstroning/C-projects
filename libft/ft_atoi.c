/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 09:41:54 by tdontos-          #+#    #+#             */
/*   Updated: 2019/02/23 12:35:49 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		atio_forbidden(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int				ft_atoi(char const *str)
{
	int		neg;
	int		res;

	res = 0;
	while (atio_forbidden(*str))
		str++;
	neg = (*str == '-') ? -1 : 1;
	str = (*str == '+' || *str == '-') ? str + 1 : str;
	while (ft_isdigit(*str))
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (res *= neg);
}
