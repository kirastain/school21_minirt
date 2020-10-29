/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:28:48 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/29 22:29:13 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

# include "linalg.h"
# include "scene.h"
# include "color.h"
# include "image.h"

typedef struct	s_sphere
{
	t_double3	center;
	double		radius;
}				t_sphere;

typedef struct	s_plane
{
	t_double3	center;
	t_double3	normal;
}				t_plane;

typedef struct	s_square
{
	t_double3	center;
	t_double3	normal;
	double		side;
}				t_square;

typedef struct	s_cylinder
{
	t_double3	center;
	t_double3	normal;
	double		diameter;
	double		height;
}				t_cylinder;

typedef struct	s_triangle
{
	t_double3	a;
	t_double3	b;
	t_double3	c;
}				t_triangle;

t_double3		get_normal(t_double3 p, t_object *object);
t_double3		sphere_normal(t_double3 point, t_sphere sphere);
t_double3		plane_normal(t_plane plane);
t_double3		triangle_normal(t_triangle triangle);
t_double3		square_normal(t_square square);
t_double3		cylinder_normal(t_double3 point, t_cylinder cylinder);

#endif
