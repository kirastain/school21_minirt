/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 14:31:23 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 18:16:03 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

int	handle_mouse(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == 1)
	{
		select_object(vars, gen_ray(x, y, vars->scene));
	}
	return (0);
}

int	rerender(int key, t_vars *vars)
{
	if (key == 124)
		vars->cam_num += 1;
	else if (key == 123)
		vars->cam_num -= 1;
	else if (key == 8)
		select_camera(vars);
	else if (key == 37)
		select_light(vars);
	else if (key == W || key == A || key == S || key == D || key == Z ||
			key == X || key == R || key == F ||
			key == T || key == Y || key == G ||
			key == H || key == B || key == N)
		transform_main(key, vars);
	else if (key == 53)
		close_window(vars);
	drawing_image(vars, vars->cam_num, 0);
	return (0);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_scene(vars);
	exit(0);
}
