/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:02:37 by tdontos-          #+#    #+#             */
/*   Updated: 2018/11/28 15:02:38 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i] == needle[j] && haystack[i] != '\0')
			{
				j++;
				i++;
			}
			if (needle[j] == '\0')
				return ((char *)&haystack[i - j]);
			i = i - j;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
