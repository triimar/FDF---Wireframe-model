/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:45:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/24 18:00:25 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ARRAY_SIZE 25
# define WIDTH 1540
# define HEIGHT 1028
# define START_RGBA 0xEE0000FF
# define END_RGBA 	0xFFFFFFFF

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42/MLX42_Input.h"

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

typedef struct s_2d {
	int	x;
	int	y;
	int	pt_rgba;
}	t_2d;

typedef struct s_px {
	int		step;
	int		dx;
	int		dy;
	double	pos_pct;
	int		color;
}	t_px;

typedef struct center {
	int	x_0;
	int	y_0;
}	t_center;

typedef struct s_map {
	t_3d		**mtrx;
	t_3d		*pt_z_max;
	t_3d		*pt_z_min;
	int			x_max;
	int			y_max;
	int			y_coeff;
	double		sc;
	double		z_sc;
	mlx_t		*window;
	mlx_image_t	*img;
	t_center	center;
	t_rot		s_rot;
}	t_map;

typedef t_2d	(*t_conv_f)(t_3d *, t_map *);

/*initiate*/
void			ft_initiate(t_map *s_map);
double			default_scale(t_map *s_map);
void			ft_defaults(t_map *s_map);
/*map*/
t_3d			**map_parse(int fd, t_map *s_map);
/*draw & draw_line*/
void			draw_all(t_conv_f funct, t_map *s_map);
void			draw_line(mlx_image_t *img, t_2d s_p1, t_2d s_p2);
/*2d_converters*/
t_2d			ft_iso_rot(t_3d *s_3d, t_map *s_map);
t_2d			ft_parallel_x(t_3d *s_3d, t_map *s_map);
t_2d			ft_parallel_y(t_3d *s_3d, t_map *s_map);
t_2d			ft_parallel_z(t_3d *s_3d, t_map *s_map);
/*rotations*/
t_3d			ft_rotate_x(t_3d *s_3d, t_map *s_map);
t_3d			ft_rotate_y(t_3d *s_3d, t_map *s_map);
t_3d			ft_rotate_z(t_3d *s_3d, t_map *s_map);
/*hooks*/
void			single_key_h(mlx_key_data_t keydata, void *param);
void			scroll_scale(double xdelta, double ydelta, void *param);
void			genhook_re(t_map *s_map);
/*color*/
double			position_pct(double min, double max, double current);
int				get_rgba(double pct, int start, int end);
/*fdf_utils*/
char			*ft_free_double_p(t_3d **p_p, int len);
char			*ft_free_split(char **p_p);
char			*ft_free_all(t_map *s_map, char **split_str, char *str);
void			error_msg(int error);

#endif