/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:09:37 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 17:50:51 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

void	free_t_scene(t_scene *scene)
{
	t_list	*obj;

	if (!scene)
		return ;
	while (scene->objects)
	{
		obj = scene->objects->next;
		free(((t_object*)(scene->objects->content))->obj);
		free(scene->objects->content);
		scene->objects = obj;
	}
	while (scene->lights)
	{
		obj = scene->lights->next;
		free(scene->lights->content);
		free(scene->lights);
		scene->lights = obj;
	}
	while (scene->cameras)
	{
		obj = scene->cameras->next;
		free(scene->cameras->content);
		free(scene->cameras);
		scene->cameras = obj;
	}
}

void	free_scene(t_vars *vars)
{
	if (vars->scene)
		free_t_scene(vars->scene);
	free(vars->scene);
}
