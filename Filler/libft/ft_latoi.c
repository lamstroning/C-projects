/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_latoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:45:26 by tdontos-          #+#    #+#             */
/*   Updated: 2019/01/12 14:45:33 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int					atio_forbidden(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

long long int				ft_latoi(char const *str)
{
	int					neg;
	long long int		res;

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
