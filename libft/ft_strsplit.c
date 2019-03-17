/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:59:30 by tdontos-          #+#    #+#             */
/*   Updated: 2018/12/01 11:59:31 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cont_words(const char *s, char c)
{
	int		cnt;
	int		flag;

	flag = 0;
	cnt = 0;
	while (*s)
	{
		if (flag == 1 && *s == c)
			flag = 0;
		if (flag == 0 && *s != c)
		{
			flag = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static int		count_letter(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		words;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	words = cont_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (cont_words(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	while (words--)
	{
		while (*s == c && *s)
			s++;
		arr[i] = ft_strsub(s, 0, count_letter(s, c));
		if (arr[i] == NULL)
			return (NULL);
		s = s + count_letter(s, c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
