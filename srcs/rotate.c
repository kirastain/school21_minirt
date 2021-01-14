/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:09:17 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 18:03:30 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

void	rotate_plane(t_plane *pl, int key)
{
	t_rot_matrix	m;

	m = get_rot_m(key, ROTATE);
	pl->normal = mult_rot_matrix(pl->normal, m);
}

void	rotate_square(t_square *sq, int key)
{
	t_rot_matrix	m;

	m = get_rot_m(key, ROTATE);
	sq->normal = mult_rot_matrix(sq->normal, m);
	if (key == B || key == N)
	{
		if ((dot(sq->normal, vec_create(1, 0, 0)) == 0) && (dot(sq->normal,
				vec_create(0, 1, 0)) == 0))
			work_with_abcd(m, sq, key);
	}
	else if (key == G || key == H)
	{
		if ((dot(sq->normal, vec_create(1, 0, 0)) == 0) && (dot(sq->normal,
				vec_create(0, 0, 1)) == 0))
			work_with_abcd(m, sq, key);
	}
	else
	{
		if ((dot(sq->normal, vec_create(0, 1, 0)) == 0) && (dot(sq->normal,
				vec_create(0, 0, 1)) == 0))
			work_with_abcd(m, sq, key);
	}
}

void	rotate_cylinder(t_cylinder *cy, int key)
{
	t_rot_matrix	m;

	m = get_rot_m(key, ROTATE);
	cy->normal = mult_rot_matrix(cy->normal, m);
}

void	rotate_camera(t_camera *cam, int key)
{
	t_rot_matrix	m;

	m = get_rot_m(key, ROTATE);
	cam->dir = mult_rot_matrix(cam->dir, m);
	cam->dir_y = mult_rot_matrix(cam->dir_y, m);
	cam->dir_x = mult_rot_matrix(cam->dir_x, m);
}

void	rotate_triangle(t_triangle *tr, int key)
{
	t_double3		center;
	t_double3		a;
	t_double3		b;
	t_double3		c;
	t_rot_matrix	m;

	center.x = (tr->a.x + tr->b.x + tr->c.x) / 3;
	center.y = (tr->a.y + tr->b.y + tr->c.y) / 3;
	center.z = (tr->a.z + tr->b.z + tr->c.z) / 3;
	a = vec_sub(tr->a, center);
	b = vec_sub(tr->b, center);
	c = vec_sub(tr->c, center);
	m = get_rot_m(key, ROTATE);
	a = mult_rot_matrix(a, m);
	b = mult_rot_matrix(b, m);
	c = mult_rot_matrix(c, m);
	tr->a = vec_sub(center, a);
	tr->b = vec_sub(center, b);
	tr->c = vec_sub(center, c);
}
