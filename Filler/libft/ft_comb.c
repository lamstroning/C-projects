/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:58:50 by tdontos-          #+#    #+#             */
/*   Updated: 2019/02/13 19:03:18 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_comb(char **src, char **dst)
{
	char *tmp;

	if (src == NULL || dst == NULL)
		return (NULL);
	tmp = ft_strjoin(*src, *dst);
	ft_strdel(src);
	ft_strdel(dst);
	return (tmp);
}
