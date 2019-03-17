/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnchr_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:35:55 by tdontos-          #+#    #+#             */
/*   Updated: 2019/02/24 13:35:57 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addnchr_s(char *str, char c, int cont)
{
	char	*tmp;
	char	*buf;
	int		i;

	i = -1;
	if (str == NULL)
	{
		tmp = ft_strnew(cont);
		while (++i < cont)
			tmp[i] = c;
		return (tmp);
	}
	tmp = ft_strnew(cont);
	buf = ft_strdup(str);
	while (++i < cont)
		tmp[i] = c;
	return (ft_comb(&tmp, &buf));
}
