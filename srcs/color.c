/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:16:17 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/29 22:48:03 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

t_colrgb	get_colrgb(int red, int green, int blue)
{
	t_colrgb	color;

	color.red = (double)red / 256;
	color.green = (double)green / 256;
	color.blue = (double)blue / 256;
	return (color);
}

t_colrgb	int_to_color(int color)
{
	t_int_color	a;
	t_colrgb	result;

	a.integer = color;
	result.red = a.comps[2];
	result.green = a.comps[1];
	result.blue = a.comps[0];
	return (result);
}

int			color_to_int(t_int3 color)
{
	t_int_color a;

	a.comps[2] = color.x;
	a.comps[1] = color.y;
	a.comps[0] = color.z;
	return (a.integer);
}

int			to_int(t_colrgb a)
{
	int		result;
	t_int3	this;

	this.x = a.red * 256;
	this.y = a.green * 256;
	this.z = a.blue * 256;
	result = color_to_int(this);
	return (result);
}
