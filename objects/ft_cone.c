/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:05:00 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/18 20:39:12 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_rt.h"

static t_obj	ft_find_coef(t_object obj, t_vector dir, t_vec v)
{
	t_obj		c;
	double		alpha;
	double		beta;
	double		b;
	double		a;

	obj.misc = M_PI * obj.misc / 180.0;
	a = pow(cos(obj.misc), 2);
	b = pow(sin(obj.misc), 2);
	alpha = ft_vector_dot(dir, obj.axe);
	beta = ft_vector_dot(v.d, obj.axe);
	c.a = a * ft_vector_dot(v.b, v.b) - b * pow(alpha, 2);
	c.b = 2 * (a * ft_vector_dot(v.e, v.b)) - 2 * (b * alpha * beta);
	c.c = a * ft_vector_dot(v.e, v.e) - b * pow(beta, 2);
	return (c);
}

double			ft_cone(t_object obj, t_vector dir, t_vector o)
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
		if (c.alpha1 > 0.0 && c.alpha1 < HUGE_VAL)
		{
			if (c.alpha1 < c.alpha2 || c.alpha2 < 0.0)
				return (c.alpha1);
		}
		if (c.alpha2 > 0.0 && c.alpha2 < HUGE_VAL)
			return (c.alpha2);
	}
	return (HUGE_VAL);
}

t_vector		ft_get_normal_cone(t_object obj, t_vector inter)
{
	t_vector	normal;
	t_vector	sub;
	t_vector	tangente;
	double		dot;

	sub = ft_vector_sub(obj.pos, inter);
	sub = ft_vector_normalize(sub);
	obj.axe = ft_vector_normalize(obj.axe);
	if ((dot = ft_vector_dot(sub, obj.axe)) > 0.0)
		tangente = ft_vector_wedge(obj.axe, sub);
	else
		tangente = ft_vector_wedge(sub, obj.axe);
	tangente = ft_vector_normalize(tangente);
	normal = ft_vector_wedge(sub, tangente);
	return (normal);
}
