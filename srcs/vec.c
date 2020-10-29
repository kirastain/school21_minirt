/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 16:32:19 by bbelen@stud       #+#    #+#             */
/*   Updated: 2020/10/29 14:36:34 by bbelen           ###   ########.fr       */
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

t_double3	lin_comb(t_double3 a, double k1, t_double3 b, double k2)
{
	t_double3 ret;

	ret.x = k1 * a.x + k2 * b.x;
	ret.y = k1 * a.y + k2 * b.y;
	ret.z = k1 * a.z + k2 * b.z;
	return (ret);
}