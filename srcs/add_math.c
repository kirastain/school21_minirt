/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelen <bbelen@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:35:47 by bbelen            #+#    #+#             */
/*   Updated: 2020/09/12 15:38:44 by bbelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minirt.h"

t_float3	vec_normalize(t_float3 vec)
{
	float	len;

	len = sqrtf(vec.x * vec.x + vec.y * vec.y * vec.z * vec.z);
	vec.x = vec.x / len;
	vec.y = vec.y / len;
	vec.z = vec.z / len;
	return (vec);
}
