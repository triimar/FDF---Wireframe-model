/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:18:11 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/03 21:22:42 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*converting 3d coordinares to 2d coordinates 
with (0, 0, 0) specified as origin*/

t_2d_isom	ft_2d_convert(t_3d *s_3d)
{
	double		x_cart;
	double		y_cart;
	t_2d_isom	s_2d_isom;

	x_cart = SC * (s_3d->pt_x - s_3d->pt_y) * cos(M_PI / 6);
	s_2d_isom.x = round((x_cart + WIDTH / 2));
	y_cart = SC * (s_3d->pt_x + s_3d->pt_y) * sin(M_PI / 6) - SC * s_3d->pt_z;
	s_2d_isom.y = round(y_cart + (HEIGHT / 2));
	return (s_2d_isom);
}
