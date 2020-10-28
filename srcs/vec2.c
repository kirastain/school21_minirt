/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:35:47 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/15 18:44:00 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

t_double3	vec_normalize(t_double3 vec)
{
	double	len;
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

t_double3	mult_float(double a, t_double3 u)
{
	t_double3	res;
	
	res.x = a * u.x;
	res.y = a * u.y;
	res.z = a * u.z;
	return (res);	
}

double 	dot(t_double3 u, t_double3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_double3	vec_sub(t_double3 u, t_double3 v)
{
	t_double3	res;
	
	res.x = u.x - v.x;
	res.y = u.y - v.y;
	res.z = u.z - v.z;
	//printf("substr is %f %f %f\n", res.x, res.y, res.z);
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

t_double3		multiply_by_matrix(t_double3 p, t_matrix m)
{
	t_double3 res;

	res.x = p.x * m.d[0][0] + p.y * m.d[1][0] + p.z * m.d[2][0] + m.d[3][0];
	res.y = p.x * m.d[0][1] + p.y * m.d[1][1] + p.z * m.d[2][1] + m.d[3][1];
	res.z = p.x * m.d[0][2] + p.y * m.d[1][2] + p.z * m.d[2][2] + m.d[3][2];
	return (res);
}

t_matrix	look_at(t_double3 origin, t_double3 cam_vector)
{
	t_matrix	m;
	t_double3		random;
	t_double3		right;
	t_double3		up;

	random = vec_create(0, 1, 0);
	random = vec_normalize(random);
	right = vec_cross(random, cam_vector);
	right = vec_normalize(right);
	up = vec_cross(cam_vector, right);
	up = vec_normalize(up);
	m.d[0][0] = right.x;
	m.d[0][1] = right.y;
	m.d[0][2] = right.z;
	m.d[1][0] = up.x;
	m.d[1][1] = up.y;
	m.d[1][2] = up.z;
	m.d[2][0] = cam_vector.x;
	m.d[2][1] = cam_vector.y;
	m.d[2][2] = cam_vector.z;
	m.d[3][0] = origin.x;
	m.d[3][1] = origin.y;
	m.d[3][2] = origin.z;
	return (m);
}