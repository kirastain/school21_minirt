/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen@student.21-school.ru <bbelen>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:55:20 by bbelen            #+#    #+#             */
/*   Updated: 2020/09/23 19:01:39 by bbelen@stud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minirt.h"

int	intersects_plane(t_object *obj, t_surf *surf, t_ray *ray)
{
	float	t;
	t_plane	*pl;
	
	pl = obj->obj;
	//printf("ray o is%f %f %f\n", ray->o.x, ray->o.y, ray->o.z);
	//printf("ray dir is %f %f %f\n", ray->dir.x, ray->dir.y, ray->dir.z);
	//printf("surf t is %f\n", surf->t);
	//printf("dot 1 is %f\n", dot(float3_substr(pl->center, ray->o), pl->normal));
	//printf("dot 2 is %f\n", dot(ray->dir, pl->normal));
	t = dot(float3_substr(pl->center, ray->o), pl->normal) / dot(ray->dir, pl->normal);
	//printf("plane t is %f\n", t);
	if (t > MIN_DIST && t < surf->t)
	{
		//printf("plane t is %f\n", t);
		surf->t = t;
		surf->notmal = pl->normal;
		surf->hit = 1;
		return (1);
	}
	//surf.t = dot((point - ray.o), normal) / dot(ray.d, normal);
	return (0);
}

int	intersects_sphere(t_object *obj, t_surf *surf, t_ray ray)
{
	float		t;
	t_sphere	*sp;
	t_float3	k;
	t_float3	inv_dir;
	float		d;

	sp = obj->obj;
	inv_dir = float3_substr(ray.o, sp->center);
	//printf("sphere is %f %f %f rad %f\n", sp->center.x, sp->center.y, sp->center.z, sp->radius);
	//printf("ray dir is %f %f %f\n", ray->dir.x, ray->dir.y, ray->dir.z);
	k.x = dot(ray.dir, ray.dir);
	k.y = dot(mult_float(2, inv_dir), ray.dir);
	k.z = dot(inv_dir, inv_dir) - sp->radius * sp->radius;
	d = k.y * k.y - 4 * k.x * k.z;
	//printf("k is %f %f %f\n", k.x, k.y, k.z);
	//printf("d is %f\n", d);
	if (d < 0)
	{
		//printf("d < 0\n");
		return (0);
	}
	t = (-k.y - sqrt(d)) / 2 * k.x;
	//printf("sphere t is %f\n", t);
	if (t > MIN_DIST && t < surf->t)
	{
		//printf("sphere t is %f\n", t);
		surf->t = t;
		surf->hitPoint = vec_add(ray.o, mult_float(surf->t, ray.dir));
		surf->notmal = vec_normalize(float3_substr(surf->hitPoint, sp->center));
		surf->hit = 1;
		return (1);
	}
	t = (-k.y + sqrt(d)) / 2 * k.x;
	if (t > MIN_DIST && t < surf->t)
	{
		printf("sphere t is %f\n", t);
		surf->t = t;
		surf->hitPoint = vec_add(ray.o, mult_float(surf->t, ray.dir));
		surf->notmal = vec_normalize(float3_substr(surf->hitPoint, sp->center));
		surf->hit = 1;
		return (1);
	}
	return (0);
}

int	intersects_square()
{
	return (0);
}

int	intersects_cylinder()
{
	return (0);
}

int	intersects_triangle()//t_object *obj, t_surf *surf, t_ray ray)
{
	/*t_triangle	*tr;
	t_float3	T;
    t_float3	E1;
    t_float3	E2;
	t_float3	tuv; = (1 / dot(cross(ray.d, E2), E1)) * float3((dot(cross(T, E1), E2)), dot(cross(ray.d, E2), T), dot(cross(T, E1), ray.d));
    
	tr = obj->obj;
	T = float3_substr(ray.o, tr->a);
	E1 = float3_substr(tr->b, tr->a);
	E2 = float3_substr(tr->c, tr->a);
    if (tuv.y < 0 || tuv.z < 0 || (tuv.y + tuv.z) > 1)
        return (0);

    if (tuv.x > MIN_DIST && tuv.x < surf->t)
    {
        surf->hit = 1;
        surf->hitPoint = ray.o + surf.t * ray.d;
        surf->notmal = vec_cross(float3_substr(tr->b. tr->a), float3_substr(tr->c, tr->a));
        return (1);
    }*/
    return (0);
}

int	intersects(t_object *obj, t_surf *surf, t_ray *ray)
{
	if (obj->type == T_PLANE)
	{
		//printf("goes into the plane\n");
		return (intersects_plane(obj, surf, ray));
	}
	else if (obj->type == T_SPHERE)
	{
		//printf("into the sphere\n");
		return (intersects_sphere(obj, surf, *ray));
	}
	else if (obj->type == T_SQUARE)
		intersects_square();
	else if (obj->type == T_CYLINDER)
		intersects_cylinder();
	else
		intersects_triangle();
	return (0);
}

