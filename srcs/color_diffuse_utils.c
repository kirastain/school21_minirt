/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_diffuse_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:45:29 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/29 22:46:23 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

t_colrgb	colrgb_amb(t_colrgb col, float coeff)
{
	t_colrgb color;

	color.red = fmin(col.red * coeff, 1);
	color.green = fmin(col.green * coeff, 1);
	color.blue = fmin(col.blue * coeff, 1);
	return (color);
}

t_colrgb	colrgb_add(t_colrgb col, t_colrgb col_2)
{
	t_colrgb	color;

	color.red = fmin(col.red + col_2.red, 0.99);
	color.green = fmin(col.green + col_2.green, 0.99);
	color.blue = fmin(col.blue + col_2.blue, 0.99);
	return (color);
}

t_colrgb	colrgb_mult(t_colrgb col, t_colrgb col_2)
{
	t_colrgb color;

	color.red = fmin(col.red * col_2.red, 1);
	color.green = fmin(col.green * col_2.green, 1);
	color.blue = fmin(col.blue * col_2.blue, 1);
	return (color);
}
