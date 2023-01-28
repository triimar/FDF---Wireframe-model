/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:45:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/01/28 21:32:19 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef ARRAY_SIZE
#  define ARRAY_SIZE 25
# endif

# define WIDTH 1540
# define HEIGHT 1028
# define SCALE 15

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

typedef struct s_isom {
	int	x1;
	int	y1;
	int	x2;
	int	y2;
}	t_isom;

t_3d	*map_x_y_z(char *map_name, t_3d *s_3d);
void	draw_line(mlx_image_t *img, t_isom *s_isom);
// void	draw_line(mlx_image_t *img, int x1, int y1, int x2, int y2);
#endif