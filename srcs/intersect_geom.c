/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_geom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:17:06 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 17:56:18 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

int		intersects_plane(t_object *obj, double *t, t_ray ray)
{
	double	t0;
	t_plane	*pl;

	pl = obj->obj;
	t0 = dot(vec_sub(pl->center, ray.o), pl->normal) / dot(ray.dir, pl->normal);
	if (t0 > MIN_DIST)
	{
		*t = t0;
		return (1);
	}
	return (0);
}

int		intersects_sphere(t_object *obj, double *t, t_ray ray)
{
	double		t0;
	t_sphere	*sp;
	t_double3	k;
	t_double3	inv_dir;
	double		t1;

	sp = obj->obj;
	inv_dir = vec_sub(ray.o, sp->center);
	k.x = dot(ray.dir, ray.dir);
	k.y = 2.0 * dot(ray.dir, inv_dir);
	k.z = dot(inv_dir, inv_dir) - (sp->radius * sp->radius);
	if (solve_quadratic(new_qparams(k.x, k.y, k.z), &t0, &t1) == 0)
		return (0);
	*t = (t0 < t1 ? t0 : t1);
	return (1);
}

int		intersects_square(t_ray ray, t_square *sq, double *t)
{
	t_triangle	tr1;
	t_triangle	tr2;

	tr1.a = sq->a;
	tr1.b = sq->b;
	tr1.c = sq->c;
	tr2.a = sq->a;
	tr2.b = sq->c;
	tr2.c = sq->d;
	return (intersects_triangle(&tr1, t, ray) ||
			intersects_triangle(&tr2, t, ray));
}

int		intersects_cylinder(t_ray ray, t_cylinder *cylinder, double *t)
{
	double t0;
	double t1;

	if (!cyl_get_roots(&t0, &t1, *cylinder, ray))
		return (0);
	if (t0 > 0)
		check_t(&t0, *cylinder, ray);
	if (t1 > 0)
		check_t(&t1, *cylinder, ray);
	if (t0 < 0 && t1 < 0)
		return (0);
	if (t1 < t0)
		*t = (t1 > 0 ? t1 : t0);
	else
		*t = (t0 > 0 ? t0 : t1);
	return (1);
}

int		intersects_triangle(t_triangle *tr, double *t, t_ray ray)
{
	t_double3	a;
	t_double3	b;
	t_double3	n;
	double		angle;
	t_double3	p;

	a = vec_sub(tr->b, tr->a);
	b = vec_sub(tr->c, tr->a);
	n = vec_cross(a, b);
	n = vec_normalize(n);
	angle = dot(n, ray.dir);
	if (fabs(angle) < MIN_DIST)
		return (0);
	*t = (dot(n, vec_sub(tr->a, ray.o)) / angle);
	if (*t < 0)
		return (0);
	p = vec_add(ray.o, mult_float(*t, ray.dir));
	return (check_edges(*tr, p, n));
}
