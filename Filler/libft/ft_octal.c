/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 19:28:18 by tdontos-          #+#    #+#             */
/*   Updated: 2019/01/13 13:49:06 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_octal(unsigned long long int o)
{
	int		module[21];
	int		i;
	char	*str;
	int		j;

	j = 1;
	i = 0;
	while (o > 7)
	{
		module[i++] = o % 8;
		o /= 8;
	}
	if (!(str = malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i + 1] = '\0';
	str[0] = o + 48;
	while (i > 0)
		str[j++] = module[--i] + 48;
	return (str);
}
