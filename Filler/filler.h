/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:47:36 by tdontos-          #+#    #+#             */
/*   Updated: 2019/02/18 17:47:37 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include <fcntl.h>

# define FD 0

typedef struct	s_map
{
	char		my;
	char		op;
	int			size[2];
	int			way[2];
	int			pos[2];
	int			low;
	char		**map;
}				t_map;

typedef struct	s_tokn
{
	int			size[2];
	int			put;
	char		**form;
}				t_tokn;

void			create_tokn(t_tokn *tokn, char *line);
void			read_tokn(t_tokn *tokn, char *line);
void			read_param(t_map *conf, char *line);
void			read_map(t_map *conf, char *line);

void			measure_tokn(t_tokn *tokn, t_map *conf);
void			next_step(t_map *conf, t_tokn *tokn, int end);
void			search_way(t_map *conf, int y, int x);
void			reload_step(t_map *conf, t_tokn *tokn);

int				check_area(t_map *map, t_tokn *tokn, int ar);
int				put_tokn(char ***area, t_tokn *tokn, t_map *conf);
void			trim_area(char ***area, int row, t_map *conf);
void			ft_delmtrx(char ***mtrx);
int				check_cell(t_tokn *tokn, t_map *map, char *cell, int i);
#endif
