/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_diffuse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:13:28 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 15:05:43 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

t_colrgb	mix_colors(t_light light, double coeff, t_surf surf)
{
	t_colrgb	res;
	t_colrgb	light_color;
	t_colrgb	object_color;

	light_color = colrgb_amb(light.color, light.bright);
	object_color = surf.object->color;
	res = colrgb_amb(colrgb_mult(light_color, object_color), coeff);
	if (coeff)
		res = colrgb_add(res, specular(light, surf));
	return (res);
}

t_colrgb	light_contribution(t_light light, t_surf surf, t_scene scene)
{
	t_object	*closest_object2;
	double		t;
	t_double3	shadow_dir;
	t_ray		shadow_ray;
	float		coeff;

	coeff = 0;
	shadow_dir = vec_sub(light.pos, surf.hit_point);
	shadow_dir = vec_normalize(shadow_dir);
	shadow_ray = create_ray(vec_add(surf.hit_point, mult_float(0.1,
					surf.normal)), shadow_dir);
	if (!intersect_main_shadow(scene.objects, shadow_ray, &closest_object2,
					&t)
					|| t > vec_len(vec_sub(light.pos, surf.hit_point)))
	{
		coeff = fmax(0, dot(surf.normal, shadow_dir));
	}
	return (mix_colors(light, coeff, surf));
}

t_colrgb	shade(t_scene *scene, t_ray ray, t_object *object, double t_min)
{
	t_double3	hit_point;
	t_double3	normal;
	t_list		*cur_light;
	t_colrgb	color;
	t_colrgb	addition;

	color = int_to_color(0);
	hit_point = vec_add(ray.o, mult_float(t_min, ray.dir));
	normal = get_normal(hit_point, object);
	if (dot(ray.dir, normal) > 0)
		normal = vec_inv(normal);
	cur_light = scene->lights;
	while (cur_light != NULL)
	{
		addition = light_contribution(*(t_light *)(cur_light->content),
					init_surf(hit_point, normal, object, ray),
					*scene);
		color = colrgb_add(color, addition);
		cur_light = cur_light->next;
	}
	return (color);
}
