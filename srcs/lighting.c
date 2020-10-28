/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 19:07:40 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/16 19:13:52 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

double		spec_coeff(t_light light, t_surf surf)
{
	t_double3		light_ray;
	t_double3		reflectance_vector;
	t_double3		back_view_ray;
	double		result;

	light_ray = vec_sub(light.pos, surf.hitPoint);
	light_ray = vec_normalize(light_ray);
	reflectance_vector = vec_add(light_ray,
								mult_float(-2, mult_float(dot(light_ray, surf.normal), surf.normal)));
	back_view_ray = vec_sub(surf.hitPoint, surf.ray.o);
	back_view_ray = vec_normalize(back_view_ray);
	result = fmax(dot(reflectance_vector, back_view_ray), 0);
	result = pow(result, 10);
	return (result);
}

t_colrgb	specular(t_light light, t_surf surf)
{
	t_colrgb	specular;
	t_colrgb	highlight;
	double		metalness;
	double		coeff;

	metalness = 0.1;
	highlight.red = 1;
	highlight.green = 1;
	highlight.blue = 1;
	highlight = colrgb_amb(highlight, (1 - metalness));
	specular = colrgb_add(
					colrgb_amb(surf.object->color, metalness),
					highlight);
	coeff = spec_coeff(light, surf);
	return (colrgb_amb(specular, coeff));
}