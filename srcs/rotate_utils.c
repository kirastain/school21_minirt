/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:08:55 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/29 21:50:51 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

t_rot_matrix	get_x_m(float degree)
{
	t_rot_matrix	m;

	m.type = 'x';
	m.d[0][0] = 1;
	m.d[0][1] = 0;
	m.d[0][2] = 0;
	m.d[1][0] = 0;
	m.d[1][1] = cosf(degree);
	m.d[1][2] = -1 * sinf(degree);
	m.d[2][0] = 0;
	m.d[2][1] = sinf(degree);
	m.d[2][2] = cosf(degree);
	return (m);
}

t_rot_matrix	get_y_m(float degree)
{
	t_rot_matrix	m;

	m.type = 'y';
	m.d[0][0] = cosf(degree);
	m.d[0][1] = 0;
	m.d[0][2] = sinf(degree);
	m.d[1][0] = 0;
	m.d[1][1] = 1;
	m.d[1][2] = 0;
	m.d[2][0] = -1 * sinf(degree);
	m.d[2][1] = 0;
	m.d[2][2] = cosf(degree);
	return (m);
}

t_rot_matrix	get_z_m(float degree)
{
	t_rot_matrix	m;

	m.type = 'z';
	m.d[0][0] = cosf(degree);
	m.d[0][1] = -1 * sinf(degree);
	m.d[0][2] = 0;
	m.d[1][0] = sinf(degree);
	m.d[1][1] = cosf(degree);
	m.d[1][2] = 0;
	m.d[2][0] = 0;
	m.d[2][1] = 0;
	m.d[2][2] = 1;
	return (m);
}

t_rot_matrix	get_rot_m(int key)
{
	if (key == T)
		return (get_x_m(-ROTATE));
	if (key == Y)
		return (get_x_m(ROTATE));
	if (key == G)
		return (get_y_m(-ROTATE));
	if (key == H)
		return (get_y_m(ROTATE));
	if (key == B)
		return (get_z_m(-ROTATE));	
	else
		return (get_z_m(ROTATE));	
}