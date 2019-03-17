/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makemtrx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:04:03 by tdontos-          #+#    #+#             */
/*   Updated: 2019/02/26 20:05:13 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_makemtrx(char ***mtrx, int size)
{
	int i;

	i = -1;
	*mtrx = (char **)malloc(sizeof(char **) * size + 1);
	while (++i < size)
		mtrx[0][i] = NULL;
	return ;
}
