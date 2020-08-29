/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_geom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 13:54:32 by bbelen            #+#    #+#             */
/*   Updated: 2020/08/29 14:05:43 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minirt.h"
#include <stdio.h>

int	create_plane(char **line)
{
	t_plane	plane;
	t_int3	color;

	if (strarr_len(line) == 4)
	{
		plane.center = get_float3(line[1]);
		plane.normal = get_float3_normal(line[2]);
		color = get_int3_color(line[3]);
		plane.color = create_trgb(0, color.x, color.y, color.z);
		return (0);
	}
	else
	{
		printf("Wrong input getting plane %i\n", strarr_len(line));
		exit(-1);
	}
}

int	create_sphere(char **line)
{
	t_sphere	sphere;
	t_int3	color;

	if (strarr_len(line) == 4)
	{
		sphere.center = get_float3(line[1]);
		sphere.radius = atof(line[2]);
		color = get_int3_color(line[3]);
		sphere.color = create_trgb(0, color.x, color.y, color.z);
		return (0);
	}
	else
	{
		printf("Wrong input getting sphere %i\n", strarr_len(line));
		exit(-1);
	}
}