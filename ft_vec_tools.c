/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 13:45:39 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/16 13:23:29 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_rtv1.h"

t_vector	ft_vector_intercept(t_vector v, t_vector o, double alpha)
{
	t_vector	new;

	new.x = v.x * alpha + o.x;
	new.y = v.y * alpha + o.y;
	new.z = v.z * alpha + o.z;
	return (new);
}

t_vector	ft_vector_normalize(t_vector v)
{
	double		norme;
	t_vector	z;

	z.x = 0;
	z.y = 0;
	z.z = 0;
	norme = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	if (norme)
	{
		v.x /= norme;
		v.y /= norme;
		v.z /= norme;
		return (v);
	}
	else
		return (z);
}

t_vector	ft_vector_neg(t_vector v)
{
	t_vector	new;

	new.x = -v.x;
	new.y = -v.y;
	new.z = -v.z;
	return (new);
}

t_vector	ft_vector_copy(t_vector v)
{
	t_vector	new;

	new.x = v.x;
	new.y = v.y;
	new.z = v.z;
	return (new);
}
