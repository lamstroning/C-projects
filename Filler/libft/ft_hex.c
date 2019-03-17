/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:12:08 by tdontos-          #+#    #+#             */
/*   Updated: 2019/01/12 18:12:11 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_hex(unsigned long long int o, char format)
{
	int		module[15];
	int		i;
	char	*hex;
	char	reg;
	int		j;

	j = 0;
	i = 0;
	if (o == 0)
		return (ft_strdup("0"));
	reg = format == 'X' ? 'A' : 'a';
	while (o != 0)
	{
		module[i++] = o % 16;
		o /= 16;
	}
	hex = ft_strnew(i + 1);
	if (hex == NULL)
		return (NULL);
	hex[i] = '\0';
	while (i > 0)
		hex[j++] = module[--i] > 9 ? module[i] - 10 + reg : module[i] + 48;
	return (hex);
}
