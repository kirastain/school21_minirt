/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:35:09 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 15:16:06 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

t_colrgb	init_color(float r, float g, float b)
{
	t_colrgb	color;

	color.red = r;
	color.blue = b;
	color.green = g;
	return (color);
}
