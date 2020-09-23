/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen@student.21-school.ru <bbelen>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:06:17 by bbelen@stud       #+#    #+#             */
/*   Updated: 2020/09/23 17:37:26 by bbelen@stud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minirt.h"

int	init_scene(t_vars *vars)
{
	vars->res_x = 0;
	vars->res_y = 0;
	vars->mlx = mlx_init();
	vars->ambience = 0.0f;
	vars->amb_color = 0;
	vars->cameras = NULL;
	vars->lights = NULL;
	vars->scene = NULL;
	return (0);
}

int	init_object(t_object *obj)
{
	obj->color = 0;
	obj->type = 0;
	obj->obj = NULL;
	return (0);
}

t_plane		*init_plane()
{
	t_plane	*plane;

	plane = (t_plane*)malloc(sizeof(t_plane));
	plane->type = 0;
	plane->color = 0;
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
	sp->center.x = 0.0f;
	sp->center.y = 0.0f;
	sp->center.z = 0.0f;
	sp->radius = 0.0f;
	return (sp);
}

t_camera	*init_camera()
{
	t_camera	*camera;

	camera = (t_camera*)malloc(sizeof(t_camera));
	camera->angle = 0;
	camera->pos.x = 0.0f;
	camera->pos.y = 0.0f;
	camera->pos.z = 0.0f;
	camera->view.x = 0.0f;
	camera->view.y = 0.0f;
	camera->view.z = 0.0f;
	return (camera);
}