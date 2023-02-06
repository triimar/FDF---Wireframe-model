/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:18:11 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/06 20:41:44 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*converting 3d coordinares to 2d coordinates 
with (0, 0, 0) specified as origin*/

t_2d_isom	ft_2d_convert(t_3d *s_3d, t_map *s_map)
{
	double		x_cart;
	double		y_cart;
	t_2d_isom	s_2d_isom;

	x_cart = s_map->sc * (s_3d->pt_x - s_3d->pt_y) * cos(M_PI / 6);
	s_2d_isom.x = round((x_cart + WIDTH / 2));
	y_cart = s_map->sc * (s_3d->pt_x + s_3d->pt_y) * sin(M_PI / 6) - \
	s_map->sc * s_3d->pt_z;
	s_2d_isom.y = round(y_cart + (HEIGHT / 2));
	return (s_2d_isom);
}

//taking 4 points of interest - 
// the points of max y and min x &  max y and min x decide the scale on 
// the 2d x axis (width of the window)
// the point of maximum x and y and pont of maximum z value give the
// needed scaling of the 2d y axis (height of the window)

double	default_scale(t_map *s_map)
{
	double	pt_max_xy;
	double	pt_max_z;
	double	scale_x;

	if (s_map->x_max >= s_map->y_max)
		scale_x = (WIDTH / 2 - 80) / (s_map->x_max - 1) * cos((M_PI / 6));
	else
		scale_x = (WIDTH / 2 - 80) / (-1 - s_map->y_max) * cos(M_PI / 6);
	pt_max_xy = (s_map->x_max + s_map->y_max - 2) * sin(M_PI / 6) - \
	s_map->mtrx[s_map->y_max - 1][s_map->x_max - 1].pt_z;
	pt_max_z = (s_map->z_abs_max->pt_x + s_map->z_abs_max->pt_y) \
	* sin(M_PI / 6) - s_map->z_abs_max->pt_z;
	if (abs(pt_max_xy) <= abs(pt_max_z) && pt_max_z != 0)
		s_map->sc = (HEIGHT / 2 - 80) / pt_max_z;
	else
		s_map->sc = (HEIGHT / 2 - 80) / pt_max_xy;
	if (abs(scale_x) < abs(s_map->sc))
		s_map->sc = scale_x;
	if (s_map->sc < 1 && s_map->sc >= 0)
		s_map->sc = 1;
	if (s_map->sc < 0)
		s_map->sc = -1 * s_map->sc;
	return (s_map->sc);
}
