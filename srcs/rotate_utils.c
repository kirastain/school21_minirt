/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:08:55 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 18:02:15 by bbelen           ###   ########.fr       */
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

t_rot_matrix	get_rot_m(int key, double degree)
{
	if (key == T)
		return (get_x_m(-degree));
	if (key == Y)
		return (get_x_m(degree));
	if (key == G)
		return (get_y_m(-degree));
	if (key == H)
		return (get_y_m(degree));
	if (key == B)
		return (get_z_m(-degree));
	else
		return (get_z_m(degree));
}

void			work_with_abcd(t_rot_matrix m, t_square *sq, int key)
{
	t_double3		a_vec;
	t_double3		b_vec;
	t_double3		c_vec;
	t_double3		d_vec;

	a_vec = vec_sub(sq->a, sq->center);
	a_vec = mult_rot_matrix(a_vec, m);
	c_vec = vec_sub(sq->c, sq->center);
	c_vec = mult_rot_matrix(c_vec, m);
	m = get_rot_m(key, 1.5708);
	b_vec = mult_rot_matrix(c_vec, m);
	d_vec = mult_rot_matrix(a_vec, m);
	sq->a = vec_add(sq->center, a_vec);
	sq->b = vec_add(sq->center, b_vec);
	sq->c = vec_add(sq->center, c_vec);
	sq->d = vec_add(sq->center, d_vec);
}
