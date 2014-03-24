/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 18:28:51 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/03 14:11:43 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_rt.h"

t_vector		ft_vector_rotation_x(t_vector v, double alpha)
{
	t_vector	new;
	double		angle;

	alpha = fmod(alpha, 360.0);
	if (alpha < 0.0)
		alpha += 360.0;
	angle = (M_PI * alpha / 180.0);
	new.x = v.x;
	new.y = v.y * cos(angle) - v.z * sin(angle);
	new.z = v.y * sin(angle) + v.z * cos(angle);
	return (new);
}

t_vector		ft_vector_rotation_y(t_vector v, double alpha)
{
	t_vector	new;
	double		angle;

	alpha = fmod(alpha, 360.0);
	if (alpha < 0.0)
		alpha += 360.0;
	angle = (M_PI * alpha / 180.0);
	new.x = v.x * cos(angle) + v.z * sin(angle);
	new.y = v.y;
	new.z = -(v.x * sin(angle)) + v.z * cos(angle);
	return (new);
}

t_vector		ft_vector_rotation_z(t_vector v, double alpha)
{
	t_vector	new;
	double		angle;

	alpha = fmod(alpha, 360.0);
	if (alpha < 0.0)
		alpha += 360.0;
	angle = (M_PI * alpha / 180.0);
	new.x = v.x * cos(angle) - v.y * sin(angle);
	new.y = v.x * sin(angle) + v.y * cos(angle);
	new.z = v.z;
	return (new);
}
