/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:08:27 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/30 11:15:41 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "linalg.h"
# include "scene.h"
# include "image.h"

typedef struct		s_colrgb
{
	float			red;
	float			green;
	float			blue;
}					t_colrgb;

typedef union		u_int_color
{
	int				integer;
	unsigned char	comps[4];
}					t_int_color;

t_colrgb			init_color(float r, float g, float b);
t_colrgb			get_colrgb(int red, int green, int blue);

t_colrgb			int_to_color(int color);
int					color_to_int(t_int3 color);
int					to_int(t_colrgb a);

t_int3				get_int3_color(char *line);

t_colrgb			colrgb_amb(t_colrgb col, float coeff);
t_colrgb			colrgb_add(t_colrgb col, t_colrgb col_2);
t_colrgb			colrgb_mult(t_colrgb col, t_colrgb col_2);

#endif
