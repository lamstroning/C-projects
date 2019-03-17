/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tokn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:09:48 by tdontos-          #+#    #+#             */
/*   Updated: 2019/02/23 17:09:56 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_area(t_map *conf, t_tokn *tokn, int row)
{
	char	**cell;
	int		i;
	int		sym;
	int		put;

	put = 0;
	if (tokn->size[0] + row > conf->size[0])
		return (0);
	i = -1;
	sym = 0;
	conf->pos[0] = row;
	conf->pos[1] = conf->way[1] == 1 ? conf->size[1] - tokn->size[1] : 0;
	ft_makemtrx(&cell, tokn->size[0] + 1);
	while (++i < tokn->size[0])
	{
		cell[i] = ft_strdup(conf->map[row++]);
		sym += ft_chr_rep(cell[i], conf->my);
		put += ft_chr_rep(cell[i], '.');
	}
	if (sym == 0 || put < tokn->put - 1)
	{
		ft_delmtrx(&cell);
		return (0);
	}
	return (put_tokn(&cell, tokn, conf));
}

int		put_tokn(char ***area, t_tokn *tokn, t_map *conf)
{
	int		i;
	int		j;
	int		eq;

	i = -1;
	j = -1;
	eq = 0;
	while (++i < tokn->size[0])
	{
		eq += check_cell(tokn, conf, area[0][i], i);
		if (i + 1 >= tokn->size[0] && eq != 1)
		{
			trim_area(&area[0], tokn->size[0], conf);
			if ((int)ft_strlen(area[0][0]) < tokn->size[1])
			{
				ft_delmtrx(area);
				return (0);
			}
			i = -1;
			eq = 0;
		}
		j = -1;
	}
	ft_delmtrx(area);
	return (eq == 1 ? 1 : 0);
}

void	trim_area(char ***area, int row, t_map *conf)
{
	char	**tmp;
	int		i;
	int		len;

	i = -1;
	tmp = NULL;
	tmp = (char **)malloc(sizeof(char **) * row - 1);
	len = ft_strlen(**area);
	while (++i < row)
	{
		if (conf->way[1] == 1)
			tmp[i] = ft_strsub(area[0][i], 0, len - 1);
		else
			tmp[i] = ft_strdup(&area[0][i][1]);
		ft_strdel(&area[0][i]);
		area[0][i] = ft_strdup(tmp[i]);
		ft_strdel(&tmp[i]);
	}
	free(tmp);
	conf->pos[1] = conf->way[1] == 1 ? conf->pos[1] - 1 : conf->pos[1] + 1;
}

void	ft_delmtrx(char ***mtrx)
{
	int		i;

	i = -1;
	if (!mtrx || !*mtrx || !**mtrx)
		return ;
	while (mtrx[0][++i])
	{
		free(mtrx[0][i]);
		mtrx[0][i] = NULL;
	}
	free(*mtrx);
}

int		check_cell(t_tokn *tokn, t_map *conf, char *cell, int i)
{
	int		j;
	char	*tmp;
	int		len;
	int		eq;

	eq = 0;
	len = (int)ft_strlen(cell) - tokn->size[1];
	if (conf->way[1] == 1)
		tmp = ft_strsub(cell, len, tokn->size[1]);
	else
		tmp = ft_strsub(cell, 0, tokn->size[1]);
	j = -1;
	while (++j < tokn->size[1])
	{
		if (tokn->form[i][j] == '*' && tmp[j] != conf->my && tmp[j] != '.')
		{
			ft_strdel(&tmp);
			return (2);
		}
		if (tokn->form[i][j] == '*' && tmp[j] == conf->my)
			eq++;
	}
	ft_strdel(&tmp);
	return (eq);
}
