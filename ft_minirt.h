/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minirt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:17:26 by bbelen            #+#    #+#             */
/*   Updated: 2020/09/12 15:41:07 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINIRT_H
# define FT_MINIRT_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# include <math.h>

typedef struct	s_float3
{
	float		x;
	float		y;
	float		z;
}				t_float3;

typedef struct	s_int3
{
	int			x;
	int			y;
	int			z;
}				t_int3;

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
	int			res_x;
	int			res_y;
	float		ambience;
	int			amb_color;
	t_list		*scene;
	t_list		*cameras;
	t_list		*lights;
}				t_vars;

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_ray
{
	t_float3	o;
	t_float3	dir;
}				t_ray;


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
	int			color;
}				t_light;

typedef struct	s_sphere
{
	t_float3	center;
	float		radius;
	int			color;
}				t_sphere;

typedef struct	s_plane
{
	t_float3	center;
	t_float3	normal; //[-1,1]
	int			color;
}				t_plane;

typedef struct	s_square
{
	t_float3	center;
	t_float3	normal;
	float		side;
	int			color;
}				t_square;

typedef struct	s_cylinder
{
	t_float3	center;
	t_float3	normal;
	float		diameter;
	float		height;
	int			color;
}				t_cylinder;

typedef struct	s_triangle
{
	t_float3	a;
	t_float3	b;
	t_float3	c;
	int			color;
}				t_triangle;

int				create_trgb(int t, int r, int g, int b);
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);
int				get_opposite(int trgb);
int				add_shade(double distance, int trgb);
int				key_close(int keycode, t_vars *vars);
int				mouse_press(int button, int x, int y, void *param);
int				close_app(void *param);
int				checking_flags(int fd, t_vars *vars);

int				create_res(char **line, t_vars *vars);
int				create_amb(char **line, t_vars *vars);
int				create_camera(char **line, t_vars *vars);
int				create_light(char **line, t_vars *vars);

int				create_plane(char **line, t_vars *vars);
int				create_sphere(char **line, t_vars *vars);
int				create_square(char **line, t_vars *vars);
int				create_cylinder(char **line, t_vars *vars);
int				create_triangle(char **line, t_vars *vars);

int				strarr_len(char **line);
t_int3			get_int3_color(char *line);
t_float3		get_float3(char *line);
t_float3		get_float3_normal(char *line);

t_ray			gen_ray(int w, int h, int x, int y, t_camera *cam);
t_float3		vec_normalize(t_float3 vec);

#endif
