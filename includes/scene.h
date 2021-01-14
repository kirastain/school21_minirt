/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:08:27 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 11:19:03 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "linalg.h"
# include "color.h"

typedef struct	s_object
{
	void		*obj;
	int			type;
	t_colrgb	color;
	double		albedo;
}				t_object;

typedef struct	s_ray
{
	t_double3	o;
	t_double3	dir;
}				t_ray;

typedef struct	s_camera
{
	t_double3	pos;
	t_double3	dir;
	t_double3	dir_y;
	t_double3	dir_x;
	int			fov;
}				t_camera;

typedef struct	s_light
{
	t_double3	pos;
	double		bright;
	t_colrgb	color;
}				t_light;

typedef struct	s_surf
{
	t_double3	hit_point;
	t_double3	normal;
	t_list		*objects;
	t_object	*object;
	t_ray		ray;
}				t_surf;

typedef struct	s_scene
{
	t_list		*objects;
	t_list		*lights;
	int			width;
	int			height;
	double		ambient;
	t_colrgb	ambient_color;
	t_list		*cameras;
	int			selected_camera;
}				t_scene;

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_scene		*scene;
	int			cam_num;
	t_object	*chosen_object;
}				t_vars;

#endif
