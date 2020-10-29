/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:26:50 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/29 20:08:32 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

void	resize_plane(t_plane *pl, int key)
{
	return ;
}

void	resize_sphere(t_sphere *sp, int key)
{
	if (key == Z && (sp->radius - 0.5 > 0))
		sp->radius -= 0.5;
	else if (key == X)
		sp->radius += 0.5;
}

void	resize_square(t_square *sq, int key)
{
	if (key == Z && (sq->side - 0.5 > 0))
		sq->side -= 0.5;
	else if (key == X)
		sq->side += 0.5;
}

void	resize_cylinder(t_cylinder *cy, int key)
{
	if (key == Z && (cy->height - 0.2 > 0) && (cy->diameter - 0.2 > 0))
	{
		cy->diameter -= 0.2;
		cy->height -= 0.2;
	}
	else if (key == X)
	{
		cy->diameter += 0.2;
		cy->height += +0.2;
	}
}

void	resize_triangle_add(t_double3 *p, t_double3 center, int key)
{
	t_double3	vec;

	vec = vec_sub(*p, center);
	if (key == Z)
		vec = mult_float(0.8, vec);
	else
		vec = mult_float(1.2, vec);
	*p = vec_add(center, vec);
}

double	triangle_square_check(t_triangle *tr)
{
	double	square;
	double	side_a;
	double	side_b;
	double	side_c;
	double	p;

	side_a = vec_len(vec_sub(tr->b, tr->a));
	side_b = vec_len(vec_sub(tr->b, tr->c));
	side_c = vec_len(vec_sub(tr->c, tr->a));
	p = (side_a + side_b + side_c) / 2;
	square = sqrt(p * (p - side_a) * (p - side_b) * (p - side_c));
	return (square);
}

void	resize_triangle(t_triangle *tr, int key)
{
	t_double3	center;

	if ((key == Z) && (triangle_square_check(tr) < 1.0))
		return ;
	center.x = (tr->a.x + tr->b.x + tr->c.x) / 3;
	center.y = (tr->a.y + tr->b.y + tr->c.y) / 3;
	center.z = (tr->a.z + tr->b.z + tr->c.z) / 3;
	resize_triangle_add(&(tr->a), center, key);
	resize_triangle_add(&(tr->b), center, key);
	resize_triangle_add(&(tr->c), center, key);
}