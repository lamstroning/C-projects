/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnchr_e.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:36:01 by tdontos-          #+#    #+#             */
/*   Updated: 2019/02/24 13:36:05 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addnchr_e(char *str, char c, int cont)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	if (str == NULL)
	{
		tmp = ft_strnew(cont);
		while (++i < cont)
			tmp[i] = c;
		return (tmp);
	}
	j = ft_strlen(str);
	tmp = ft_strdup(str);
	while (++i < cont)
		tmp[j++] = c;
	return (tmp);
}
