/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:23:51 by tdontos-          #+#    #+#             */
/*   Updated: 2018/12/01 13:23:53 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		end;
	char	*arr;

	if (s == NULL)
		return (NULL);
	end = ft_strlen(s) - 1;
	i = 0;
	while (s[i] == 32 || s[i] == 9 || s[i] == 10)
		i++;
	if (s[i] == '\0')
		return (ft_strnew(1));
	while (s[end] == 32 || s[end] == 9 || s[end] == 10)
		end--;
	arr = (char *)malloc(sizeof(char) * (end - i + 2));
	if (arr == NULL)
		return (NULL);
	arr = ft_strncpy(arr, &s[i], end - i + 1);
	arr[end - i + 1] = '\0';
	return (arr);
}
