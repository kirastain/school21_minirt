/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:14:04 by bbelen            #+#    #+#             */
/*   Updated: 2020/08/29 13:55:17 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minirt.h"
#include <stdio.h>

int	create_res(char **line, t_vars *vars)
{
	if (strarr_len(line) == 3)
	{
		vars->res_x = ft_atoi(line[1]);
		vars->res_y = ft_atoi(line[2]);
		//добавить про разрешение экрана!!!!!!!!!!!
		printf("Res found\n");
		return (0);
	}
	else
	{
		printf("Wrong input getting res %i\n", strarr_len(line));
		exit(-1);
	}
}

int	create_amb(char **line, t_vars *vars)
{
	t_int3	color;

	printf("%s\n", line[2]);
	if (strarr_len(line) == 3)
	{
		vars->ambience = atof(line[1]);
		printf("%f\n", vars->ambience);
		color = get_int3_color(line[2]);
		vars->amb_color = create_trgb(0, color.x, color.y, color.z);
		printf("Ambience found color %x\n", vars->amb_color);
		return (0);
	}
	else
	{
		printf("Wrong input getting amb %i\n", strarr_len(line));
		exit(-1);
	}
}

int	create_camera(char **line)
{
	t_camera	camera;

	if (strarr_len(line) == 4)
	{
		camera.pos = get_float3(line[1]);
		camera.view = get_float3_normal(line[2]);
		if ((camera.angle = ft_atoi(line[3])))
		{
			return (0);
		}
		else
			exit(-1);		
	}
	else
	{
		printf("Wrong input getting camera %i\n", strarr_len(line));
		exit(-1);
	}
}

int	create_light(char **line)
{
	t_light	light;
	t_int3	color;

	if (strarr_len(line) == 4)
	{
		light.pos = get_float3(line[1]);
		light.bright = atof(line[2]);
		color = get_int3_color(line[3]);
		light.color = create_trgb(0, color.x, color.y, color.z);
		printf("light done\n");
		return (0);
	}
	else
	{
		printf("Wrong input getting light %i\n", strarr_len(line));
		exit(-1);
	}
}
