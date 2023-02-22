/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:41:43 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/22 17:39:19 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_x(t_conv_f funct, t_map *s_map)
{
	int		column;
	int		row;
	t_2d_px	p_1;
	t_2d_px	p_2;
	double	pos_pct;

	row = -1;
	while (++row < s_map->y_max)
	{
		column = 0;
		p_1 = funct(&s_map->mtrx[row][column], s_map);
		pos_pct = position_pct(s_map->pt_z_min->pt_z, s_map->pt_z_max->pt_z, \
		s_map->mtrx[row][column].pt_z);
		p_1.pt_rgba = get_rgba(pos_pct, START_RGBA, END_RGBA);
		while (++column < s_map->x_max)
		{
			p_2 = funct(&s_map->mtrx[row][column], s_map);
			pos_pct = position_pct(s_map->pt_z_min->pt_z, \
			s_map->pt_z_max->pt_z, s_map->mtrx[row][column].pt_z);
			p_2.pt_rgba = get_rgba(pos_pct, START_RGBA, END_RGBA);
			draw_line(s_map->img, p_1, p_2);
			p_1 = p_2;
		}
	}
}

static void	ft_draw_y(t_conv_f funct, t_map *s_map)
{
	int			column;
	int			row;
	t_2d_px		p_1;
	t_2d_px		p_2;
	double		pos_pct;

	column = -1;
	while (++column < s_map->x_max)
	{
		row = 0;
		p_1 = funct(&s_map->mtrx[row][column], s_map);
		pos_pct = position_pct(s_map->pt_z_min->pt_z, s_map->pt_z_max->pt_z, \
		s_map->mtrx[row][column].pt_z);
		p_1.pt_rgba = get_rgba(pos_pct, START_RGBA, END_RGBA);
		while (++row < s_map->y_max)
		{
			p_2 = funct(&s_map->mtrx[row][column], s_map);
			pos_pct = position_pct(s_map->pt_z_min->pt_z, \
			s_map->pt_z_max->pt_z, s_map->mtrx[row][column].pt_z);
			p_2.pt_rgba = get_rgba(pos_pct, START_RGBA, END_RGBA);
			draw_line(s_map->img, p_1, p_2);
			p_1 = p_2;
		}
	}
}

void	draw_all(t_conv_f funct, t_map *s_map)
{
	ft_memset(s_map->img->pixels, 0, s_map->img->width * \
	s_map->img->height * sizeof(int32_t));
	ft_draw_x(funct, s_map);
	ft_draw_y(funct, s_map);
	return ;
}
