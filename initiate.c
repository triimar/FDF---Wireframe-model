/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:54:29 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/12 23:02:45 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_initiate(t_map *s_map)
{
	s_map->window = mlx_init(WIDTH, HEIGHT, "test", true);
	if (!s_map->window)
		exit(EXIT_FAILURE);
	s_map->img = mlx_new_image(s_map->window, WIDTH, HEIGHT);
	if (!s_map->img)
		exit(EXIT_FAILURE);
	if (mlx_image_to_window(s_map->window, s_map->img, 0, 0) < 0)
		exit(EXIT_FAILURE);
	s_map->y_max = 0;
	s_map->x_max = 0;
	s_map->z_sc = 1;
	s_map->par_view = 1;
	s_map->center.x_0 = WIDTH / 2;
	s_map->center.y_0 = HEIGHT / 2;
	s_map->z_abs_max = NULL;
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
	return (round(s_map->sc));
}