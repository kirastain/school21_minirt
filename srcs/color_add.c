/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:35:09 by bbelen            #+#    #+#             */
/*   Updated: 2020/08/13 16:09:07 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minirt.h" 
#include <stdio.h>

int	add_shade(double distance, int trgb)
{
	int	r;
	int	g;
	int	b;

	r = (int)(get_r(trgb) / (256 * 256) * distance);
	g = (int)(get_g(trgb) / 256 * distance);
	b = (int)(get_b(trgb) * distance);
	return (create_trgb((int)(get_t(trgb) / (256 * 256 * 256)), r, g, b));
}

int	get_opposite(int trgb)
{
	int	invert;
	int	r;
	int	g;
	int	b;

	invert = ~trgb;
	r = (int)(get_r(invert) / (256 * 256));
	g = (int)(get_g(invert) / 256);
	b = (int)(get_b(invert));
	return (create_trgb((int)(get_t(trgb) / (256 * 256 * 256)), r, g, b));
}
