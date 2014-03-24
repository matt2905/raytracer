/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hyperboloid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 18:37:02 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/23 16:52:18 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_rt.h"

static t_obj	ft_find_coef(t_object obj, t_vector dir, t_vec v)
{
	t_obj		h;
	double		alpha;
	double		beta;

	obj.misc = M_PI * obj.misc / 180.0;
	alpha = ft_vector_dot(dir, obj.axe);
	beta = ft_vector_dot(v.d, obj.axe);
	h.a = pow(cos(obj.misc), 2) * ft_vector_dot(v.b, v.b);
	h.a -= pow(sin(obj.misc), 2) * pow(alpha, 2);
	h.b = (pow(cos(obj.misc), 2) * ft_vector_dot(v.e, v.b));
	h.b -= (pow(sin(obj.misc), 2) * alpha * beta);
	h.c = pow(cos(obj.misc), 2) * ft_vector_dot(v.e, v.e);
	h.c -= pow(sin(obj.misc), 2) * pow(beta, 2) + obj.hyp;
	return (h);
}

double			ft_hyperboloid(t_object obj, t_vector dir, t_vector o)
{
	t_obj		h;
	t_vec		v;

	obj.axe = ft_vector_normalize(obj.axe);
	v.a = ft_vector_mult(obj.axe, ft_vector_dot(dir, obj.axe));
	v.b = ft_vector_sub(v.a, dir);
	v.d = ft_vector_sub(obj.pos, o);
	v.g = ft_vector_mult(obj.axe, ft_vector_dot(v.d, obj.axe));
	v.e = ft_vector_sub(v.g, v.d);
	h = ft_find_coef(obj, dir, v);
	if ((h.delta = pow(h.b, 2) - h.a * h.c) >= 0)
	{
		h.alpha1 = (-h.b - sqrt(h.delta)) / h.a;
		h.alpha2 = (-h.b + sqrt(h.delta)) / h.a;
		if (h.alpha1 > 0.0 && h.alpha1 < HUGE_VAL)
		{
			if (h.alpha1 < h.alpha2 || h.alpha2 < 0.0)
				return (h.alpha1);
		}
		if (h.alpha2 > 0.0 && h.alpha2 < HUGE_VAL)
			return (h.alpha2);
	}
	return (HUGE_VAL);
}
