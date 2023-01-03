/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:45:37 by tmarts            #+#    #+#             */
/*   Updated: 2023/01/03 19:15:50 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <string.h>

void	draw_line(mlx_image_t *img, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	p;

	dx = x2 - x1;
	dy = y2 - y1;
	p = 2 * dy - dx;
	while (x1 < x2)
	{
		mlx_put_pixel(img, x1, y1, 0xEE4B2BFF);
		x1++;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy - 2 * dx;
			y1++;
		}
	}	
}

int	main (void)
{
	void		*mlx_ptr;
	mlx_image_t	*img;	

	mlx_ptr = mlx_init(500, 700, "mlx 42", true);
	if (!mlx_ptr)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx_ptr, 500, 700);
	if (!img)
		exit(EXIT_FAILURE);
	if (mlx_image_to_window(mlx_ptr, img, 0, 0) < 0)
		exit(EXIT_FAILURE);
	draw_line(img, 10, 40, 490, 80);
	draw_line(img, 10, 40, 490, 160);
	draw_line(img, 10, 40, 490, 240);
	draw_line(img, 10, 40, 490, 320);
	draw_line(img, 10, 40, 200, 700);
	mlx_loop(mlx_ptr);
	mlx_delete_image(mlx_ptr, img);
	mlx_terminate(mlx_ptr);
	return (EXIT_SUCCESS);
}