/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:45:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/02 20:51:25 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef ARRAY_SIZE
#  define ARRAY_SIZE 25
# endif

# define WIDTH 1540
# define HEIGHT 1028
# define SCALE 25.00

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42.h"
// # include "MLX42/include/MLX42/MLX42.h"
// # include "MLX42/include/MLX42/MLX42_Int.h"
// # include "MLX42/MLX42/MLX42_Input.h"

typedef struct s_3d {
	int	**mtrx;
	int	x_max;
	int	y_max;
}	t_3d;

typedef struct s_2d_isom {
	int	x;
	int	y;
}	t_2d_isom;

// typedef struct s_isom {
// 	int	x1;
// 	int	y1;
// 	int	x2;
// 	int	y2;
// }	t_isom;

typedef struct s_displ {
	mlx_t		*window;
	mlx_image_t	*img;
}	t_displ;

t_3d		*map_x_y_z(char *map_name, t_3d *s_3d);
// void		draw_line(mlx_image_t *img, t_isom *s_isom);
void		draw_line(mlx_image_t *img, t_2d_isom s_p1, t_2d_isom s_p2);
// void		draw_grid(t_3d *s_3d, t_isom *s_isom, t_displ *s_displ);
void		draw_grid(t_3d *s_3d, t_displ *s_displ);
// int		x_fla(double x, double y, double z);
// int		y_fla(double x, double y, double z);
t_2d_isom	ft_2d_convert(double x, double y, double z);
// void		draw_line_high(mlx_image_t *img, int x1, int y1, int x2, int y2);
// void		draw_line_low(mlx_image_t *img, int x1, int y1, int x2, int y2);
void		draw_line_low(mlx_image_t *img, t_2d_isom s_p1, t_2d_isom s_p2);
char		*ft_free_double_p(int **p_p, int len);
void		esc_close(mlx_key_data_t keydata, void *param);

#endif