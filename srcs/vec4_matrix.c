/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:33:27 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 18:09:22 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

t_double3		mult_rot_matrix(t_double3 p, t_rot_matrix m)
{
	t_double3 res;

	res.x = p.x * m.d[0][0] + p.y * m.d[1][0] + p.z * m.d[2][0];
	res.y = p.x * m.d[0][1] + p.y * m.d[1][1] + p.z * m.d[2][1];
	res.z = p.x * m.d[0][2] + p.y * m.d[1][2] + p.z * m.d[2][2];
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

t_matrix		look_at(t_camera camera)
{
	t_matrix	m;
	t_double3	right;
	t_double3	up;

	right = camera.dir_x;
	up = camera.dir_y;
	m.d[0][0] = right.x;
	m.d[0][1] = right.y;
	m.d[0][2] = right.z;
	m.d[1][0] = up.x;
	m.d[1][1] = up.y;
	m.d[1][2] = up.z;
	m.d[2][0] = camera.dir.x;
	m.d[2][1] = camera.dir.y;
	m.d[2][2] = camera.dir.z;
	m.d[3][0] = camera.pos.x;
	m.d[3][1] = camera.pos.y;
	m.d[3][2] = camera.pos.z;
	return (m);
}
