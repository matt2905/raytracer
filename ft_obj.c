/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 14:25:19 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/16 18:30:24 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_rtv1.h"

double		ft_sphere(t_object obj, t_vector dir, t_vector o)
{
	t_vector	tmp;
	t_sphere	s;

	tmp = ft_vector_sub(obj.pos, o);
	s.a = ft_vector_dot(dir, dir);
	s.b = 2 * ft_vector_dot(dir, tmp);
	s.c = ft_vector_dot(tmp, tmp) - pow(obj.misc, 2);
	if ((s.delta = pow(s.b, 2) - 4 * s.a * s.c) >= 0)
	{
		s.alpha1 = (-s.b - sqrt(s.delta)) / (2.0 * s.a);
		s.alpha2 = (-s.b + sqrt(s.delta)) / (2.0 * s.a);
		if (s.alpha1 > 0.02 && s.alpha1 < HUGE_VAL)
		{
			if (s.alpha1 < s.alpha2 || s.alpha2 < 0.0)
				return (s.alpha1);
			if (s.alpha2 > 0.02 && s.alpha2 < HUGE_VAL)
				return (s.alpha2);
		}
		if (s.alpha2 > 0.02 && s.alpha2 < HUGE_VAL)
			return (s.alpha2);
	}
	return (HUGE_VAL);
}

double		ft_plane(t_object obj, t_vector dir, t_vector o)
{
	double		a;
	double		b;
	double		alpha;

	a = ft_vector_dot(obj.axe, dir);
	if (a == 0)
		return (HUGE_VAL);
	else
	{
		b = ft_vector_dot(obj.axe, o) + obj.misc;
		alpha = -b / a;
		if (alpha > 0.02 && alpha < HUGE_VAL)
			return (alpha);
		else
			return (HUGE_VAL);
	}
}

double		ft_cylinder(t_object obj, t_vector dir, t_vector o)
{
	(void)obj;
	(void)dir;
	(void)o;
	return (0.0);
}

double		ft_cone(t_object obj, t_vector dir, t_vector o)
{
	(void)obj;
	(void)dir;
	(void)o;
	return (0.0);
}
