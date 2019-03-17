/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tokn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:57:46 by tdontos-          #+#    #+#             */
/*   Updated: 2019/02/23 13:58:13 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	measure_tokn(t_tokn *tokn, t_map *conf)
{
	int	row;

	search_way(conf, conf->size[0], conf->size[1]);
	row = conf->way[0] == 1 ? conf->low : 0;
	if (conf->low > conf->size[0] - tokn->size[0])
		conf->low -= tokn->size[0];
	while (1)
	{
		if (check_area(conf, tokn, row))
		{
			next_step(conf, tokn, 1);
			return ;
		}
		if ((row + tokn->size[0]) >= conf->size[1] - 1)
		{
			if (conf->way[0] == 1)
			{
				row = 0;
				conf->way[0] = 0;
			}
			if ((row + tokn->size[0]) >= conf->size[1] - 1)
				next_step(conf, tokn, 0);
		}
		row++;
	}
}

void	next_step(t_map *conf, t_tokn *tokn, int end)
{
	if (end == 0)
	{
		conf->pos[0] = 0;
		conf->pos[1] = 0;
	}
	ft_putnbr(conf->pos[0]);
	ft_putchar(' ');
	ft_putnbr(conf->pos[1]);
	ft_putchar('\n');
	reload_step(conf, tokn);
	if (end == 0)
		exit(1);
}

void	search_way(t_map *conf, int y, int x)
{
	int		i;
	char	*tmp;
	int		way[4];

	i = 4;
	while (--i >= 0)
		way[i] = 0;
	while (++i < y)
	{
		tmp = ft_strnew(x / 2);
		tmp = ft_strncpy(tmp, conf->map[i], x / 2);
		if (i <= y / 2)
		{
			way[1] += ft_chr_rep(&conf->map[i][x / 2], conf->op);
			way[0] += ft_chr_rep(tmp, conf->op);
		}
		else
		{
			way[3] += ft_chr_rep(&conf->map[i][x / 2], conf->op);
			way[2] += ft_chr_rep(tmp, conf->op);
		}
		ft_strdel(&tmp);
	}
	conf->way[0] = way[0] + way[1] > way[2] + way[3] ? 0 : 1;
	conf->way[1] = way[0] + way[2] > way[3] + way[1] ? 0 : 1;
}

void	reload_step(t_map *conf, t_tokn *tokn)
{
	int		i;

	i = -1;
	while (++i < conf->size[0])
	{
		free(conf->map[i]);
		conf->map[i] = NULL;
	}
	i = -1;
	while (++i < tokn->size[0])
	{
		free(tokn->form[i]);
		tokn->form[i] = NULL;
	}
	free(tokn->form);
	tokn->put = 0;
}
