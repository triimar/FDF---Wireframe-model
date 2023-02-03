/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:45:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/03 21:23:15 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef ARRAY_SIZE
#  define ARRAY_SIZE 25
# endif

# define WIDTH 1540
# define HEIGHT 1028
# define SC 25.00

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
	double	pt_x;
	double	pt_y;
	double	pt_z;
}	t_3d;

typedef struct s_map {
	t_3d		**mtrx;
	int			x_max;
	int			y_max;
	int			z_max;
	float		sc;
	float		z_sc;
}	t_map;

typedef struct s_2d_isom {
	int	x;
	int	y;
}	t_2d_isom;

typedef struct s_displ {
	mlx_t		*window;
	mlx_image_t	*img;
}	t_displ;

t_map		*map_x_y_z(char *map_name, t_map *s_map);
void		draw_line(mlx_image_t *img, t_2d_isom s_p1, t_2d_isom s_p2);
// void		draw_grid(t_map *s_map, t_displ *s_displ);
void		ft_draw_x(t_map *s_map, t_displ *s_displ);
void		ft_draw_y(t_map *s_map, t_displ *s_displ);
t_2d_isom	ft_2d_convert(t_3d *s_3d);
void		draw_line_low(mlx_image_t *img, t_2d_isom s_p1, t_2d_isom s_p2);
void		draw_line_high(mlx_image_t *img, t_2d_isom s_p1, t_2d_isom s_p2);
char		*ft_free_double_p(void **p_p, int len);
void		esc_close(mlx_key_data_t keydata, void *param);

#endif