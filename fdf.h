/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:45:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/01/23 17:28:36 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef ARRAY_SIZE
#  define ARRAY_SIZE 25
# endif

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# include <fcntl.h>
// # include "MLX42/include/MLX42/MLX42.h"
// # include "MLX42/include/MLX42/MLX42_Int.h"
// # include "MLX42/MLX42/MLX42_Input.h"

typedef struct s_3d {
	int	**mtrx;
	int	x_max;
	int	y_max;
}	t_3d;

#endif
