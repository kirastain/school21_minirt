/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:08:09 by bbelen            #+#    #+#             */
/*   Updated: 2020/09/12 16:07:18 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minirt.h"

t_ray	gen_ray(int w, int h, int x, int y, t_camera *cam)
{
	t_ray	ray;

	ray.o = cam->pos;
	ray.dir.x = (2 * (x + 0.5f) / (float)w  - 1) * tan(cam->angle / 2.) * w/ (float)h;
	ray.dir.y = -(2 * (y + 0.5f) / (float)h - 1) * tan(cam->angle / 2.);
	ray.dir.z = -w / tan(cam->angle / 2.0f); //edit
	ray.dir = vec_normalize(ray.dir);
	return (ray); 
}

void	trace_ray(t_ray *ray, t_vars *vars, t_data *data)
{
	int	i;

	i = 0;
	while (i < ft_lstsize(vars->scene))
	{
		
		i++;
	}
}
