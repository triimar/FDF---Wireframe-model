/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:18:11 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/12 23:02:22 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*converting 3d coordinares to 2d coordinates */

t_2d_px	ft_isometric(t_3d *s_3d, t_map *s_map)
{
	double	x_cart;
	double	y_cart;
	t_2d_px	s_2d_px;

	x_cart = s_map->sc * (s_3d->pt_x - s_3d->pt_y) * cos(M_PI / 6);
	s_2d_px.x = round(x_cart + s_map->center.x_0);
	y_cart = s_map->sc * (s_3d->pt_x + s_3d->pt_y) * sin(M_PI / 6) - \
	s_map->sc * s_map->z_sc * s_3d->pt_z;
	s_2d_px.y = round(y_cart + s_map->center.y_0);
	return (s_2d_px);
}

t_2d_px	ft_parallel_x(t_3d *s_3d, t_map *s_map)
{
	double	x_2d;
	double	y_2d;
	t_2d_px	s_2d_px;

	default_scale(s_map);
	x_2d = s_map->sc * s_3d->pt_y;
	y_2d = s_map->sc * s_3d->pt_z;
	s_2d_px.y = round(-y_2d + HEIGHT / 2);
	s_2d_px.x = round(x_2d + WIDTH / 2 - s_map->sc * s_map->y_max / 2);
	return (s_2d_px);
}

t_2d_px	ft_parallel_y(t_3d *s_3d, t_map *s_map)
{
	double	x_2d;
	double	y_2d;
	t_2d_px	s_2d_px;

	default_scale(s_map);
	x_2d = s_map->sc * s_3d->pt_x;
	y_2d = s_map->sc * s_3d->pt_z;
	s_2d_px.y = round(-y_2d + HEIGHT / 2);
	s_2d_px.x = round(x_2d + WIDTH / 2 - s_map->sc * s_map->x_max / 2);
	return (s_2d_px);
}

t_2d_px	ft_parallel_z(t_3d *s_3d, t_map *s_map)
{
	double	x_2d;
	double	y_2d;
	t_2d_px	s_2d_px;

	default_scale(s_map);
	x_2d = s_map->sc * (s_3d->pt_x);
	y_2d = s_map->sc * (s_3d->pt_y);
	s_2d_px.y = round(y_2d + HEIGHT / 2 - s_map->sc * s_map->y_max / 2);
	s_2d_px.x = round(x_2d + WIDTH / 2 - s_map->sc * s_map->x_max / 2);
	return (s_2d_px);
}