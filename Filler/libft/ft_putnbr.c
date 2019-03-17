/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 12:53:11 by tdontos-          #+#    #+#             */
/*   Updated: 2018/11/25 12:59:11 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	unsigned int	num;

	if (nb < 0)
	{
		ft_putchar('-');
		num = nb * -1;
	}
	else
		num = nb;
	if (num >= 10)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + 48);
}
