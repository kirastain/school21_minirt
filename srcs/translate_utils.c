/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:35:16 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 18:32:51 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

void	translate_square_3(t_square *sq, int key)
{
	if (key == R)
	{
		sq->center.z -= 2;
		sq->a.z -= 2;
		sq->b.z -= 2;
		sq->c.z -= 2;
		sq->d.z -= 2;
	}
	else if (key == F)
	{
		sq->center.z += 2;
		sq->a.z += 2;
		sq->b.z += 2;
		sq->c.z += 2;
		sq->d.z += 2;
	}
}

void	translate_square_2(t_square *sq, int key)
{
	if (key == A)
	{
		sq->center.x += 2;
		sq->a.x += 2;
		sq->b.x += 2;
		sq->c.x += 2;
		sq->d.x += 2;
	}
	else if (key == D)
	{
		sq->center.x -= 2;
		sq->a.x -= 2;
		sq->b.x -= 2;
		sq->c.x -= 2;
		sq->d.x -= 2;
	}
	else
		translate_square_3(sq, key);
}

void	translate_triangle_2(t_triangle *tr, int key)
{
	if (key == D)
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
