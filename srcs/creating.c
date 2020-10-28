/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:14:04 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/28 21:27:41 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"
#include <stdio.h>

t_object *create_object(t_colrgb color, int type, void *geom)
{
	t_object	*obj;
	
	obj = (t_object*)malloc(sizeof(t_object));
	if (!obj)
		error_quit("Not enough memory\n");
	obj->color = color;
	obj->type = type;
	obj->obj = geom;
	obj->albedo = 0.1;
	return (obj);
}

void	create_res(char **line, t_vars *vars)
{
	if (strarr_len(line) == 3)
	{
		vars->res_x = ft_atoi(line[1]);
		vars->res_y = ft_atoi(line[2]);
		vars->scene->height = ft_atoi(line[2]);
		vars->scene->width = ft_atoi(line[1]);
		//добавить про разрешение экрана!!!!!!!!!!!
	}
	else
		error_quit("Wrong input getting res\n");
}

void	create_amb(char **line, t_vars *vars)
{
	t_int3	color;

	if (strarr_len(line) == 3)
	{
		vars->scene->ambient = ft_atod(line[1]);
		color = get_int3_color(line[2]);
		vars->scene->ambient_color = get_colrgb(color.x, color.y, color.z);
	}
	else
		error_quit("Wrong input creating amb\n");
}

void	create_camera(char **line, t_vars *vars)
{
	t_camera	*camera;

	if (strarr_len(line) == 4)
	{
		camera = init_camera();
		camera->pos = get_double3(line[1]);
		camera->dir = get_double3_normal(line[2]);
		camera->fov = ft_atoi(line[3]);
		ft_lstadd_back(&(vars->scene->cameras), ft_lstnew(camera));
	}
	else
		error_quit("Wrong input creating camera\n");
}

void	create_light(char **line, t_vars *vars)
{
	t_light	*light;
	t_int3	color;

	if (strarr_len(line) == 4)
	{
		light = init_light();
		light->pos = get_double3(line[1]);
		light->bright = ft_atod(line[2]);
		color = get_int3_color(line[3]);
		light->color = get_colrgb(color.x, color.y, color.z);
		ft_lstadd_back(&(vars->scene->lights), ft_lstnew(light));
	}
	else
		error_quit("Wrong input creating light\n");
}
