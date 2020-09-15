/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:14:04 by bbelen            #+#    #+#             */
/*   Updated: 2020/09/03 14:58:29 by bbelen           ###   ########.fr       */
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

int	create_camera(char **line, t_vars *vars)
{
	t_camera	camera;
	t_list		*cam;

	if (strarr_len(line) == 4)
	{
		camera.pos = get_float3(line[1]);
		camera.view = get_float3_normal(line[2]);
		if ((camera.angle = ft_atoi(line[3])))
		{
			cam = ft_lstnew(&camera);
			if (cam)
			{
				ft_lstadd_front(&(vars->cameras), ft_lstnew(&camera));
				printf("Camera added\n");
			}
			return (0);
		}
		exit(-1);		
	}
	else
	{
		printf("Wrong input getting camera %i\n", strarr_len(line));
		exit(-1);
	}
}

int	create_light(char **line, t_vars *vars)
{
	t_light	light;
	t_int3	color;
	t_list	*light_list;

	if (strarr_len(line) == 4)
	{
		light.pos = get_float3(line[1]);
		light.bright = atof(line[2]);
		color = get_int3_color(line[3]);
		light.color = create_trgb(0, color.x, color.y, color.z);
		light_list = ft_lstnew(&light);
		if (light_list)
		{
			ft_lstadd_front(&(vars->lights), ft_lstnew(&light));
			printf("Light added\n");
		}
		printf("light done\n");
		return (0);
	}
	else
	{
		printf("Wrong input getting light %i\n", strarr_len(line));
		exit(-1);
	}
}
