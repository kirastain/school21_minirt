/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:25:52 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 15:26:31 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

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
