/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:08:09 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 18:00:23 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

t_ray		create_ray(t_double3 o, t_double3 dir)
{
	t_ray ray;

	ray.o = o;
	ray.dir = dir;
	return (ray);
}

t_camera	pick_camera(t_scene *scene)
{
	t_list	*runner;
	int		i;

	i = 0;
	runner = scene->cameras;
	while (i < scene->selected_camera && runner != NULL)
	{
		i++;
		runner = runner->next;
	}
	return (*(t_camera *)runner->content);
}

t_double3	get_direction(int x, int y, t_scene *scene, t_camera camera)
{
	double		fov_coeff;
	double		aspect_ratio;
	double		p_x;
	double		p_y;
	t_double3	res;

	fov_coeff = tan((double)camera.fov / 2 * M_PI / 180);
	aspect_ratio = (double)scene->width / (double)scene->height;
	p_x = (2 * (x + 0.5) / (double)scene->width - 1) * aspect_ratio * fov_coeff;
	p_x = p_x * -1.0;
	p_y = (1 - 2 * (y + 0.5) / (double)scene->height) * fov_coeff;
	res = vec_create(p_x, p_y, 1);
	return (res);
}

t_ray		gen_ray(int x, int y, t_scene *scene)
{
	t_double3	origin;
	t_double3	direction;
	t_matrix	c2w;
	t_camera	camera;
	t_ray		ray;

	camera = pick_camera(scene);
	c2w = look_at(camera);
	origin = multiply_by_matrix(vec_create(0, 0, 0), c2w);
	direction.x = 0.0;
	direction = get_direction(x, y, scene, camera);
	direction = multiply_by_matrix(direction, c2w);
	direction = vec_sub(direction, origin);
	direction = vec_normalize(direction);
	ray = create_ray(origin, direction);
	return (ray);
}

int			trace_ray(t_scene *scene, t_ray ray)
{
	double		t_min;
	t_object	*object;
	t_colrgb	color;
	t_colrgb	ambient_color;

	if (intersect_main(scene->objects, ray, &object, &t_min))
	{
		ambient_color = colrgb_amb(scene->ambient_color,
									scene->ambient);
		color = colrgb_add(colrgb_mult(object->color, ambient_color),
							shade(scene, ray, object, t_min));
		return (to_int(color));
	}
	else
		return (0);
}
