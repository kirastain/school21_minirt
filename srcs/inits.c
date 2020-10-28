/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:06:17 by bbelen@stud       #+#    #+#             */
/*   Updated: 2020/10/28 21:30:17 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

int	init_scene(t_vars *vars)
{
	vars->scene = (t_scene*)malloc(sizeof(t_scene));
	if (!vars->scene)
		error_quit("Not enough memory\n");
	vars->res_x = 0;
	vars->res_y = 0;
	vars->mlx = mlx_init();
	vars->scene->ambient = 0.0;
	vars->scene->ambient_color = init_color(0, 0, 0);
	vars->scene->cameras = NULL;
	vars->scene->height = 0;
	vars->scene->lights = NULL;
	vars->scene->objects = NULL;
	vars->scene->selected_camera = 0;
	vars->scene->width = 0;
	return (0);
}

int	init_object(t_object *obj)
{
	obj->color = init_color(0, 0, 0);
	obj->type = 0;
	obj->obj = NULL;
	obj->albedo = 0.2;
	return (0);
}

t_colrgb	init_color(double r, double g, double b)
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
		error_quit("Not enough memory\n");
	plane->center.x = 0.0f;
	plane->center.y = 0.0f;
	plane->center.z = 0.0f;
	plane->normal.x = 0.0f;
	plane->normal.y = 0.0f;
	plane->normal.z = 0.0f;
	return (plane);
}

t_sphere	*init_sphere()
{
	t_sphere	*sp;

	sp = (t_sphere*)malloc(sizeof(t_sphere));
	if (!sp)
		error_quit("Not enough memory\n");
	sp->center.x = 0.0f;
	sp->center.y = 0.0f;
	sp->center.z = 0.0f;
	sp->radius = 0.0f;
	return (sp);
}

t_square	*init_square()
{
	t_square	*sq;

	sq = (t_square*)malloc(sizeof(t_square));
	if (!sq)
		error_quit("Not enough memory\n");
	sq->center.x = 0.0f;
	sq->center.y = 0.0f;
	sq->center.z = 0.0f;
	sq->normal.x = 0.0f;
	sq->normal.y = 0.0f;
	sq->normal.z = 0.0f;
	sq->side = 0.0f;
	return (sq);
}

t_cylinder	*init_cylinder()
{
	t_cylinder	*cy;

	cy = (t_cylinder*)malloc(sizeof(t_cylinder));
	if (!cy)
		error_quit("Not enough memory\n");
	cy->center.x = 0.0f;
	cy->center.y = 0.0f;
	cy->center.z = 0.0f;
	cy->normal.x = 0.0f;
	cy->normal.y = 0.0f;
	cy->normal.z = 0.0f;
	cy->diameter = 0.0f;
	cy->height = 0.0f;
	return (cy);
}

t_triangle	*init_triangle()
{
	t_triangle	*tr;

	tr = (t_triangle*)malloc(sizeof(t_triangle));
	if (!tr)
		error_quit("Not enough memory\n");
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
		error_quit("Not enough memory\n");
	camera->fov = 0;
	camera->pos.x = 0.0f;
	camera->pos.y = 0.0f;
	camera->pos.z = 0.0f;
	camera->dir.x = 0.0f;
	camera->dir.y = 0.0f;
	camera->dir.z = 0.0f;
	return (camera);
}

t_light		*init_light()
{
	t_light	*light;

	light = (t_light*)malloc(sizeof(t_light));
	if (!light)
		error_quit("Not enough memory\n");
	light->pos.x = 0.0f;
	light->pos.y = 0.0f;
	light->pos.z = 0.0f;
	light->bright = 0.0f;
	light->color = init_color(0, 0, 0);
	return (light);
}

t_surf		init_surf(t_double3 hitPoint, t_double3 normal, t_object *object, t_ray ray)
{
	t_surf surf;

	surf.hitPoint = hitPoint;
	surf.normal = normal;
	surf.object = object;
	surf.ray = ray;
	return (surf);
}