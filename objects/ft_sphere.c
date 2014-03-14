/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:02:38 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/08 18:15:23 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_rt.h"

double		ft_sphere(t_object obj, t_vector dir, t_vector o)
{
	t_vector	tmp;
	t_obj		s;

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
