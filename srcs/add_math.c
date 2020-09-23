/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen@student.21-school.ru <bbelen>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:35:47 by bbelen            #+#    #+#             */
/*   Updated: 2020/09/23 18:36:13 by bbelen@stud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minirt.h"

t_float3	vec_normalize(t_float3 vec)
{
	float	len;

	len = sqrtf(vec.x * vec.x + vec.y * vec.y * vec.z * vec.z);
	vec.x = vec.x / len;
	vec.y = vec.y / len;
	vec.z = vec.z / len;
	return (vec);
}

t_float3	vec_add(t_float3 u, t_float3 v)
{
	t_float3	res;
	
	res.x = u.x + v.x;
	res.y = u.y + v.y;
	res.z = u.z + v.z;
	return (res);
}

t_float3	mult_float(float a, t_float3 u)
{
	t_float3	res;
	
	res.x = a * u.x;
	res.y = a * u.y;
	res.z = a * u.z;
	return (res);	
}

float 	dot(t_float3 u, t_float3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_float3	float3_substr(t_float3 u, t_float3 v)
{
	t_float3	res;
	
	res.x = u.x - v.x;
	res.y = u.y - v.y;
	res.z = u.z - v.z;
	//printf("substr is %f %f %f\n", res.x, res.y, res.z);
	return (res);
}

t_float3	vec_inv(t_float3 u)
{
	t_float3	res;

	res.x = -u.x;
	res.y = -u.y;
	res.z = -u.z;
	return (res);
}

t_float3	vec_cross(t_float3 u, t_float3 v)
{
	t_float3	res;
	
	res.x = u.y * v.z - u.z * v.y;
	res.y = u.z * v.x - u.x * v.z;
	res.z = u.x * v.y - u.y * v.x;
	return (res);
}