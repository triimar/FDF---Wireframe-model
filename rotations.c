/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:06:13 by tmarts            #+#    #+#             */
/*   Updated: 2023/02/23 19:13:44 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3d	ft_rotate_x(t_3d *s_3d, t_map *s_map)
{
	t_3d	new_pt;

	new_pt.pt_x = s_3d->pt_x;
	new_pt.pt_y = (s_3d->pt_y - s_map->y_max / 2) * cos(s_map->s_rot.x_angle) \
	+ s_3d->pt_z * (sin(s_map->s_rot.x_angle));
	new_pt.pt_z = (s_3d->pt_y - s_map->y_max / 2) * -sin(s_map->s_rot.x_angle) \
	+ s_3d->pt_z * cos(s_map->s_rot.x_angle);
	return (new_pt);
}

t_3d	ft_rotate_y(t_3d *s_3d, t_map *s_map)
{
	t_3d	new_pt;

	new_pt.pt_x = (s_3d->pt_x - s_map->x_max / 2) * cos(s_map->s_rot.y_angle) \
	+ s_3d->pt_z * sin(s_map->s_rot.y_angle);
	new_pt.pt_y = s_3d->pt_y;
	new_pt.pt_z = (s_3d->pt_x - s_map->x_max / 2) * -sin(s_map->s_rot.y_angle) \
	+ s_3d->pt_z * cos(s_map->s_rot.y_angle);
	return (new_pt);
}

t_3d	ft_rotate_z(t_3d *s_3d, t_map *s_map)
{
	t_3d	new_pt;

	new_pt.pt_x = s_3d->pt_x * cos(s_map->s_rot.z_angle) \
	+ (s_3d->pt_y) * -sin(s_map->s_rot.z_angle);
	new_pt.pt_y = s_3d->pt_x * sin(s_map->s_rot.z_angle) \
	+ s_3d->pt_y * cos(s_map->s_rot.z_angle);
	new_pt.pt_z = s_3d->pt_z;
	return (new_pt);
}
