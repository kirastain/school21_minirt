/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:55:20 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 15:19:59 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

int		intersect_main_shadow(t_list *objects, t_ray ray, t_object **object,
				double *t_min)
{
	t_list		*current;
	t_object	*this_object;
	double		t;

	*object = NULL;
	current = objects;
	*t_min = MAX_DIST;
	while (current != NULL)
	{
		this_object = current->content;
		if (intersects(this_object, &t, ray))
		{
			if (t < *t_min && t > 0.01)
			{
				*object = this_object;
				*t_min = t;
			}
		}
		current = current->next;
	}
	if (*object != NULL)
		return (1);
	else
		return (0);
}

int		intersect_main(t_list *objects, t_ray ray, t_object **object,
				double *t_min)
{
	t_list		*current;
	t_object	*this_object;
	double		t;

	*object = NULL;
	current = objects;
	*t_min = MAX_DIST;
	while (current != NULL)
	{
		this_object = current->content;
		if (intersects(this_object, &t, ray))
		{
			if (t < *t_min && t > 0.001)
			{
				*object = this_object;
				*t_min = t;
			}
		}
		current = current->next;
	}
	if (*object != NULL)
		return (1);
	else
		return (0);
}

int		intersects(t_object *obj, double *t, t_ray ray)
{
	if (obj->type == T_PLANE)
		return (intersects_plane(obj, t, ray));
	else if (obj->type == T_SPHERE)
		return (intersects_sphere(obj, t, ray));
	else if (obj->type == T_SQUARE)
		return (intersects_square(ray, (t_square*)obj->obj, t));
	else if (obj->type == T_CYLINDER)
		return (intersects_cylinder(ray, (t_cylinder*)obj->obj, t));
	else
		return (intersects_triangle((t_triangle*)obj->obj, t, ray));
	return (0);
}
