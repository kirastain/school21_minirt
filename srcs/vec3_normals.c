/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:28:47 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/29 17:13:57 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

t_double3		sphere_normal(t_double3 point, t_sphere sphere)
{
	t_double3 norm;

	norm = vec_sub(point, sphere.center);
	norm = vec_normalize(norm);
	return (norm);
}

t_double3	plane_normal(t_plane plane)
{
	t_double3 norm;

	norm = plane.normal;
	return (norm);
}

t_double3		triangle_normal(t_triangle triangle)
{
	t_double3	a;
	t_double3	b;
	t_double3	norm;

	a = vec_sub(triangle.b, triangle.a);
	b = vec_sub(triangle.c, triangle.a);
	norm = vec_cross(a, b);
	norm = vec_normalize(norm);
	return (norm);
}

t_double3		square_normal(t_square square)
{
	t_double3 norm;

	norm = square.normal;
	return (norm);
}

t_double3		cylinder_normal(t_double3 point, t_cylinder cylinder)
{
	t_double3 ctp;
	t_double3 norm;

	ctp = vec_sub(point, cylinder.center);
	norm = vec_sub(ctp, mult_float(dot(cylinder.normal, ctp), cylinder.normal));
	norm = vec_normalize(norm);
	return (norm);
}
