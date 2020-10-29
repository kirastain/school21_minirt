/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:23:51 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/29 17:11:14 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"
#include <stdio.h>

int	strarr_len(char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

t_double3	get_double3(char *line)
{
	t_double3	pos;

	pos.x = atof(line);
	while (*line != ',')
		line++;
	pos.y = atof(++line);
	while (*line != ',')
		line++;
	pos.z = atof(++line);
	return (pos);
}

t_double3	get_double3_normal(char *line)
{
	t_double3	norm;

	norm = get_double3(line);
	if ((norm.x >= -1.0f && norm.x <= 1.0f) || (norm.y >= -1.0f && norm.y <= 1.0f) ||
	(norm.z >= -1.0f && norm.z >= 1.0f))
		return (norm);
	else
		error_quit("Error\nWrong input view of norm vector\n");
	return (norm);	
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
		error_quit("Error\nWrong colors input\n");
	return (color);
}

static int	parsing_line(char **line, t_vars *vars)
{
	if (ft_strncmp(line[0], "R", 2) == 0 && !(vars->scene->width))
		create_res(line, vars);
	else if (ft_strncmp(line[0], "A", 3) == 0 && !(vars->scene->ambient))
		create_amb(line, vars);
	else if (ft_strncmp(line[0], "c", 3) == 0)
		create_camera(line, vars);
	else if (ft_strncmp(line[0], "l", 3) == 0)
		create_light(line, vars);
	else if (ft_strncmp(line[0], "pl", 3) == 0)
		create_plane(line, vars);
	else if (ft_strncmp(line[0], "sp", 3) == 0)
		create_sphere(line, vars);
	else if (ft_strncmp(line[0], "sq", 3) == 0)
		create_square(line, vars);
	else if (ft_strncmp(line[0], "cy", 3) == 0)
		create_cylinder(line, vars);
	else if (ft_strncmp(line[0], "tr", 3) == 0)
		create_triangle(line, vars);
	else
		error_quit("Error\nWrong input parsing\n");
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
				error_quit("Error\nWrong input parsing\n");
		}
	}
	data = ft_split(line, ' ');
	if (data[0])
	{
		if (parsing_line(data, vars) == -1)
			error_quit("Error\nWrong input parsing\n");
	}
	return (0);
}