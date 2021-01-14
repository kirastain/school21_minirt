/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_geom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:14:08 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 17:54:06 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

t_plane		*init_plane(void)
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

t_sphere	*init_sphere(void)
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

t_square	*init_square(void)
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
	sq->a = vec_create(0, 0, 0);
	sq->b = vec_create(0, 0, 0);
	sq->c = vec_create(0, 0, 0);
	sq->d = vec_create(0, 0, 0);
	return (sq);
}

t_cylinder	*init_cylinder(void)
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

t_triangle	*init_triangle(void)
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
