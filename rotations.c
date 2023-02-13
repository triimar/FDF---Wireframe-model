/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:06:13 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/13 20:12:20 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3d	ft_rotate_x(t_3d *s_3d, t_map *s_map)
{
	t_3d	new_pt;

	new_pt.pt_x = s_3d->pt_x;
	new_pt.pt_y = s_3d->pt_y * cos(s_map->s_rot.x_angle) \
	+ s_3d->pt_z * (sin(s_map->s_rot.x_angle));
	new_pt.pt_z = s_3d->pt_y * -sin(s_map->s_rot.x_angle) \
	+ s_3d->pt_z * cos(s_map->s_rot.x_angle);
	return (new_pt);
}

t_3d	ft_rotate_y(t_3d *s_3d, t_map *s_map)
{
	t_3d	new_pt;

	new_pt.pt_x = s_3d->pt_x * cos(s_map->s_rot.y_angle) \
	+ s_3d->pt_z * sin(s_map->s_rot.y_angle);
	new_pt.pt_y = s_3d->pt_y;
	new_pt.pt_z = s_3d->pt_x * -sin(s_map->s_rot.y_angle) \
	+ s_3d->pt_z * cos(s_map->s_rot.y_angle);
	return (new_pt);
}

t_3d	ft_rotate_z(t_3d *s_3d, t_map *s_map)
{
	t_3d	new_pt;

	new_pt.pt_x = s_3d->pt_x * cos(s_map->s_rot.z_angle) \
	+ s_3d->pt_y * -sin(s_map->s_rot.z_angle);
	new_pt.pt_y = s_3d->pt_x * sin(s_map->s_rot.z_angle) \
	+ s_3d->pt_y * cos(s_map->s_rot.z_angle);
	new_pt.pt_z = s_3d->pt_z;
	return (new_pt);
}

static void	ft_rot_draw_x(t_conv_f funct, t_map *s_map)
{
	int		column;
	int		row;
	t_2d_px	p_1;
	t_2d_px	p_2;
	t_3d	new_pt;

	row = -1;
	while (++row < s_map->y_max)
	{
		column = 0;
		new_pt = ft_rotate_x(&s_map->mtrx[row][column], s_map);
		p_1 = funct(&new_pt, s_map);
		while (++column < s_map->x_max)
		{
			new_pt = ft_rotate_x(&s_map->mtrx[row][column], s_map);
			p_2 = funct(&new_pt, s_map);
			draw_line(s_map->img, p_1, p_2);
			p_1 = p_2;
		}
	}
}

static void	ft_rot_draw_y(t_conv_f funct, t_map *s_map)
{
	int			column;
	int			row;
	t_2d_px		p_1;
	t_2d_px		p_2;
	t_3d		new_pt;

	column = -1;
	while (++column < s_map->x_max)
	{
		row = 0;
		new_pt = ft_rotate_x(&s_map->mtrx[row][column], s_map);
		p_1 = funct(&new_pt, s_map);
		while (++row < s_map->y_max)
		{
			new_pt = ft_rotate_x(&s_map->mtrx[row][column], s_map);
			p_2 = funct(&new_pt, s_map);
			draw_line(s_map->img, p_1, p_2);
			p_1 = p_2;
		}
	}
}

void	rot_draw(t_conv_f funct, t_map *s_map)
{
	ft_memset(s_map->img->pixels, 0, s_map->img->width * \
	s_map->img->height * sizeof(int32_t));
	ft_rot_draw_x(funct, s_map);
	ft_rot_draw_y(funct, s_map);
	return ;
}