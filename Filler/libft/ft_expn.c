/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:53:53 by tdontos-          #+#    #+#             */
/*   Updated: 2019/01/14 11:54:03 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float	ft_expn_period(char *expn, long double e)
{
	int		i;

	i = 0;
	expn[9] = '+';
	while (e > 10)
	{
		e /= 10;
		i++;
	}
	if (i >= 10)
	{
		expn[10] = i / 10 + 48;
		i /= 10;
	}
	else
		expn[10] = '0';
	expn[11] = i + 48;
	return (e);
}

char			*ft_expn(long double e, int format)
{
	char	*expn;
	int		i;
	int		j;

	j = 0;
	i = 2;
	expn = malloc(sizeof(char) * 13);
	e = ft_expn_period(&expn[0], e);
	expn[0] = e + 48;
	expn[1] = '.';
	expn[13] = '\0';
	while (i <= 8)
	{
		j = (int)e * 10;
		e = (e * 10) - j;
		expn[i++] = e + '0';
	}
	expn[8] = format == 0 ? 'E' : 'e';
	return (expn);
}
