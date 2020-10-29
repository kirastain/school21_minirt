/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 14:31:23 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/29 21:34:27 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

int	handle_mouse(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == 1)
	{
		printf("mouse pressed in %d %d\n", x, y);
		select_object(vars, gen_ray(x, y, vars->scene));
	}
	if (keycode == 2)
		printf("mouse released\n");
	return (0);
}

int		rerender(int key, t_vars *vars)
{
	if (key == 124)
		vars->cam_num += 1;
	else if (key == 123)
		vars->cam_num -= 1;
	else if (key == 8)
		select_camera(vars);
	else if (key == 37)
		select_light(vars);
	else if (key == W || key == A || key == S || key == D || key == Z || key == X || key == R || key == F ||
					key == T || key == Y || key == G || key == H || key == B || key == N)
		transform_main(key, vars);
	else if (key == 53)
		exit(0);
	drawing_image(vars, vars->cam_num, 0);
	return (0);
}

int	key_close(int keycode, t_vars *vars)
{
    if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == 0)
		printf("here liea the next camera to the ledt\n");
	else if (keycode == 2)
		printf("hete lies right camera\n");
	return (0);
}

int	mouse_press(int button, int x, int y, void *param)
{
	(void)param;
	printf("`%d %d %d\n", button, x, y);
	return (0);
}

int	close_app(void *param)
{
    (void)param;
    exit(0);
}