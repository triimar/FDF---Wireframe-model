/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_converters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:18:11 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/23 18:24:23 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*converting 3d coordinares to 2d coordinates */

static t_2d	ft_isometric(t_3d *s_3d, t_map *s_map)
{
	double	x_cart;
	double	y_cart;
	t_2d	s_2d;

	x_cart = s_map->sc * (s_3d->pt_x - s_3d->pt_y) * cos(M_PI / 6);
	s_2d.x = round(x_cart + s_map->center.x_0);
	y_cart = s_map->sc * (s_3d->pt_x + s_3d->pt_y) * sin(M_PI / 6) - \
	s_map->sc * s_map->z_sc * s_3d->pt_z;
	s_2d.y = round(y_cart + s_map->center.y_0);
	return (s_2d);
}

t_2d	ft_iso_rot(t_3d *s_3d, t_map *s_map)
{
	t_3d	new_pt;
	t_2d	s_2d;

	new_pt = ft_rotate_x(s_3d, s_map);
	new_pt = ft_rotate_y(&new_pt, s_map);
	new_pt = ft_rotate_z(&new_pt, s_map);
	s_2d = ft_isometric(&new_pt, s_map);
	return (s_2d);
}

t_2d	ft_parallel_x(t_3d *s_3d, t_map *s_map)
{
	double	x_2d;
	double	y_2d;
	t_2d	s_2d;

	x_2d = -s_map->sc * s_3d->pt_y;
	y_2d = s_map->sc * s_3d->pt_z;
	s_2d.y = round(-y_2d + HEIGHT / 2);
	s_2d.x = round(x_2d + WIDTH / 2);
	return (s_2d);
}

t_2d	ft_parallel_y(t_3d *s_3d, t_map *s_map)
{
	double	x_2d;
	double	y_2d;
	t_2d	s_2d;

	x_2d = s_map->sc * s_3d->pt_x;
	y_2d = s_map->sc * s_3d->pt_z;
	s_2d.y = round(-y_2d + s_map->center.y_0);
	s_2d.x = round(x_2d + s_map->center.x_0);
	return (s_2d);
}

t_2d	ft_parallel_z(t_3d *s_3d, t_map *s_map)
{
	double	x_2d;
	double	y_2d;
	t_2d	s_2d;

	x_2d = s_map->sc * (s_3d->pt_x);
	y_2d = s_map->sc * (s_3d->pt_y);
	s_2d.y = round(y_2d + s_map->center.y_0);
	s_2d.x = round(x_2d + s_map->center.x_0);
	return (s_2d);
}
