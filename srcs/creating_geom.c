/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_geom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 13:54:32 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 17:44:30 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"
#include <stdio.h>

void	create_plane(char **line, t_vars *vars)
{
	t_plane		*plane;
	t_int3		color;
	t_object	*obj;

	if (strarr_len(line) == 4)
	{
		plane = init_plane();
		plane->center = get_double3(line[1]);
		plane->normal = get_double3_normal(line[2]);
		color = get_int3_color(line[3]);
		obj = create_object(get_colrgb(color.x, color.y, color.z),
				T_PLANE, plane);
		ft_lstadd_back(&(vars->scene->objects), ft_lstnew(obj));
	}
	else
		error_quit("Error\nWrong input creating plane\n");
}

void	create_sphere(char **line, t_vars *vars)
{
	t_sphere	*sphere;
	t_int3		color;
	t_object	*obj;

	if (strarr_len(line) == 4)
	{
		sphere = init_sphere();
		sphere->center = get_double3(line[1]);
		sphere->radius = ft_atod(line[2]);
		color = get_int3_color(line[3]);
		obj = create_object(get_colrgb(color.x, color.y, color.z),
				T_SPHERE, sphere);
		ft_lstadd_back(&(vars->scene->objects), ft_lstnew(obj));
	}
	else
		error_quit("Error\nWrong input creating sphere\n");
}

void	create_square(char **line, t_vars *vars)
{
	t_square	*square;
	t_int3		color;
	t_object	*obj;

	if (strarr_len(line) == 5)
	{
		square = init_square();
		square->center = get_double3(line[1]);
		square->normal = get_double3_normal(line[2]);
		square->side = ft_atod(line[3]);
		get_sq_points(square);
		color = get_int3_color(line[4]);
		obj = create_object(get_colrgb(color.x, color.y, color.z),
				T_SQUARE, square);
		ft_lstadd_back(&(vars->scene->objects), ft_lstnew(obj));
	}
	else
		error_quit("Error\nWrong input creating square\n");
}

void	create_cylinder(char **line, t_vars *vars)
{
	t_cylinder	*cylinder;
	t_int3		color;
	t_object	*obj;

	if (strarr_len(line) == 6)
	{
		cylinder = init_cylinder();
		cylinder->center = get_double3(line[1]);
		cylinder->normal = get_double3_normal(line[2]);
		cylinder->diameter = ft_atod(line[3]);
		cylinder->height = ft_atod(line[4]);
		color = get_int3_color(line[5]);
		obj = create_object(get_colrgb(color.x, color.y, color.z),
				T_CYLINDER, cylinder);
		ft_lstadd_back(&(vars->scene->objects), ft_lstnew(obj));
	}
	else
		error_quit("Error\nWrong input creating cylinder\n");
}

void	create_triangle(char **line, t_vars *vars)
{
	t_triangle	*triangle;
	t_int3		color;
	t_object	*obj;

	if (strarr_len(line) == 5)
	{
		triangle = init_triangle();
		triangle->a = get_double3(line[1]);
		triangle->b = get_double3(line[2]);
		triangle->c = get_double3(line[3]);
		color = get_int3_color(line[4]);
		obj = create_object(get_colrgb(color.x, color.y, color.z),
				T_TRIANGLE, triangle);
		ft_lstadd_back(&(vars->scene->objects), ft_lstnew(obj));
	}
	else
		error_quit("Error\nWrong input creating triangle\n");
}
