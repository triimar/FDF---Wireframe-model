/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:35:08 by tmarts            #+#    #+#             */
/*   Updated: 2023/01/07 17:44:10 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*converting 3d cordinares to 2d cordinates 
with (0, 0, 0) sprcified as origin*/
int	x_fla(int x, int y, int z, int x_origin)
{
	int	x_cart;
	int	x_isom;

	x_cart = (x - y) * cos(0.5236);
	x_isom = x_cart + x_origin;
	return (x_isom);
}

int	y_fla(int x, int y, int z, int y_origin)
{
	int	y_cart;
	int	y_isom;

	y_cart = ((x + y) * sin(0.5236)) - z;
	y_isom = y_cart + y_origin;
	return (y_isom);
}

/*places pixels to draw a line, 
following Bresenhams algorithm*/
void	draw_line_low(mlx_image_t *img, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	p;
	int	y_step;

	y_step = 1;
	dx = x2 - x1;
	dy = y2 - y1;
	if (dy < 0)
	{
		y_step = -1;
		dy = -dy;
	}	
	p = 2 * dy - dx;
	while (x1 < x2)
	{
		mlx_put_pixel(img, x1++, y1, 0xEE4B2BFF);
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy - 2 * dx;
			y1 = y1 + y_step;
		}
	}
}

void	draw_line_high(mlx_image_t *img, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	p;
	int	x_step;

	x_step = 1;
	dx = x2 - x1;
	dy = y2 - y1;
	if (dx < 0)
	{
		x_step = -1;
		dx = -dx;
	}	
	p = 2 * dx - dy;
	while (y1 < y2)
	{
		mlx_put_pixel(img, x1, y1++, 0xEE4B2BFF);
		if (p < 0)
			p = p + 2 * dx;
		else
		{
			p = p + 2 * dx - 2 * dy;
			x1 = x1 + x_step;
		}
	}
}

void	draw_line(mlx_image_t *img, int x1, int y1, int x2, int y2)
{
	if (abs(y2 - y1) < abs(x2 - x1))
	{
		if (x1 > x2)
			draw_line_low(img, x2, y2, x1, y1);
		else
			draw_line_low(img, x1, y1, x2, y2);
	}
	else
	{
		if (y1 > y2)
			draw_line_high(img, x2, y2, x1, y1);
		else
			draw_line_high(img, x1, y1, x2, y2);
	}
}

int	main (void)
{
	void		*mlx_ptr;
	mlx_image_t	*img;	
	int			x_o = 400/2;
	int			y_o = 800-400;

	mlx_ptr = mlx_init(400, 800, "mlx 42", true);
	if (!mlx_ptr)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx_ptr, 400, 800);
	if (!img)
		exit(EXIT_FAILURE);
	if (mlx_image_to_window(mlx_ptr, img, 0, 0) < 0)
		exit(EXIT_FAILURE);
	printf("x_fla %d\n", x_fla(100, 0, 0, x_o));
	printf("y_fla %d\n", y_fla(100, 0, 0, y_o));
	draw_line(img, x_fla(0, 0, 100, x_o), y_fla(0, 0, 100, y_o), x_o, y_o);
	draw_line(img, x_fla(0, 100, 0, x_o), y_fla(0, 100, 0, y_o), x_o, y_o);
	draw_line(img, x_fla(10, 100, 0, x_o), y_fla(10, 100, 0, y_o), x_fla(10, 0, 0, x_o), y_fla(10, 0, 0, y_o));
	draw_line(img, x_fla(20, 100, 0, x_o), y_fla(20, 100, 0, y_o), x_fla(20, 0, 0, x_o), y_fla(20, 0, 0, y_o));
	draw_line(img, x_fla(100, 0, 0, x_o), y_fla(100, 0, 0, y_o), x_o, y_o);
	draw_line(img, x_fla(100, 10, 0, x_o), y_fla(100, 10, 0, y_o), x_fla(0, 10, 0, x_o), y_fla(0, 10, 0, y_o));
	draw_line(img, x_fla(100, 20, 0, x_o), y_fla(100, 20, 0, y_o), x_fla(0, 20, 0, x_o), y_fla(0, 20, 0, y_o));
	mlx_loop(mlx_ptr);
	mlx_delete_image(mlx_ptr, img);
	mlx_terminate(mlx_ptr);
	return (EXIT_SUCCESS);
}