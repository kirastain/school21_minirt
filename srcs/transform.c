/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:40:05 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/29 22:31:22 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

void	translate_light(t_list *place, int key)
{
	t_light	*light;

	light = place->content;
	if (key == W)
		light->pos.y += 2;
	else if (key == S)
		light->pos.y -= 2;
	else if (key == A)
		light->pos.x -= 2;
	else if (key == D)
		light->pos.x += 2;
	else if (key == R)
		light->pos.z -= 2;
	else if (key == F)
		light->pos.z += 2;
}

void	translate_camera(t_camera *cam, int key)
{
	if (key == W)
		cam->pos.y += 2;
	else if (key == S)
		cam->pos.y -= 2;
	else if (key == A)
		cam->pos.x -= 2;
	else if (key == D)
		cam->pos.x += 2;
	else if (key == R)
		cam->pos.z -= 2;
	else if (key == F)
		cam->pos.z += 2;
}

void	translate_object(t_object *object, int key)
{
	printf("translate\n");
	if (object->type == T_PLANE)
		translate_plane((t_plane*)object->obj, key);
	else if (object->type == T_SPHERE)
		translate_sphere((t_sphere*)object->obj, key);
	else if (object->type == T_SQUARE)
		translate_square((t_square*)object->obj, key);
	else if (object->type == T_CYLINDER)
		translate_cylinder((t_cylinder*)object->obj, key);
	else if (object->type == T_CAMERA)
		translate_camera((t_camera*)object->obj, key);
	else if (object->type == T_LIGHT)
		translate_light((t_list*)object->obj, key);
	else
		translate_triangle((t_triangle*)object->obj, key);
}

void	rotate_object(t_object *object, int key)
{
	printf("rotate\n");
	if (object->type == T_PLANE)
		rotate_plane((t_plane*)object->obj, key);
	else if (object->type == T_SQUARE)
		rotate_square((t_square*)object->obj, key);
	else if (object->type == T_CYLINDER)
		rotate_cylinder((t_cylinder*)object->obj, key);
	else if (object->type == T_CAMERA)
		rotate_camera((t_camera*)object->obj, key);
	else
		rotate_triangle((t_triangle*)object->obj, key);
}

void	resize_object(t_object *object, int key)
{
	printf("resize\n");
	if (object->type == T_PLANE)
		resize_plane((t_plane*)object->obj, key);
	else if (object->type == T_SPHERE)
		resize_sphere((t_sphere*)object->obj, key);
	else if (object->type == T_SQUARE)
		resize_square((t_square*)object->obj, key);
	else if (object->type == T_CYLINDER)
		resize_cylinder((t_cylinder*)object->obj, key);
	else
		resize_triangle((t_triangle*)object->obj, key);
}
