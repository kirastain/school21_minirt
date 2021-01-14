/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:14:22 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 18:21:41 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

static int	open_file(char *file, t_vars *vars)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (checking_flags(fd, vars) == -1)
		exit(0);
	close(fd);
	return (0);
}

int			raystart(t_vars *vars, int save)
{
	int		x;
	int		y;
	t_pixel	**buff;
	int		color;

	y = 0;
	buff = create_buffer(vars->scene->height, vars->scene->width);
	while (y < vars->scene->height)
	{
		x = 0;
		while (x < vars->scene->width)
		{
			color = trace_ray(vars->scene, gen_ray(x, y, vars->scene));
			if (save)
				buff[y][x] = pix_from_int(color);
			else
				my_mlx_pixel_put(&(vars->img), x, y, color);
			x++;
		}
		y++;
	}
	if (save)
		write_bmp("file.bmp", vars->scene->width, vars->scene->height, buff);
	free_buffer(buff, vars->scene->height);
	return (0);
}

int			drawing_image(t_vars *vars, int cam_num, int save)
{
	int		cameras;

	cameras = ft_lstsize(vars->scene->cameras);
	vars->scene->selected_camera = cam_num % cameras;
	raystart(vars, save);
	if (save == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

void		do_rt(char *file, int save)
{
	t_vars	vars;

	init_scene(&vars);
	open_file(file, &vars);
	vars.cam_num = 0;
	if (save == 1)
	{
		drawing_image(&vars, 0, 1);
		return ;
	}
	vars.win = mlx_new_window(vars.mlx, vars.scene->width,
				vars.scene->height, "minirt");
	vars.img.img = mlx_new_image(vars.mlx, vars.scene->width,
				vars.scene->height);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
				&vars.img.line_length, &vars.img.endian);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_hook(vars.win, 4, 0, handle_mouse, &vars);
	mlx_key_hook(vars.win, rerender, &vars);
	drawing_image(&vars, 0, 0);
	mlx_loop(vars.mlx);
}

int			main(int argc, char **argv)
{
	t_vars	vars;

	if (argc < 2 || argc > 3)
		return (-1);
	else
	{
		if (argc == 2)
		{
			do_rt(argv[1], 0);
		}
		else if (ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) == 0)
			do_rt(argv[1], 1);
	}
	return (0);
}
