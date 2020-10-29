/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:06:17 by bbelen@stud       #+#    #+#             */
/*   Updated: 2020/10/29 22:20:42 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

int	init_scene(t_vars *vars)
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

t_colrgb	init_color(float r, float g, float b)
{
	t_colrgb	color;

	color.red = r;
	color.blue = b;
	color.green = g;
	return (color);
}

t_plane		*init_plane()
{
	t_plane	*plane;

	plane = (t_plane*)malloc(sizeof(t_plane));
	if (!plane)
		error_quit("Error\nNot enough memory\n");
	plane->center.x = 0.0;
	plane->center.y = 0.0;
	plane->center.z = 0.0;
	plane->normal.x = 0.0;
	plane->normal.y = 0.0;
	plane->normal.z = 0.0;
	return (plane);
}

t_sphere	*init_sphere()
{
	t_sphere	*sp;

	sp = (t_sphere*)malloc(sizeof(t_sphere));
	if (!sp)
		error_quit("Error\nNot enough memory\n");
	sp->center.x = 0.0;
	sp->center.y = 0.0;
	sp->center.z = 0.0;
	sp->radius = 0.0;
	return (sp);
}

t_square	*init_square()
{
	t_square	*sq;

	sq = (t_square*)malloc(sizeof(t_square));
	if (!sq)
		error_quit("Error\nNot enough memory\n");
	sq->center.x = 0.0;
	sq->center.y = 0.0;
	sq->center.z = 0.0;
	sq->normal.x = 0.0;
	sq->normal.y = 0.0;
	sq->normal.z = 0.0;
	sq->side = 0.0;
	return (sq);
}

t_cylinder	*init_cylinder()
{
	t_cylinder	*cy;

	cy = (t_cylinder*)malloc(sizeof(t_cylinder));
	if (!cy)
		error_quit("Error\nNot enough memory\n");
	cy->center.x = 0.0;
	cy->center.y = 0.0;
	cy->center.z = 0.0;
	cy->normal.x = 0.0;
	cy->normal.y = 0.0;
	cy->normal.z = 0.0;
	cy->diameter = 0.0;
	cy->height = 0.0;
	return (cy);
}

t_triangle	*init_triangle()
{
	t_triangle	*tr;

	tr = (t_triangle*)malloc(sizeof(t_triangle));
	if (!tr)
		error_quit("Error\nNot enough memory\n");
	tr->a = vec_create(0, 0, 0);
	tr->b = vec_create(0, 0, 0);
	tr->c = vec_create(0, 0, 0);
	return (tr);
}

t_camera	*init_camera()
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
	return (camera);
}

t_light		*init_light()
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

t_surf		init_surf(t_double3 hit_point, t_double3 normal, t_object *object, t_ray ray)
{
	t_surf surf;

	surf.hit_point = hit_point;
	surf.normal = normal;
	surf.object = object;
	surf.ray = ray;
	return (surf);
}