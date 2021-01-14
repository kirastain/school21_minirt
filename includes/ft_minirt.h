/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minirt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:17:26 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 18:40:41 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINIRT_H
# define FT_MINIRT_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include "scene.h"
# include "linalg.h"
# include "geometry.h"
# include "color.h"
# include "image.h"

# define MAX_DIST	1000000000.0f
# define MIN_DIST	0.000001f
# define T_SPHERE	1
# define T_SQUARE	2
# define T_PLANE	3
# define T_CYLINDER	4
# define T_TRIANGLE	5
# define T_CAMERA	6
# define T_LIGHT	7
# define WIDTH 		1280
# define HEIGHT		720
# define W			13
# define A			0
# define S			1
# define D			2
# define Z			6
# define X			7
# define R			15
# define F			3
# define T			17
# define Y			16
# define G			5
# define H			4
# define B			11
# define N			45
# define ROTATE		0.0872665

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

int				key_close(int keycode, t_vars *vars);
int				mouse_press(int button, int x, int y, void *param);
int				close_app(void *param);
int				rerender(int key, t_vars *vars);
int				close_window(t_vars *vars);

int				drawing_image(t_vars *vars, int cam_num, int save);

void			select_object(t_vars *vars, t_ray ray);
void			select_camera(t_vars *vars);
void			select_light(t_vars	*vars);

int				checking_flags(int fd, t_vars *vars);
void			error_quit(char *str);

int				init_scene(t_vars *vars);
t_camera		*init_camera(void);
t_light			*init_light(void);
t_plane			*init_plane(void);
t_sphere		*init_sphere(void);
t_triangle		*init_triangle(void);
t_square		*init_square(void);
t_cylinder		*init_cylinder(void);
t_surf			init_surf(t_double3 hit_point, t_double3 normal,
					t_object *object, t_ray ray);

void			create_res(char **line, t_vars *vars);
void			create_amb(char **line, t_vars *vars);
void			create_camera(char **line, t_vars *vars);
t_matrix		look_at(t_camera camera);
void			create_light(char **line, t_vars *vars);

t_object		*create_object(t_colrgb color, int type, void *geom);
void			create_plane(char **line, t_vars *vars);
void			create_sphere(char **line, t_vars *vars);
void			create_square(char **line, t_vars *vars);
void			get_sq_points(t_square *sq);
void			create_cylinder(char **line, t_vars *vars);
void			create_triangle(char **line, t_vars *vars);

int				strarr_len(char **line);

t_camera		pick_camera(t_scene *scene);
t_double3		get_direction(int x, int y, t_scene *scene, t_camera camera);
t_ray			gen_ray(int x, int y, t_scene *scene);
t_ray			create_ray(t_double3 o, t_double3 dir);
int				trace_ray(t_scene *scene, t_ray rays);
t_ray			ray_to_pixel(int x, int y, t_scene *sene);

int				check_edges(t_triangle triangle, t_double3 p, t_double3 n);

int				intersects(t_object *obj, double *t, t_ray ray);
int				intersect_main(t_list *objects, t_ray ray,
					t_object **object, double *t_min);
int				intersect_main_shadow(t_list *objects, t_ray ray,
					t_object **object, double *t_min);
int				intersects_plane(t_object *obj, double *t, t_ray ray);
int				intersects_sphere(t_object *obj, double *t, t_ray ray);
int				intersects_square(t_ray ray, t_square *sq, double *t);
int				intersects_cylinder(t_ray ray, t_cylinder *cylinder, double *t);
int				intersects_triangle(t_triangle *tr, double *t, t_ray ray);

t_colrgb		shade(t_scene *scene, t_ray ray, t_object *object,
					double t_min);
double			spec_coeff(t_light light, t_surf surf);
t_colrgb		specular(t_light light, t_surf surf);
t_colrgb		mix_colors(t_light light, double coeff, t_surf surf);
t_colrgb		light_contribution(t_light light, t_surf surf, t_scene scene);

int				solve_quadratic(t_qparams params, double *x0, double *x1);
int				cyl_get_roots(double *t0, double *t1, t_cylinder cy,
					t_ray ray);
void			check_t(double *t, t_cylinder cylinder, t_ray ray);

int				write_bmp(char *filename, unsigned int width,
					unsigned int height, t_pixel **pixels);

int				handle_mouse(int keycode, int x, int y, t_vars *vars);
void			transform_main(int key, t_vars *vars);
void			translate_object(t_object *object, int key);
void			rotate_object(t_object *object, int key);
void			resize_object(t_object *object, int key);
void			translate_plane(t_plane *pl, int key);
void			translate_sphere(t_sphere *sp, int key);
void			translate_square(t_square *sq, int key);
void			translate_square_2(t_square *sq, int key);
void			translate_square_3(t_square *sq, int key);
void			translate_cylinder(t_cylinder *cy, int key);
void			translate_triangle(t_triangle *tr, int key);
void			translate_triangle_2(t_triangle *tr, int key);
void			translate_camera(t_camera *cam, int key);
void			translate_light(t_list *place, int key);

void			resize_plane(t_plane *pl, int key);
void			resize_sphere(t_sphere *sp, int key);
void			resize_square(t_square *sq, int key);
void			resize_cylinder(t_cylinder *cy, int key);
double			triangle_square_check(t_triangle *tr);
void			resize_triangle(t_triangle *tr, int key);
void			resize_triangle_add(t_double3 *p, t_double3 center, int key);

void			rotate_plane(t_plane *pl, int key);
void			rotate_square(t_square *sq, int key);
void			work_with_abcd(t_rot_matrix m, t_square *sq, int key);
void			rotate_cylinder(t_cylinder *cy, int key);
void			rotate_camera(t_camera *cam, int key);
void			rotate_triangle(t_triangle *tr, int key);

t_rot_matrix	get_rot_m(int key, double degree);
t_rot_matrix	get_x_m(float degree);
t_rot_matrix	get_y_m(float degree);
t_rot_matrix	get_z_m(float degree);

void			free_scene(t_vars *vars);
void			free_t_scene(t_scene *scene);

#endif
