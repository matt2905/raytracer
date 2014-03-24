/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:05:21 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/23 16:44:49 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_rt.h"

double			ft_cylinder(t_object obj, t_vector dir, t_vector o)
{
	t_obj		c;
	t_vec		v;

	obj.axe = ft_vector_normalize(obj.axe);
	v.a = ft_vector_mult(obj.axe, ft_vector_dot(dir, obj.axe));
	v.b = ft_vector_sub(v.a, dir);
	v.d = ft_vector_sub(obj.pos, o);
	v.g = ft_vector_mult(obj.axe, ft_vector_dot(v.d, obj.axe));
	v.e = ft_vector_sub(v.g, v.d);
	c.a = ft_vector_dot(v.b, v.b);
	c.b = (ft_vector_dot(v.e, v.b));
	c.c = ft_vector_dot(v.e, v.e) - pow(obj.misc, 2);
	if ((c.delta = pow(c.b, 2) - c.a * c.c) >= 0)
	{
		c.alpha1 = (-c.b - sqrt(c.delta)) / c.a;
		c.alpha2 = (-c.b + sqrt(c.delta)) / c.a;
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

t_vector		ft_get_normal_cylinder(t_object obj, t_vector inter)
{
	t_vector	tmp;
	t_vector	sub;

	sub = ft_vector_sub(obj.pos, inter);
	obj.axe = ft_vector_normalize(obj.axe);
	tmp = ft_vector_sub(ft_vector_project(sub, obj.axe), sub);
	return (ft_vector_neg(tmp));
}
