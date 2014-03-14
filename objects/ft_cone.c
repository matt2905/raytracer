/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:05:00 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/14 17:32:38 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_rt.h"

t_obj		ft_find_coef(t_object obj, t_vector dir, t_vec v)
{
	t_obj		c;
	double		alpha;
	double		beta;

	obj.misc = M_PI * obj.misc / 180.0;
	alpha = ft_vector_dot(dir, obj.axe);
	beta = ft_vector_dot(v.d, obj.axe);
	c.a = pow(cos(obj.misc), 2) * ft_vector_dot(v.b, v.b);
	c.a = c.a - pow(sin(obj.misc), 2) * pow(alpha, 2);
	c.b = 2 * (pow(cos(obj.misc), 2) * ft_vector_dot(v.e, v.b));
	c.b = c.b - 2 * (pow(sin(obj.misc), 2) * alpha * beta);
	c.c = pow(cos(obj.misc), 2) * ft_vector_dot(v.e, v.e);
	c.c = c.c - pow(sin(obj.misc), 2) * pow(beta, 2);
	return (c);
}

double		ft_cone(t_object obj, t_vector dir, t_vector o)
{
	t_obj		c;
	t_vec		v;

	obj.axe = ft_vector_normalize(obj.axe);
	v.a = ft_vector_mult(obj.axe, ft_vector_dot(dir, obj.axe));
	v.b = ft_vector_sub(v.a, dir);
	v.d = ft_vector_sub(obj.pos, o);
	v.g = ft_vector_mult(obj.axe, ft_vector_dot(v.d, obj.axe));
	v.e = ft_vector_sub(v.g, v.d);
	c = ft_find_coef(obj, dir, v);
	if ((c.delta = pow(c.b, 2) - 4 * c.a * c.c) >= 0)
	{
		c.alpha1 = (-c.b - sqrt(c.delta)) / (2.0 * c.a);
		c.alpha2 = (-c.b + sqrt(c.delta)) / (2.0 * c.a);
		if (c.alpha1 > 0.02 && c.alpha1 < HUGE_VAL)
		{
			if (c.alpha1 < c.alpha2 || c.alpha2 < 0.0)
				return (c.alpha1);
		}
		if (c.alpha2 > 0.02 && c.alpha2 < HUGE_VAL)
			return (c.alpha2);
	}
	return (HUGE_VAL);
}

t_vector	ft_get_normal_cone(t_object obj, t_vector inter)
{
	t_vector	sub;
	t_vector	normal;
	t_vector	tmp;
	double		hypotenuse;
	double		d;

	sub = ft_vector_sub(obj.pos, inter);
	hypotenuse = sqrt(ft_vector_dot(sub, sub));
	d = hypotenuse * cos(M_PI * obj.misc / 180.0);
	tmp = ft_vector_mult(obj.axe, d);
	normal = ft_vector_sub(inter, tmp);
	return (normal);
}
