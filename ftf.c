/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:35:08 by tmarts            #+#    #+#             */
/*   Updated: 2023/01/05 20:02:00 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <string.h>

//converting 3d cordinares to 2d flash cordinates
int	x_fla(int x, int y, int z, int x_origin)
{
	int	x_cart;
	int	x_isom;

	x_cart = (x - z) * cos(0.5236);
	x_isom = x_cart + x_origin;
	return (x_isom);
}

int	y_fla(int x, int y, int z, int y_origin)
{
	int	y_cart;
	int	y_isom;

	y_cart = y + (x + z) * sin(0.5236);
	y_isom = -y_cart + y_origin;
	return (y_isom);
}

style = function (a, b, c) {
// a: line width
// b: line color
// c: line alpha
lineStyle(a, b, c);
};

plot = function (x, y, z) {
moveTo(xFla(x, y, z), yFla(x, y, z));
};

draw = function (x, y, z) {
lineTo(xFla(x, y, z), yFla(x, y, z));
};

void	draw_line(mlx_image_t *img, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	p;

	dx = x2 - x1;
	dy = y2 - y1;
	p = 2 * dy - dx;
	while (x1 < x2)
	{
		mlx_put_pixel(img, x1, y1, 0xEE4B2BFF);
		x1++;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy - 2 * dx;
			y1++;
		}
	}	
}

