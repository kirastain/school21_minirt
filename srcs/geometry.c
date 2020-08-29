/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 14:50:55 by bbelen            #+#    #+#             */
/*   Updated: 2020/08/20 15:22:24 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_float3
{
	float	x;
	float	y;
	float	z;
}				t_float3;

typedef struct	s_camera
{
	t_float3	pos;
	t_float3	view; //[-1,1]
	int			angle; //[0, 180]
}				t_camera;

typedef struct	s_light
{
	t_float3	pos;
	float		bright; //[0, 1]
	t_float3	color;
}				t_light;

typedef struct	s_sphere
{
	t_float3	radius;
	float		center;
	t_float3	color;
}				t_sphere;

typedef struct	s_plane
{
	t_float3	center;
	t_float3	normal; //[-1,1]
	t_float3	color;
}				t_plane;

typedef struct	s_square
{
	t_float3	center;
	t_float3	normal;
	float		side;
	t_float3	color;
}				t_square;

typedef struct	s_cylinder
{
	t_float3	center;
	t_float3	normal;
	float		diameter;
	float		height;
	t_float3	color;
}				t_cylinder;

typedef struct s_triangle
{
	t_float3	a;
	t_float3	b;
	t_float3	c;
	t_float3	color;
}				t_triangle;
