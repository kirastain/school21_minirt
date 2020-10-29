/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:56:57 by bbelen            #+#    #+#             */
/*   Updated: 2020/10/29 22:30:43 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# define PIXEL_DATA_OFFSET	54
# define HEADER_SIZE		40
# define PLANES				1
# define BITS_PER_PIXEL		24

typedef struct		s_pixel
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
}					t_pixel;

int					write_bmp(char *filename, unsigned int width,
							unsigned int height, t_pixel **pixels);
t_pixel				**create_buffer(int height, int width);
void				free_buffer(t_pixel **buffer, int height);
t_pixel				pix_from_int(int color);

#endif
