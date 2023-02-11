/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:18:11 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/11 21:34:26 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*converting 3d coordinares to 2d coordinates */

t_2d_isom	ft_2d_convert(t_3d *s_3d, t_map *s_map)
{
	double		x_cart;
	double		y_cart;
	t_2d_isom	s_2d_isom;

	x_cart = s_map->sc * (s_3d->pt_x - s_3d->pt_y) * cos(M_PI / 6);
	s_2d_isom.x = round(x_cart + s_map->center.x_0);
	y_cart = s_map->sc * (s_3d->pt_x + s_3d->pt_y) * sin(M_PI / 6) - \
	s_map->sc * s_map->z_sc * s_3d->pt_z;
	s_2d_isom.y = round(y_cart + s_map->center.y_0);
	return (s_2d_isom);
}

//taking 4 points of interest - 
// the points of max y and min x &  max y and min x decide the scale on 
// the 2d x axis (width of the window)
// the point of maximum x and y and pont of maximum z value give the
// needed scaling of the 2d y axis (height of the window)

// t_2d_isom ft_perspective(t_3d *s_3d, t_map *smap)
// {
// 

t_2d_isom	ft_parallel(t_3d *s_3d, t_map *s_map, char view)
{
	double		x_2d;
	double		y_2d;
	t_2d_isom	s_2d_isom;

	if (view == 'x')
	{
		x_2d = s_map->sc * s_3d->pt_x;
		y_2d = s_map->sc * s_3d->pt_z;
		s_2d_isom.x = round(x_2d + WIDTH / 2);
		s_2d_isom.y = round(y_2d + HEIGHT / 2);
	}
	if (view == 'z')
	{
		x_2d = s_map->sc * (s_3d->pt_x);
		s_2d_isom.x = round(x_2d) + WIDTH / 2;
		y_2d = s_map->sc * (s_3d->pt_y);
		s_2d_isom.y = round(y_2d) + HEIGHT / 2;
	}
	return (s_2d_isom);
}