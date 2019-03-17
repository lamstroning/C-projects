/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 16:14:22 by tdontos-          #+#    #+#             */
/*   Updated: 2019/01/19 13:30:06 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_float_itoa(int prec, long double n)
{
	char	*doab;
	int		i;
	char	*tmp;

	i = 0;
	if (!(doab = ft_strnew(ft_strlen(ft_itoa((int)n)) + prec + 1)))
		return (NULL);
	tmp = ft_itoa((int)n);
	doab = ft_strcpy(doab, tmp);
	free(tmp);
	i = ft_strlen(doab);
	if (prec > 0)
		doab[i] = '.';
	n -= (int)n;
	while (--prec >= 0)
	{
		n = (n * 10) - ((int)n * 10);
		doab[++i] = n + '0';
	}
	return (doab);
}
