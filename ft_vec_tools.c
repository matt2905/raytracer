/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 13:45:39 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/14 10:54:05 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_rt.h"

t_vector	ft_vector_intercept(t_vector v, t_vector o, double alpha)
{
	t_vector	new;

	new.x = v.x * alpha + o.x;
	new.y = v.y * alpha + o.y;
	new.z = v.z * alpha + o.z;
	return (new);
}

double		ft_find_alpha(t_vector v, t_vector o, t_vector inter)
{
	double		alpha;
	t_vector	sub;

	(void)v;
	sub = ft_vector_sub(o, inter);
	sub = ft_vector_normalize(sub);
	alpha = sqrt(ft_vector_dot(sub, sub));
	return (alpha);
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
