/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_geom_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:09:42 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 17:42:43 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

void	get_sq_points(t_square *sq)
{
	t_rot_matrix	m;
	t_double3		n2;
	t_double3		n1;

	if ((dot(sq->normal, vec_create(1, 0, 0)) == 0) &&
			(dot(sq->normal, vec_create(0, 1, 0)) == 0))
		m = get_x_m(1.5708);
	else if ((dot(sq->normal, vec_create(0, 1, 0)) == 0) &&
			(dot(sq->normal, vec_create(0, 0, 1)) == 0))
		m = get_z_m(1.5708);
	else
		m = get_y_m(1.5708);
	m = get_x_m(1.5708);
	n1 = vec_normalize(mult_rot_matrix(sq->normal, m));
	n2 = vec_normalize(vec_cross(sq->normal, n1));
	sq->d = vec_sub(sq->center, mult_float((sq->side / 2), n1));
	sq->d = vec_sub(sq->d, mult_float((sq->side / 2), n2));
	sq->c = vec_add(sq->center, mult_float((sq->side / 2), n1));
	sq->c = vec_sub(sq->c, mult_float((sq->side / 2), n2));
	sq->b = vec_add(sq->center, mult_float((sq->side / 2), n1));
	sq->b = vec_add(sq->b, mult_float((sq->side / 2), n2));
	sq->a = vec_sub(sq->center, mult_float((sq->side / 2), n1));
	sq->a = vec_add(sq->a, mult_float((sq->side / 2), n2));
}
