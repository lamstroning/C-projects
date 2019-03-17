/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:26:54 by tdontos-          #+#    #+#             */
/*   Updated: 2019/02/18 17:26:56 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_map(t_map *conf, char *line)
{
	int		i;

	i = -1;
	while (get_next_line(FD, &line))
	{
		if (ft_strstr(line, "0123"))
			break ;
	}
	ft_strdel(&line);
	while (++i < conf->size[0])
	{
		get_next_line(FD, &line);
		conf->map[i] = ft_strdup(line + 4);
		if (ft_strchr(conf->map[i], conf->my) != NULL)
			conf->low = i;
		ft_strdel(&line);
	}
}

void	read_param(t_map *conf, char *line)
{
	char	*tmp;

	if (get_next_line(FD, &line) > 0)
	{
		conf->my = line[10] == '1' ? 'O' : 'X';
		conf->op = conf->my == 'O' ? 'X' : 'O';
	}
	ft_strdel(&line);
	while (get_next_line(FD, &line) > 0)
	{
		if ((tmp = ft_strstr(line, "Plateau ")))
			break ;
		ft_strdel(&line);
	}
	tmp = ft_strstr(tmp, " ");
	conf->size[0] = ft_atoi(++tmp);
	tmp = ft_strstr(tmp, " ");
	conf->size[1] = ft_atoi(tmp);
	conf->pos[0] = 0;
	conf->pos[1] = 0;
	conf->map = (char **)malloc(sizeof(char **) * conf->size[1]);
	ft_strdel(&line);
}

void	read_tokn(t_tokn *tokn, char *line)
{
	char	*tmp;

	while (get_next_line(FD, &line))
	{
		if (ft_strstr(line, "Piece "))
			break ;
	}
	tmp = ft_strchr(line, ' ');
	tokn->size[0] = ft_atoi(tmp++);
	tmp = ft_strchr(tmp, ' ');
	tokn->size[1] = ft_atoi(tmp);
	create_tokn(tokn, line);
	ft_strdel(&line);
}

void	create_tokn(t_tokn *tokn, char *line)
{
	int		i;

	i = -1;
	tokn->form = (char **)malloc(sizeof(char **) * tokn->size[0]);
	if (tokn->form == NULL)
		exit(1);
	while (++i < tokn->size[0])
	{
		get_next_line(FD, &line);
		tokn->form[i] = ft_strdup(line);
		tokn->put += ft_chr_rep(tokn->form[i], '*');
		ft_strdel(&line);
	}
}

int		main(void)
{
	char	*line;
	t_map	*conf;
	t_tokn	*tokn;

	line = NULL;
	tokn = malloc(sizeof(t_tokn));
	conf = malloc(sizeof(t_map));
	tokn->put = 0;
	read_param(conf, line);
	while (1)
	{
		read_map(conf, line);
		read_tokn(tokn, line);
		measure_tokn(tokn, conf);
	}
	free(conf);
	free(tokn);
	return (0);
}
