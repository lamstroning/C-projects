/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchr_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:40:25 by tdontos-          #+#    #+#             */
/*   Updated: 2019/02/10 16:40:26 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addchr_e(char *str, char c)
{
	char	*tmp;
	int		i;

	if (str == NULL)
	{
		str = ft_strnew(1);
		str[0] = c;
		return (str);
	}
	i = ft_strlen(str);
	tmp = ft_strdup(str);
	tmp[i] = c;
	tmp[i + 1] = '\0';
	return (tmp);
}
