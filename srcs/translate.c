/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:24:23 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/29 19:24:40 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

void	translate_plane(t_plane *pl, int key)
{
	if (key == W)
		pl->center.y += 2;
	else if (key == S)
		pl->center.y -= 2;
	else if (key == A)
		pl->center.x -= 2;
	else if (key == D)
		pl->center.x += 2;
	else if (key == R)
		pl->center.z -= 2;
	else if (key == F)
		pl->center.z += 2;
}

void	translate_sphere(t_sphere *sp, int key)
{
	if (key == W)
		sp->center.y += 2;
	else if (key == S)
		sp->center.y -= 2;
	else if (key == A)
		sp->center.x -= 2;
	else if (key == D)
		sp->center.x += 2;
	else if (key == R)
		sp->center.z -= 2;
	else if (key == F)
		sp->center.z += 2;
}

void	translate_square(t_square *sq, int key)
{
	if (key == W)
		sq->center.y += 2;
	else if (key == S)
		sq->center.y -= 2;
	else if (key == A)
		sq->center.x -= 2;
	else if (key == D)
		sq->center.x += 2;
	else if (key == R)
		sq->center.z -= 2;
	else if (key == F)
		sq->center.z += 2;
}	

void	translate_cylinder(t_cylinder *cy, int key)
{
	if (key == W)
		cy->center.y += 2;
	else if (key == S)
		cy->center.y -= 2;
	else if (key == A)
		cy->center.x += 2;
	else if (key == D)
		cy->center.x -= 2;
	else if (key == R)
		cy->center.z -= 2;
	else if (key == F)
		cy->center.z += 2;
}

void	translate_triangle(t_triangle *tr, int key)
{
	if (key == W)
	{
		tr->a.y += 2;
		tr->b.y += 2;
		tr->c.y += 2;
	}
	else if (key == S)
	{
		tr->a.y -= 2;
		tr->b.y -= 2;
		tr->c.y -= 2;
	}
	else if (key == A)
	{
		tr->a.x += 2;
		tr->b.x += 2;
		tr->c.x += 2;
	}
	else if (key == D)
	{
		tr->a.x -= 2;
		tr->b.x -= 2;
		tr->c.x -= 2;
	}
	else if (key == R)
	{
		tr->a.z -= 2;
		tr->b.z -= 2;
		tr->c.z -= 2;
	}
	else if (key == F)
	{
		tr->a.z += 2;
		tr->b.z += 2;
		tr->c.z += 2;
	}
}
