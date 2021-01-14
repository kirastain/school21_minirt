/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:26:50 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 18:13:16 by bbelen           ###   ########.fr       */
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
	get_sq_points(sq);
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
