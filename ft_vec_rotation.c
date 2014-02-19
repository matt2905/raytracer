/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 18:28:51 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/15 18:46:31 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_rtv1.h"

t_vector		ft_vector_rotation_x(t_vector v, int alpha)
{
	t_vector	new;

	alpha %= 360;
	if (alpha < 0)
		alpha += 360;
	new.x = v.x;
	new.y = v.y * cos(alpha) - v.z * sin(alpha);
	new.z = v.y * sin(alpha) + v.z * cos(alpha);
	return (new);
}

t_vector		ft_vector_rotation_y(t_vector v, int alpha)
{
	t_vector	new;

	alpha %= 360;
	if (alpha < 0)
		alpha += 360;
	new.y = v.y;
	new.x = v.x * cos(alpha) - v.z * sin(alpha);
	new.z = v.x * sin(alpha) + v.z * cos(alpha);
	return (new);
}

t_vector		ft_vector_rotation_z(t_vector v, int alpha)
{
	t_vector	new;

	alpha %= 360;
	if (alpha < 0)
		alpha += 360;
	new.z = v.z;
	new.x = v.x * cos(alpha) - v.y * sin(alpha);
	new.y = v.x * sin(alpha) + v.y * cos(alpha);
	return (new);
}
