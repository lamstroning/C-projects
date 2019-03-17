/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:48:06 by tdontos-          #+#    #+#             */
/*   Updated: 2018/11/30 13:49:22 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*arr;

	if (s == NULL || f == NULL)
		return (NULL);
	arr = (char*)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (arr == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		arr[i] = f(i, s[i]);
	arr[i] = '\0';
	return (arr);
}
