/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 19:13:15 by tdontos-          #+#    #+#             */
/*   Updated: 2019/03/04 19:13:18 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_upstr(char **str)
{
	int		i;
	char	*tmp;

	i = -1;
	if (str == NULL || *str == NULL)
		return ;
	tmp = ft_strnew(ft_strlen(*str) + 1);
	while ((*str)[++i] != '\0')
		tmp[i] = ft_toupper((*str)[i]);
	ft_rewrite(str, tmp);
}
