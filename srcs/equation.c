/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 19:36:47 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 17:49:15 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

int			solve_quadratic(t_qparams params, double *x0, double *x1)
{
	double discr;
	double q;

	discr = pow(params.b, 2) - 4 * params.a * params.c;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		*x0 = -0.5 * params.b / params.a;
		*x1 = -0.5 * params.b / params.a;
	}
	else
	{
		if (params.b > 0)
			q = -1 * (params.b + sqrt(discr)) / 2;
		else
			q = -1 * (params.b - sqrt(discr)) / 2;
		*x0 = q / params.a;
		*x1 = params.c / q;
	}
	if (*x0 > *x1)
		swap_doubles(x0, x1);
	return (1);
}

void		check_t(double *t, t_cylinder cylinder, t_ray ray)
{
	t_double3 q;
	t_double3 p2;

	p2 = vec_add(cylinder.center, mult_float(cylinder.height, cylinder.normal));
	q = vec_add(ray.o, mult_float(*t, ray.dir));
	if (dot(cylinder.normal, vec_sub(q, cylinder.center)) <= 0)
		*t = -1;
	if (dot(cylinder.normal, vec_sub(q, p2)) >= 0)
		*t = -1;
}

int			cyl_get_roots(double *t0, double *t1, t_cylinder cy, t_ray ray)
{
	t_double3	a_sqrt;
	t_double3	right;
	double		a;
	double		b;
	double		c;

	a_sqrt = vec_sub(ray.dir,
			mult_float(dot(ray.dir, cy.normal), cy.normal));
	a = dot(a_sqrt, a_sqrt);
	right = vec_sub(vec_sub(ray.o, cy.center),
			mult_float(dot(vec_sub(ray.o, cy.center),
			cy.normal), cy.normal));
	b = 2 * dot(a_sqrt, right);
	c = dot(right, right) - ((cy.diameter / 2) * (cy.diameter / 2));
	if (!solve_quadratic(new_qparams(a, b, c), t0, t1))
		return (0);
	return (1);
}

int			check_edges(t_triangle triangle, t_double3 p, t_double3 n)
{
	t_double3	c;
	t_double3	edge;
	t_double3	vp;

	edge = vec_sub(triangle.b, triangle.a);
	vp = vec_sub(p, triangle.a);
	c = vec_cross(edge, vp);
	if (dot(c, n) < 0)
		return (0);
	edge = vec_sub(triangle.c, triangle.b);
	vp = vec_sub(p, triangle.b);
	c = vec_cross(edge, vp);
	if (dot(c, n) < 0)
		return (0);
	edge = vec_sub(triangle.a, triangle.c);
	vp = vec_sub(p, triangle.c);
	c = vec_cross(edge, vp);
	if (dot(c, n) < 0)
		return (0);
	return (1);
}
