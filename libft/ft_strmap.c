/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:09:39 by tdontos-          #+#    #+#             */
/*   Updated: 2018/11/30 13:09:41 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		arr[i] = f(s[i]);
	arr[i] = '\0';
	return (arr);
}
