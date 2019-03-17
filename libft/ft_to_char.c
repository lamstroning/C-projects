/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:44:07 by tdontos-          #+#    #+#             */
/*   Updated: 2019/01/13 15:09:47 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_to_char(int num)
{
	char	*str;
	int		module[15];
	int		i;

	i = 0;
	if (num == 0)
		return ("0");
	while (num > 0)
	{
		module[i++] = num % 10;
		num /= 10;
	}
	str = malloc(sizeof(char) * i);
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i] = module[i] + '0';
		i--;
	}
	return (str);
}
