/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 19:13:05 by tdontos-          #+#    #+#             */
/*   Updated: 2019/03/04 19:13:07 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lowstr(char **str)
{
	int		i;
	char	*tmp;

	i = -1;
	if (str == NULL || *str == NULL)
		return ;
	tmp = ft_strnew(ft_strlen(*str) + 1);
	while ((*str)[++i] != '\0')
		tmp[i] = ft_tolower((*str)[i]);
	ft_rewrite(str, tmp);
}
