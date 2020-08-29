/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 14:31:23 by bbelen            #+#    #+#             */
/*   Updated: 2020/08/20 16:28:48 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minirt.h"
#include <stdio.h>

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