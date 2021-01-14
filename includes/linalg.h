/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linalg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:27:03 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 12:44:52 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINALG_H
# define LINALG_H

# include "ft_minirt.h"

typedef struct	s_double3
{
	double		x;
	double		y;
	double		z;
}				t_double3;

typedef struct	s_int3
{
	int			x;
	int			y;
	int			z;
}				t_int3;

typedef struct	s_matrix
{
	double		d[4][4];
}				t_matrix;

typedef struct	s_rot_matrix
{
	double		d[3][3];
	char		type;
}				t_rot_matrix;

typedef struct	s_qparams
{
	double		a;
	double		b;
	double		c;
}				t_qparams;

t_double3		vec_create(double x, double y, double z);
double			vec_len(t_double3 vec);
t_double3		vec_normalize(t_double3 vec);
t_double3		vec_add(t_double3 u, t_double3 v);
double			dot(t_double3 u, t_double3 v);
t_double3		vec_sub(t_double3 u, t_double3 v);
t_double3		mult_float(double a, t_double3 u);
t_double3		vec_inv(t_double3 u);
t_double3		vec_cross(t_double3 u, t_double3 v);

t_double3		get_double3(char *line);
t_double3		get_double3_normal(char *line);

t_double3		multiply_by_matrix(t_double3 p, t_matrix m);
t_double3		mult_rot_matrix(t_double3 p, t_rot_matrix m);

void			swap_doubles(double *a, double *b);
t_qparams		new_qparams(double a, double b, double c);
t_double3		lin_comb(t_double3 a, double k1, t_double3 b, double k2);
t_double3		vec_divide(t_double3 u, t_double3 v);

#endif
