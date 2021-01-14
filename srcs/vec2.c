/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:35:47 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 18:08:36 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

t_double3	mult_float(double a, t_double3 u)
{
	t_double3	res;

	res.x = a * u.x;
	res.y = a * u.y;
	res.z = a * u.z;
	return (res);
}

double		dot(t_double3 u, t_double3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_double3	vec_sub(t_double3 u, t_double3 v)
{
	t_double3	res;

	res.x = u.x - v.x;
	res.y = u.y - v.y;
	res.z = u.z - v.z;
	return (res);
}

t_double3	vec_inv(t_double3 u)
{
	t_double3	res;

	res.x = -u.x;
	res.y = -u.y;
	res.z = -u.z;
	return (res);
}

t_double3	vec_cross(t_double3 u, t_double3 v)
{
	t_double3	res;

	res.x = u.y * v.z - u.z * v.y;
	res.y = u.z * v.x - u.x * v.z;
	res.z = u.x * v.y - u.y * v.x;
	return (res);
}
