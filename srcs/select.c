/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:10:11 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 18:18:49 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

void	select_light(t_vars *vars)
{
	t_object	*object;
	t_list		*place;

	if (!(vars->chosen_object) || (vars->chosen_object->type != T_LIGHT))
		place = ft_lstat(vars->scene->lights, 0);
	else if (((t_list*)(vars->chosen_object->obj))->next != NULL)
		place = ((t_list*)(vars->chosen_object->obj))->next;
	else
	{
		return ;
	}
	object = create_object(((t_light*)(place->content))->color, T_LIGHT, place);
	vars->chosen_object = object;
}

void	select_camera(t_vars *vars)
{
	t_object	*object;
	t_list		*place;
	t_camera	*cam;

	place = ft_lstat(vars->scene->cameras, vars->scene->selected_camera);
	cam = place->content;
	object = create_object(get_colrgb(0, 0, 0), T_CAMERA, cam);
	vars->chosen_object = object;
}

void	select_object(t_vars *vars, t_ray ray)
{
	double		t_min;
	t_object	*object;
	t_colrgb	color;
	t_colrgb	ambient_color;

	if (intersect_main(vars->scene->objects, ray, &object, &t_min))
	{
		vars->chosen_object = object;
	}
	else
	{
		ft_putstr_fd("nothing is selected\n", 1);
	}
}

void	transform_main(int key, t_vars *vars)
{
	if (!(vars->chosen_object))
		return ;
	if (key == W || key == S || key == A || key == D || key == R || key == F)
		translate_object(vars->chosen_object, key);
	if (key == T || key == Y || key == G || key == H || key == B || key == N)
		rotate_object(vars->chosen_object, key);
	if (key == Z || key == X)
		resize_object(vars->chosen_object, key);
}
