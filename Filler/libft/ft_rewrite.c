/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rewrite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:31:39 by tdontos-          #+#    #+#             */
/*   Updated: 2019/02/09 12:31:35 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rewrite(char **str, char *src)
{
	if (src == NULL)
		return ;
	if (!str || !*str)
		free(str);
	*str = ft_strdup(src);
	if (!src)
		free(src);
}
