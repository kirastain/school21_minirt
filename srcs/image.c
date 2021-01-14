/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:01:19 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 17:53:27 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minirt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_pixel	**create_buffer(int height, int width)
{
	t_pixel	**result;
	int		i;

	i = 0;
	result = malloc(sizeof(t_pixel *) * height);
	while (i < height)
	{
		result[i] = malloc(sizeof(t_pixel) * width);
		i++;
	}
	return (result);
}

void	free_buffer(t_pixel **buffer, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}

t_pixel	pix_from_int(int color)
{
	t_colrgb	tc;
	t_pixel		result;

	tc = int_to_color(color);
	result.b = tc.blue;
	result.g = tc.green;
	result.r = tc.red;
	return (result);
}
