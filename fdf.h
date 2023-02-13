/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:45:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/13 22:22:24 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1540
# define HEIGHT 1028

# ifndef ARRAY_SIZE
#  define ARRAY_SIZE 80
# endif

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h> // rm this
// # include "MLX42/include/MLX42/MLX42.h"
// # include "MLX42/include/MLX42/MLX42_Int.h"
// # include "MLX42/MLX42/MLX42_Input.h"

typedef struct s_3d {
	double	pt_x;
	double	pt_y;
	double	pt_z;
}	t_3d;

typedef struct s_rot {
	double	x_angle;
	double	y_angle;
	double	z_angle;
}	t_rot;

typedef struct center {
	int	x_0;
	int	y_0;
}	t_center;

typedef struct s_map {
	t_3d		**mtrx;
	t_3d		*z_abs_max;
	int			x_max;
	int			y_max;
	double		sc;
	double		z_sc;
	mlx_t		*window;
	mlx_image_t	*img;
	t_center	center;
	t_rot		s_rot;
}	t_map;

typedef struct s_2d_px {
	int	x;
	int	y;
}	t_2d_px;

typedef t_2d_px	(*t_conv_f)(t_3d *, t_map *);

void		ft_initiate(t_map *s_map);
t_3d		*ft_get_row(t_map *s_map, char **splits);
t_map		*map_x_y_z(int fd, t_map *s_map);
void		draw_line(mlx_image_t *img, t_2d_px s_p1, t_2d_px s_p2);
void		draw_all(t_conv_f funct, t_map *s_map);
t_2d_px		ft_isometric(t_3d *s_3d, t_map *s_map);
t_2d_px		ft_parallel_x(t_3d *s_3d, t_map *s_map);
t_2d_px		ft_parallel_y(t_3d *s_3d, t_map *s_map);
t_2d_px		ft_parallel_z(t_3d *s_3d, t_map *s_map);
t_3d		ft_rotate_x(t_3d *s_3d, t_map *s_map);
void		draw_line_low(mlx_image_t *img, t_2d_px s_p1, t_2d_px s_p2);
void		draw_line_high(mlx_image_t *img, t_2d_px s_p1, t_2d_px s_p2);
char		*ft_free_double_p(void **p_p, int len);
char		*ft_free_split(char **p_p);
char		*ft_free_all(t_map *s_map, char **split_str, char *str);
void		single_key_h(mlx_key_data_t keydata, t_map *s_map);
void		scroll_scale(double xdelta, double ydelta, t_map *s_map);
void		genhook_re(t_map *s_map);
double		default_scale(t_map *s_map);
void		ft_defaults(t_map *s_map);

#endif