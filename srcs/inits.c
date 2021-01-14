/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:54:56 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 17:55:39 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

int			init_scene(t_vars *vars)
{
	vars->scene = (t_scene*)malloc(sizeof(t_scene));
	if (!vars->scene)
		error_quit("Error\nNot enough memory\n");
	vars->mlx = mlx_init();
	vars->scene->ambient = 0.0;
	vars->scene->ambient_color = init_color(0.0f, 0.0f, 0.0f);
	vars->scene->cameras = NULL;
	vars->scene->height = 0;
	vars->scene->lights = NULL;
	vars->scene->objects = NULL;
	vars->scene->selected_camera = 0;
	vars->scene->width = 0;
	vars->chosen_object = NULL;
	return (0);
}

t_camera	*init_camera(void)
{
	t_camera	*camera;

	camera = (t_camera*)malloc(sizeof(t_camera));
	if (!camera)
		error_quit("Error\nNot enough memory\n");
	camera->fov = 0;
	camera->pos.x = 0.0;
	camera->pos.y = 0.0;
	camera->pos.z = 0.0;
	camera->dir.x = 0.0;
	camera->dir.y = 0.0;
	camera->dir.z = 0.0;
	camera->dir_y.x = 0.0;
	camera->dir_y.y = 0.0;
	camera->dir_y.z = 0.0;
	camera->dir_x.x = 0.0;
	camera->dir_x.y = 0.0;
	camera->dir_x.z = 0.0;
	return (camera);
}

t_light		*init_light(void)
{
	t_light	*light;

	light = (t_light*)malloc(sizeof(t_light));
	if (!light)
		error_quit("Error\nNot enough memory\n");
	light->pos.x = 0.0;
	light->pos.y = 0.0;
	light->pos.z = 0.0;
	light->bright = 0.0;
	light->color = init_color(0, 0, 0);
	return (light);
}

t_surf		init_surf(t_double3 hit_point, t_double3 normal,
					t_object *object, t_ray ray)
{
	t_surf surf;

	surf.hit_point = hit_point;
	surf.normal = normal;
	surf.object = object;
	surf.ray = ray;
	return (surf);
}
