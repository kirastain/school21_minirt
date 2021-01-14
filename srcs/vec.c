/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:07:21 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 18:07:40 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

t_double3	vec_create(double x, double y, double z)
{
	t_double3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

double		vec_len(t_double3 vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_double3	vec_divide(t_double3 u, t_double3 v)
{
	t_double3	res;

	res.x = u.x / v.x;
	res.y = u.y / v.y;
	res.z = u.z / v.z;
	return (res);
}

t_double3	vec_normalize(t_double3 vec)
{
	double		len;
	t_double3	res;

	len = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	res.x = vec.x / len;
	res.y = vec.y / len;
	res.z = vec.z / len;
	return (res);
}

t_double3	vec_add(t_double3 u, t_double3 v)
{
	t_double3	res;

	res.x = u.x + v.x;
	res.y = u.y + v.y;
	res.z = u.z + v.z;
	return (res);
}
