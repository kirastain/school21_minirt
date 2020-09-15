/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_geom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 13:54:32 by bbelen            #+#    #+#             */
/*   Updated: 2020/09/03 15:02:04 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minirt.h"
#include <stdio.h>

int	create_plane(char **line, t_vars *vars)
{
	t_plane	plane;
	t_int3	color;

	if (strarr_len(line) == 4)
	{
		plane.center = get_float3(line[1]);
		plane.normal = get_float3_normal(line[2]);
		color = get_int3_color(line[3]);
		plane.color = create_trgb(0, color.x, color.y, color.z);
		ft_lstadd_front(&(vars->scene), ft_lstnew(&plane));
		return (0);
	}
	else
	{
		printf("Wrong input getting plane %i\n", strarr_len(line));
		exit(-1);
	}
}

int	create_sphere(char **line, t_vars *vars)
{
	t_sphere	sphere;
	t_int3	color;

	if (strarr_len(line) == 4)
	{
		sphere.center = get_float3(line[1]);
		sphere.radius = atof(line[2]);
		color = get_int3_color(line[3]);
		sphere.color = create_trgb(0, color.x, color.y, color.z);
		ft_lstadd_front(&(vars->scene), ft_lstnew(&sphere));
		return (0);
	}
	else
	{
		printf("Wrong input getting sphere %i\n", strarr_len(line));
		exit(-1);
	}
}

int	create_square(char **line, t_vars *vars)
{
	t_square	square;
	t_int3	color;

	if (strarr_len(line) == 5)
	{
		square.center = get_float3(line[1]);
		square.normal = get_float3_normal(line[2]);
		square.side = atof(line[3]);
		color = get_int3_color(line[4]);
		square.color = create_trgb(0, color.x, color.y, color.z);
		ft_lstadd_front(&(vars->scene), ft_lstnew(&square));
		return (0);
	}
	else
	{
		printf("Wrong input getting square %i\n", strarr_len(line));
		exit(-1);
	}
}

int	create_cylinder(char **line, t_vars *vars)
{
	t_cylinder	cylinder;
	t_int3	color;

	if (strarr_len(line) == 6)
	{
		cylinder.center = get_float3(line[1]);
		cylinder.normal = get_float3_normal(line[2]);
		cylinder.diameter = atof(line[3]);
		cylinder.height = atof(line[4]);
		color = get_int3_color(line[5]);
		cylinder.color = create_trgb(0, color.x, color.y, color.z);
		ft_lstadd_front(&(vars->scene), ft_lstnew(&cylinder));
		return (0);
	}
	else
	{
		printf("Wrong input getting cylinder %i\n", strarr_len(line));
		exit(-1);
	}
}

int	create_triangle(char **line, t_vars *vars)
{
	t_triangle	triangle;
	t_int3	color;

	if (strarr_len(line) == 5)
	{
		triangle.a = get_float3(line[1]);
		triangle.b = get_float3(line[2]);
		triangle.c = get_float3(line[3]);
		color = get_int3_color(line[4]);
		triangle.color = create_trgb(0, color.x, color.y, color.z);
		ft_lstadd_front(&(vars->scene), ft_lstnew(&triangle));
		return (0);
	}
	else
	{
		printf("Wrong input getting triangle %i\n", strarr_len(line));
		exit(-1);
	}
}