/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:43:12 by tdontos-          #+#    #+#             */
/*   Updated: 2018/11/28 15:54:45 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	if (str2[j] == '\0')
		return ((char *)str1);
	while (str1[i] != '\0' && i < len)
	{
		if (str1[i] == str2[j])
		{
			while (str1[i] == str2[j] && str1[i] != '\0' && i < len)
			{
				j++;
				i++;
			}
			if (str2[j] == '\0')
				return ((char *)&str1[i - j]);
			i = i - j;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
