/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen@student.21-school.ru <bbelen>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:23:51 by bbelen            #+#    #+#             */
/*   Updated: 2020/09/22 19:08:46 by bbelen@stud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minirt.h"
#include <stdio.h>

int	strarr_len(char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

t_float3	get_float3(char *line)
{
	t_float3	pos;

	pos.x = atof(line);
	while (*line != ',')
		line++;
	pos.y = atof(++line);
	while (*line != ',')
		line++;
	pos.z = atof(++line);
	return (pos);
	/*else
	{
		printf("Wrong pos float3 input\n");
		exit(-1);
	}*/	
}

t_float3	get_float3_normal(char *line)
{
	t_float3	norm;

	norm = get_float3(line);
	if ((norm.x >= -1.0f && norm.x <= 1.0f) || (norm.y >= -1.0f && norm.y <= 1.0f) ||
	(norm.z >= -1.0f && norm.z >= 1.0f))
		return (norm);
	else
	{
		printf("Wrong input view or norm vec\n");
		exit(-1);
	}
	
}

t_int3	get_int3_color(char *line)
{
	t_int3	color;

	color.x = ft_atoi(line);
	while (*line != ',')
		line++;
	color.y = ft_atoi(++line);
	while (*line != ',')
		line++;
	color.z = ft_atoi(++line);
	if ((color.x >= 0 && color.x <= 255) || (color.y >= 0 && color.y <= 255)
	|| (color.z >= 0 && color.z <= 255))
		return (color);
	else
	{
		printf("Wrong colors input\n");
		exit(-1);
	}
	
}

static int	parsing_line(char **line, t_vars *vars)
{
	if (ft_strncmp(line[0], "R", 2) == 0 && !(vars->res_x))
		create_res(line, vars);
	else if (ft_strncmp(line[0], "A", 3) == 0 && !(vars->ambience))
		create_amb(line, vars);
	else if (ft_strncmp(line[0], "c", 3) == 0)
		//printf("cam\n");
		{
		create_camera(line, vars);
		t_camera *cam = vars->cameras->content;
		printf("in validation %f %d\n", cam->pos.x, 0);
		}
	else if (ft_strncmp(line[0], "l", 3) == 0)
		//printf("light\n");
		create_light(line, vars);
	else if (ft_strncmp(line[0], "pl", 3) == 0)
		//printf("plane is found\n");
		create_plane(line, vars);
	else if (ft_strncmp(line[0], "sp", 3) == 0)
		//printf("sphere\n");
		create_sphere(line, vars);
	else if (ft_strncmp(line[0], "sq", 3) == 0)
		//printf("square\n");
		create_square(line, vars);
	else if (ft_strncmp(line[0], "cy", 3) == 0)
		//printf("cylinder\n");
		create_cylinder(line, vars);
	else if (ft_strncmp(line[0], "tr", 3) == 0)
		//printf("triangle\n");
		create_triangle(line, vars);
	else
		return (-1);
	return (0);
}

int	checking_flags(int fd, t_vars *vars)
{
	char	*line;
	char	**data;

	while (get_next_line(fd, &line) == 1)
	{
		data = ft_split(line, ' ');
		if (data[0])
		{
			if (parsing_line(data, vars) == -1)
			{
				printf("Wrong input parsing\n");
				return (-1);
			}
		}
	}
	data = ft_split(line, ' ');
	if (data[0])
	{
		if (parsing_line(data, vars) == -1)
		{
			printf("Wrong input parsing\n");
			return (-1);
		}
	}
	return (0);
}