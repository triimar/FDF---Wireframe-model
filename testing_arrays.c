/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_arrays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:41:43 by tmarts            #+#    #+#             */
/*   Updated: 2023/01/28 21:49:04 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "fdf.h"

/*converting 3d cordinares to 2d cordinates 
with (0, 0, 0) sprcified as origin*/
int	x_fla(double x, double y, double z)
{
	double	x_cart;
	double	x_isom;

	x_cart = SCALE * (x - y) * cos(M_PI / 6);
	x_isom = x_cart + (WIDTH / 2);
	return (round(x_isom));
}

int	y_fla(double x, double y, double z)
{
	double	y_cart;
	double	y_isom;

	y_cart = SCALE * (x + y) * sin(M_PI / 6) - (SCALE * z);
	y_isom = y_cart + (HEIGHT / 2);
	return (round(y_isom));
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

// void	draw_line(mlx_image_t *img, int x1, int y1, int x2, int y2)
// {
// 	if (abs(y2 - y1) < abs(x2 - x1))
// 	{
// 		if (x1 > x2)
// 			draw_line_low(img, x2, y2, x1, y1);
// 		else
// 			draw_line_low(img, x1, y1, x2, y2);
// 	}
// 	else
// 	{
// 		if (y1 > y2)
// 			draw_line_high(img, x2, y2, x1, y1);
// 		else
// 			draw_line_high(img, x1, y1, x2, y2);
// 	}
// }

void	draw_line(mlx_image_t *img, t_isom *s_isom)
{
	if (abs(s_isom->y2 - s_isom->y1) < abs(s_isom->x2 - s_isom->x1))
	{
		if (s_isom->x1 > s_isom->x2)
			draw_line_low(img, s_isom->x2, s_isom->y2, s_isom->x1, s_isom->y1);
		else
			draw_line_low(img, s_isom->x1, s_isom->y1, s_isom->x2, s_isom->y2);
	}
	else
	{
		if (s_isom->y1 > s_isom->y2)
			draw_line_high(img, s_isom->x2, s_isom->y2, s_isom->x1, s_isom->y1);
		else
			draw_line_high(img, s_isom->x1, s_isom->y1, s_isom->x2, s_isom->y2);
	}
}
int	main (int argc, char **argv)
{
	t_3d		s_3d;
	t_isom		s_isom;
	void		*mlx_ptr;
	mlx_image_t	*img;
	int			x_cur;
	int			y_cur;

	y_cur = 0;
	mlx_ptr = mlx_init(1540, 1028, "test", true);
	if (!mlx_ptr)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx_ptr, 1540, 1028);
	if (!img)
		exit(EXIT_FAILURE);
	if (mlx_image_to_window(mlx_ptr, img, 0, 0) < 0)
		exit(EXIT_FAILURE);
	map_x_y_z(argv[1], &s_3d);
	while (y_cur < s_3d.y_max)
	{
		x_cur = 1;
		while (x_cur < s_3d.x_max)
		{
			s_isom.x1 = x_fla(x_cur - 1, y_cur, s_3d.mtrx[y_cur][x_cur - 1]);
			s_isom.y1 = y_fla(x_cur - 1, y_cur, s_3d.mtrx[y_cur][x_cur - 1]);
			s_isom.x2 = x_fla(x_cur, y_cur, s_3d.mtrx[y_cur][x_cur]);
			s_isom.y2 = y_fla(x_cur, y_cur, s_3d.mtrx[y_cur][x_cur]);
			draw_line(img, &s_isom);
			x_cur++;
		}
		y_cur++;
	}
	x_cur = 0;
	while (x_cur < s_3d.x_max)
	{
		y_cur = 1;
		while (y_cur < s_3d.y_max)
		{
			s_isom.x1 = x_fla(x_cur, y_cur - 1, s_3d.mtrx[y_cur - 1][x_cur]);
			s_isom.y1 = y_fla(x_cur, y_cur - 1, s_3d.mtrx[y_cur - 1][x_cur]);
			s_isom.x2 = x_fla(x_cur, y_cur, s_3d.mtrx[y_cur][x_cur]);
			s_isom.y2 = y_fla(x_cur, y_cur, s_3d.mtrx[y_cur][x_cur]);
			draw_line(img, &s_isom);
			y_cur++;
		}
		x_cur++;
	}
	mlx_loop(mlx_ptr);
	mlx_delete_image(mlx_ptr, img);
	mlx_terminate(mlx_ptr);
	system("leaks fdf");
	return (EXIT_SUCCESS);
}
