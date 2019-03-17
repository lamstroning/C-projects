/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:53:17 by tdontos-          #+#    #+#             */
/*   Updated: 2019/01/06 13:53:21 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **begin_list, t_list *new)
{
	t_list *current;

	current = *begin_list;
	if (current == NULL)
		*begin_list = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
}
