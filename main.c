/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen@student.21-school.ru <bbelen>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:14:22 by bbelen            #+#    #+#             */
/*   Updated: 2020/09/23 15:01:29 by bbelen@stud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"
#include <stdio.h>

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

static int	open_file(char *file, t_vars *vars)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (checking_flags(fd, vars) == -1)
		exit(0);
	close(fd);
	return (0);
}

int	drawing_image(t_vars *vars, t_data  *img)
{
	int 	x = 0;
	int 	y = 0;
	t_ray	ray;
	t_camera	*cam;

	cam = init_camera();
	cam = vars->cameras->content;
	printf("scene list size = %d\n", ft_lstsize(vars->scene));
	printf("lights list size = %d\n", ft_lstsize(vars->lights));
	printf("cameras list size = %d\n", ft_lstsize(vars->cameras));
    img->img = mlx_new_image(vars->mlx, 1280, 720);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	printf("cam pos in main is %f\n", cam->pos.x);
	printf("cam pos in main is %f\n", cam->pos.y);
	printf("cam pos in main is %f\n", cam->pos.z);

	while (y < vars->res_y)
	{
		while (x < vars->res_x)
		{
			//printf("cam pos in main is %f\n", cam->pos.x);
			ray = gen_ray(vars->res_x, vars->res_y, x, vars->res_y - y, cam);
			//printf("ray generated\n");
			//printf("%f\n", ray.o.x);
			trace_ray(&ray, vars, img, x, y);
			//my_mlx_pixel_put(img, x, y, 0xcc99ffe6);
			x++;
		}
		x = 0;
		y++;
	}

    mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
    t_data  img;
	t_vars	vars;

	init_scene(&vars);

	if(argc == 2)
	{
		open_file(argv[1], &vars);

		vars.win = mlx_new_window(vars.mlx, 1280, 720, "Hello world!");
    	img.img = mlx_new_image(vars.mlx, 1280, 720);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		printf("Res is %ix%i\n", vars.res_x, vars.res_y);
		drawing_image(&vars, &img);
	
	/*int b = 0;
	int g = 0;
	while (g < 1280)
	{
		while (b < 720)
		{
			if ((g / 40) % 2 == 0 && (b / 40) % 2 == 0)
				my_mlx_pixel_put(&img, g, b, 0xcc99ffe6);
			else
			{
				my_mlx_pixel_put(&img, g, b, 0xaac2efef);
			}
			
			b++;
		}
		b = 0;
		g++;
	}*/

    	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
		mlx_hook(vars.win, 2, 1L<<0, key_close, &vars);
		mlx_hook(vars.win, 4, 1L<<0, mouse_press, &vars);
		mlx_hook(vars.win, 17, 1L<<0, close_app, &vars);
    	mlx_loop(vars.mlx);
	}
	else
	{
		exit(-1);
	}
	return (0);
}
