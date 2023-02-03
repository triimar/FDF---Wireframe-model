/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:57:21 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/03 21:19:32 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_displ		s_displ;
	t_map		s_map;

	s_displ.window = mlx_init(WIDTH, HEIGHT, "test", true);
	if (!s_displ.window)
		exit(EXIT_FAILURE);
	s_displ.img = mlx_new_image(s_displ.window, WIDTH, HEIGHT);
	if (!s_displ.img)
		exit(EXIT_FAILURE);
	if (mlx_image_to_window(s_displ.window, s_displ.img, 0, 0) < 0)
		exit(EXIT_FAILURE);
	map_x_y_z(argv[1], &s_map);
	ft_draw_x(&s_map, &s_displ);
	ft_draw_y(&s_map, &s_displ);
	mlx_key_hook(s_displ.window, &esc_close, &s_displ);
	mlx_loop(s_displ.window);
	mlx_delete_image(s_displ.window, s_displ.img);
	mlx_terminate(s_displ.window);
	ft_free_double_p(s_map.mtrx, s_map.y_max);
	system("leaks fdf");
	return (EXIT_SUCCESS);
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
// 	mlx_key_hook(s_displ.window, &esc_close, NULL);
// 	mlx_loop(s_displ.window);
// 	mlx_delete_image(s_displ.window, s_displ.img);
// 	mlx_terminate(s_displ.window);
// 	ft_free_double_p(s_3d.mtrx, s_3d.y_max);
// 	system("leaks fdf");
// 	return (EXIT_SUCCESS);
// }
