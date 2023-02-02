/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:41:43 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/02 20:43:32 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*converting 3d coordinares to 2d coordinates 
with (0, 0, 0) specified as origin*/
// int	x_fla(double x, double y, double z)
// {
// 	double	x_cart;
// 	double	x_isom;

// 	x_cart = SCALE * (x - y) * cos(M_PI / 6);
// 	x_isom = x_cart + (WIDTH / 2);
// 	return (round(x_isom));
// }

// int	y_fla(double x, double y, double z)
// {
// 	double	y_cart;
// 	double	y_isom;

// 	y_cart = SCALE * (x + y) * sin(M_PI / 6) - (SCALE * z);
// 	y_isom = y_cart + (HEIGHT / 2);
// 	return (round(y_isom));
// }

t_2d_isom	ft_2d_convert(double x, double y, double z)
{
	double		x_cart;
	double		y_cart;
	t_2d_isom	s_2d_isom;

	x_cart = SCALE * (x - y) * cos(M_PI / 6);
	s_2d_isom.x = round((x_cart + WIDTH / 2));
	y_cart = SCALE * (x + y) * sin(M_PI / 6) - (SCALE * z);
	s_2d_isom.y = round(y_cart + (HEIGHT / 2));
	return (s_2d_isom);
}

/*places pixels to draw a line, 
following Bresenhams algorithm*/
// void	draw_line_low(mlx_image_t *img, int x1, int y1, int x2, int y2)
// {
// 	int	dx;
// 	int	dy;
// 	int	p;
// 	int	y_step;

// 	y_step = 1;
// 	dx = x2 - x1;
// 	dy = y2 - y1;
// 	if (dy < 0)
// 	{
// 		y_step = -1;
// 		dy = -dy;
// 	}	
// 	p = 2 * dy - dx;
// 	while (x1 < x2)
// 	{
// 		mlx_put_pixel(img, x1++, y1, 0xEE4B2BFF);
// 		if (p < 0)
// 			p = p + 2 * dy;
// 		else
// 		{
// 			p = p + 2 * dy - 2 * dx;
// 			y1 = y1 + y_step;
// 		}
// 	}
// }

void	draw_line_low(mlx_image_t *img, t_2d_isom s_p1, t_2d_isom s_p2)
{
	int	dx;
	int	dy;
	int	p;
	int	y_step;

	y_step = 1;
	dx = s_p2.x - s_p1.x;
	dy = s_p2.y - s_p1.y;
	if (dy < 0)
	{
		y_step = -1;
		dy = -dy;
	}	
	p = 2 * dy - dx;
	while (s_p1.x < s_p2.x && s_p1.x < WIDTH && s_p1.y < HEIGHT && s_p1.x > 0 && s_p1.y > 0)
	{
		mlx_put_pixel(img, s_p1.x++, s_p1.y, 0xEE4B2BFF);
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy - 2 * dx;
			s_p1.y = s_p1.y + y_step;
		}
	}
}

// void	draw_line_high(mlx_image_t *img, int x1, int y1, int x2, int y2)
// {
// 	int	dx;
// 	int	dy;
// 	int	p;
// 	int	x_step;

// 	x_step = 1;
// 	dx = x2 - x1;
// 	dy = y2 - y1;
// 	if (dx < 0)
// 	{
// 		x_step = -1;
// 		dx = -dx;
// 	}	
// 	p = 2 * dx - dy;
// 	while (y1 < y2)
// 	{
// 		mlx_put_pixel(img, x1, y1++, 0xEE4B2BFF);
// 		if (p < 0)
// 			p = p + 2 * dx;
// 		else
// 		{
// 			p = p + 2 * dx - 2 * dy;
// 			x1 = x1 + x_step;
// 		}
// 	}
// }

void	draw_line_high(mlx_image_t *img, t_2d_isom s_p1, t_2d_isom s_p2)
{
	int	dx;
	int	dy;
	int	p;
	int	x_step;

	x_step = 1;
	dx = s_p2.x - s_p1.x;
	dy = s_p2.y - s_p1.y;
	if (dx < 0)
	{
		x_step = -1;
		dx = -dx;
	}	
	p = 2 * dx - dy;
	while (s_p1.y < s_p2.y && s_p1.x < WIDTH && s_p1.y < HEIGHT && s_p1.x > 0 && s_p1.y > 0)
	{
		mlx_put_pixel(img, s_p1.x, s_p1.y++, 0xEE4B2BFF);
		if (p < 0)
			p = p + 2 * dx;
		else
		{
			p = p + 2 * dx - 2 * dy;
			s_p1.x = s_p1.x + x_step;
		}
	}
}

// void	draw_grid(t_3d *s_3d, t_isom *s_isom, t_displ *s_displ)
// {
// 	int			x_cur;
// 	int			y_cur;
// 	t_2d_isom	s_2d_isom;

// 	y_cur = 0;
// 	while (y_cur < s_3d->y_max)
// 	{
// 		x_cur = 1;
// 		while (x_cur < s_3d->x_max)
// 		{
// 			s_isom->x1 = x_fla(x_cur - 1, y_cur, s_3d->mtrx[y_cur][x_cur - 1]);
// 			s_isom->y1 = y_fla(x_cur - 1, y_cur, s_3d->mtrx[y_cur][x_cur - 1]);
// 			s_isom->x2 = x_fla(x_cur, y_cur, s_3d->mtrx[y_cur][x_cur]);
// 			s_isom->y2 = y_fla(x_cur, y_cur, s_3d->mtrx[y_cur][x_cur]);
// 			draw_line(s_displ->img, s_isom);
// 			x_cur++;
// 		}
// 		y_cur++;
// 	}
// 	x_cur = 0;
// 	while (x_cur < s_3d->x_max)
// 	{
// 		y_cur = 1;
// 		while (y_cur < s_3d->y_max)
// 		{
// 			s_isom->x1 = x_fla(x_cur, y_cur - 1, s_3d->mtrx[y_cur - 1][x_cur]);
// 			s_isom->y1 = y_fla(x_cur, y_cur - 1, s_3d->mtrx[y_cur - 1][x_cur]);
// 			s_isom->x2 = x_fla(x_cur, y_cur, s_3d->mtrx[y_cur][x_cur]);
// 			s_isom->y2 = y_fla(x_cur, y_cur, s_3d->mtrx[y_cur][x_cur]);
// 			draw_line(s_displ->img, s_isom);
// 			y_cur++;
// 		}
// 		x_cur++;
// 	}
// }

void	draw_line(mlx_image_t *img, t_2d_isom s_p1, t_2d_isom s_p2)
{
	if (abs(s_p2.y - s_p1.y) < abs(s_p2.x - s_p1.x))
	{
		if (s_p1.x > s_p2.x)
			draw_line_low(img, s_p2, s_p1);
		else
			draw_line_low(img, s_p1, s_p2);
	}
	else
	{
		if (s_p1.y > s_p2.y)
			draw_line_high(img, s_p2, s_p1);
		else
			draw_line_high(img, s_p1, s_p2);
	}
}

void	draw_grid(t_3d *s_3d, t_displ *s_displ)
{
	int			x_cur;
	int			y_cur;
	t_2d_isom	p_1;
	t_2d_isom	p_2;

	y_cur = -1;
	while (++y_cur < s_3d->y_max)
	{
		x_cur = 0;
		p_1 = ft_2d_convert(x_cur, y_cur, s_3d->mtrx[y_cur][x_cur]);
		while (++x_cur < s_3d->x_max)
		{
			p_2 = ft_2d_convert(x_cur, y_cur, s_3d->mtrx[y_cur][x_cur]);
			draw_line(s_displ->img, p_1, p_2);
			p_1 = p_2;
		}
	}
	x_cur = -1;
	while (++x_cur < s_3d->x_max)
	{
		y_cur = 0;
		p_1 = ft_2d_convert(x_cur, y_cur, s_3d->mtrx[y_cur][x_cur]);
		while (++y_cur < s_3d->y_max)
		{
			p_2 = ft_2d_convert(x_cur, y_cur, s_3d->mtrx[y_cur][x_cur]);
			draw_line(s_displ->img, p_1, p_2);
			p_1 = p_2;
		}
	}
}




// int	main(int argc, char **argv)
// {
// 	t_3d		s_3d;
// 	t_isom		s_isom;
// 	t_displ		s_displ;
// 	int			x_cur;
// 	int			y_cur;

// 	y_cur = 0;
// 	s_displ.window = mlx_init(WIDTH, HEIGHT, "test", true);
// 	if (!s_displ.window)
// 		exit(EXIT_FAILURE);
// 	s_displ.img = mlx_new_image(s_displ.window, WIDTH, HEIGHT);
// 	if (!s_displ.img)
// 		exit(EXIT_FAILURE);
// 	if (mlx_image_to_window(s_displ.window, s_displ.img, 0, 0) < 0)
// 		exit(EXIT_FAILURE);
// 	map_x_y_z(argv[1], &s_3d);
// 	while (y_cur < s_3d.y_max)
// 	{
// 		x_cur = 1;
// 		while (x_cur < s_3d.x_max)
// 		{
// 			s_isom.x1 = x_fla(x_cur - 1, y_cur, s_3d.mtrx[y_cur][x_cur - 1]);
// 			s_isom.y1 = y_fla(x_cur - 1, y_cur, s_3d.mtrx[y_cur][x_cur - 1]);
// 			s_isom.x2 = x_fla(x_cur, y_cur, s_3d.mtrx[y_cur][x_cur]);
// 			s_isom.y2 = y_fla(x_cur, y_cur, s_3d.mtrx[y_cur][x_cur]);
// 			draw_line(s_displ.img, &s_isom);
// 			x_cur++;
// 		}
// 		y_cur++;
// 	}
// 	x_cur = 0;
// 	while (x_cur < s_3d.x_max)
// 	{
// 		y_cur = 1;
// 		while (y_cur < s_3d.y_max)
// 		{
// 			s_isom.x1 = x_fla(x_cur, y_cur - 1, s_3d.mtrx[y_cur - 1][x_cur]);
// 			s_isom.y1 = y_fla(x_cur, y_cur - 1, s_3d.mtrx[y_cur - 1][x_cur]);
// 			s_isom.x2 = x_fla(x_cur, y_cur, s_3d.mtrx[y_cur][x_cur]);
// 			s_isom.y2 = y_fla(x_cur, y_cur, s_3d.mtrx[y_cur][x_cur]);
// 			draw_line(s_displ.img, &s_isom);
// 			y_cur++;
// 		}
// 		x_cur++;
// 	}
// 	mlx_key_hook(s_displ.window, &esc_close, &s_displ);
// 	mlx_loop(s_displ.window);
// 	mlx_delete_image(s_displ.window, s_displ.img);
// 	mlx_terminate(s_displ.window);
// 	ft_free_double_p(s_3d.mtrx, s_3d.y_max);
// 	system("leaks fdf");
// 	return (EXIT_SUCCESS);
// }
