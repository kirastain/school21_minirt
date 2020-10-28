/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:14:22 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/28 20:39:23 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"
#include <stdio.h>

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int		close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

static int	open_file(char *file, t_vars *vars)
{
	int	fd;

	fd = open(file, O_RDONLY);
	printf("opening checking flags\n");
	if (checking_flags(fd, vars) == -1)
		exit(0);
	close(fd);
	return (0);
}

int	raystart(t_vars *vars, int save)
{
	int 	x;
	int 	y;
	t_pixel	**buff;
	int	color;

	y = 0;
	buff = create_buffer(vars->res_y, vars->res_x);
	printf("raystart begin\n");
	while (y < vars->res_y)
	{
		x = 0;
		while (x < vars->res_x)
		{
			color = trace_ray(vars->scene, gen_ray(x, y, vars->scene));
			if (save)
				buff[y][x] = pix_from_int(color);
			else
				my_mlx_pixel_put(&(vars->img), x, y, color);
				//vars->img.addr[y * vars->scene->width + x] = color;
			x++;
		}
		y++;
	}
	if (save)
		write_bmp("file.bmp", vars->res_x, vars->res_y, buff);
	free_buffer(buff, vars->res_y);
	return (0);
}

int	drawing_image(t_vars *vars, int cam_num, int save)
{
	int		cameras;

	cameras = ft_lstsize(vars->scene->cameras);
	vars->scene->selected_camera = cam_num % cameras;
	printf("Drawing image goes into raystart\n");
	raystart(vars, save);
	if (save == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}
int		rerender(int key, t_vars *vars)
{
	if (key == 124)
		vars->cam_num += 1;
	else if (key == 123)
		vars->cam_num -= 1;
	else if (key == 53)
		exit(0);
	drawing_image(vars, vars->cam_num, 0);
	return (0);
}

void	do_rt(char *file, int save)
{
	t_vars	vars;

	init_scene(&vars);
	open_file(file, &vars);
	vars.cam_num = 0;
	printf("validation done\n");
	if (save == 1)
	{
		drawing_image(&vars, 0, 1);
		return ;
	}
	vars.win = mlx_new_window(vars.mlx, vars.res_x, vars.res_y, "minirt");
	vars.img.img = mlx_new_image(vars.mlx, vars.res_x, vars.res_y);

	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	printf("Res is %ix%i\n", vars.res_x, vars.res_y);
 
 	//mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	//mlx_hook(vars.win, 2, 1L<<0, key_close, &vars);
	//mlx_hook(vars.win, 4, 1L<<0, mouse_press, &vars);
	//mlx_hook(vars.win, 17, 1L<<0, close_app, &vars);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_key_hook(vars.win, rerender, &vars);
	drawing_image(&vars, 0, 0);
	mlx_loop(vars.mlx);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc < 2 || argc > 3)
		return (-1);
	else
	{
		if  (argc == 2)
		{
			do_rt(argv[1], 0);
		}
		else if (ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) == 0)
			do_rt(argv[1], 1);
	}
	return (0);
}
