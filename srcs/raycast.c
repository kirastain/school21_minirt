/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen@student.21-school.ru <bbelen>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:08:09 by bbelen            #+#    #+#             */
/*   Updated: 2020/09/23 19:12:54 by bbelen@stud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minirt.h"

t_ray	gen_ray(int w, int h, int x, int y, t_camera *cam)
{
	t_ray	ray;

	//printf("cam pos x in gen_ray is %f\n", cam->pos.x);
	ray.o.x = cam->pos.x;
	ray.o.y = cam->pos.y;
	ray.o.z = cam->pos.z;
	ray.dir.x = (2 * (x + 0.5f) / (float)w  - 1) * tan(cam->angle / 2.) * w/ (float)h;
	ray.dir.y = -(2 * (y + 0.5f) / (float)h - 1) * tan(cam->angle / 2.);
	ray.dir.z = -w / tan(cam->angle / 2.0f); //edit
	ray.dir = vec_normalize(ray.dir);
	return (ray); 
}

void	trace_ray(t_ray *ray, t_vars *vars, t_data *img, int x, int y)
{
	int		i;
	int		inters;
	t_surf	surf;
	t_object	*object;
	
	i = 1; //потому что в самом начале какой-то пустой фиг
	inters = 0;
	surf.t = MAX_DIST;
	while (i < ft_lstsize(vars->scene))
	{
		//printf("here we go %f\n", ray->o.x);
		//init_object(object);
		object = ft_lstat(vars->scene, i)->content;
		inters = intersects(object, &surf, ray);
		i++;
	}
	if (surf.t < MAX_DIST && inters)
	{
		//printf("yes\n");
		my_mlx_pixel_put(img, x, y, 0xcc99ffe6);
	}
	else
		my_mlx_pixel_put(img, x, y, 0xcc69C2FA);
	//object = ft_lstat(vars->scene, 0)->content;
}
