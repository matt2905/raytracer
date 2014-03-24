/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:03:25 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/17 18:29:12 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_rt.h"

double		ft_plane(t_object obj, t_vector dir, t_vector o)
{
	double		a;
	double		b;
	double		alpha;

	obj.axe = ft_vector_normalize(obj.axe);
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
