/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 14:50:55 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/28 14:42:55 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

t_double3		get_normal(t_double3 p, t_object *object)
{
	if (object->type == T_CYLINDER)
		return (cylinder_normal(p, *(t_cylinder*)object->obj));
	if (object->type == T_SPHERE)
		return (sphere_normal(p, *(t_sphere*)object->obj));
	if (object->type == T_SQUARE)
		return (square_normal(*(t_square*)object->obj));
	if (object->type == T_TRIANGLE)
		return (triangle_normal(*(t_triangle*)object->obj));
	else
		return (plane_normal(*(t_plane*)object->obj));
}
