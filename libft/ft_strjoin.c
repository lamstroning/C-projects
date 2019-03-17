/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:48:43 by tdontos-          #+#    #+#             */
/*   Updated: 2018/11/30 15:48:48 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*arr;
	unsigned int	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	arr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (arr == NULL)
		return (NULL);
	while (*s1)
		arr[i++] = *s1++;
	while (*s2)
		arr[i++] = *s2++;
	arr[i] = '\0';
	return (arr);
}
