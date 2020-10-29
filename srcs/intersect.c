/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:55:20 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/29 22:36:44 by bbelen           ###   ########.fr       */
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
	double		denom;
	t_double3	hit_point;
	t_double3	p0l0;

	denom = dot(sq->normal, ray.dir);
	if (fabs(denom) > MIN_DIST)
	{
		p0l0 = vec_sub(sq->center, ray.o);
		*t = dot(p0l0, sq->normal) / denom;
		hit_point = vec_add(ray.o, mult_float(*t, ray.dir));
		if (*t >= 0)
		{
			if (fabs(hit_point.x - sq->center.x) > (sq->side / 2))
				return (0);
			if (fabs(hit_point.y - sq->center.y) > (sq->side / 2))
				return (0);
			if (fabs(hit_point.z - sq->center.z) > (sq->side / 2))
				return (0);
			else
				return (1);
		}
		else
			return (0);
	}
	return (0);
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

int		intersect_main_shadow(t_list *objects, t_ray ray, t_object **object,
				double *t_min, t_object *work_object)
{
	t_list		*current;
	t_object	*this_object;
	double		t;

	*object = NULL;
	current = objects;
	*t_min = MAX_DIST;
	while (current != NULL)
	{
		this_object = current->content;
		if (intersects(this_object, &t, ray) && (this_object != work_object))
		{
			if (t < *t_min && t > 0.01)
			{
				*object = this_object;
				*t_min = t;
			}
		}
		current = current->next;
	}
	if (*object != NULL)
		return (1);
	else
		return (0);
}

int		intersect_main(t_list *objects, t_ray ray, t_object **object,
				double *t_min)
{
	t_list		*current;
	t_object	*this_object;
	double		t;

	*object = NULL;
	current = objects;
	*t_min = MAX_DIST;
	while (current != NULL)
	{
		this_object = current->content;
		if (intersects(this_object, &t, ray))
		{
			if (t < *t_min && t > 0.001)
			{
				*object = this_object;
				*t_min = t;
			}
		}
		current = current->next;
	}
	if (*object != NULL)
		return (1);
	else
		return (0);
}

int		intersects(t_object *obj, double *t, t_ray ray)
{
	if (obj->type == T_PLANE)
		return (intersects_plane(obj, t, ray));
	else if (obj->type == T_SPHERE)
		return (intersects_sphere(obj, t, ray));
	else if (obj->type == T_SQUARE)
		return (intersects_square(ray, (t_square*)obj->obj, t));
	else if (obj->type == T_CYLINDER)
		return (intersects_cylinder(ray, (t_cylinder*)obj->obj, t));
	else
		return (intersects_triangle((t_triangle*)obj->obj, t, ray));
	return (0);
}
