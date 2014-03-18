/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 16:44:13 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/18 16:48:52 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void	ft_coef_color(t_object obj, t_data *d, int i, t_vector n)
{
	double			alpha;

	alpha = obj.material.diffuse * ft_vector_dot(d->lights[i].dir, n);
	if (alpha < 0.0)
		alpha = 0.0;
	d->r = obj.material.r * alpha * d->lights[i].coef;
	d->g = obj.material.g * alpha * d->lights[i].coef;
	d->b = obj.material.b * alpha * d->lights[i].coef;
}

void	ft_color_normalize(t_data *d)
{
	if (d->r > 255)
		d->r = 255;
	if (d->g > 255)
		d->g = 255;
	if (d->b > 255)
		d->b = 255;
	if (d->r < 0)
		d->r = 0;
	if (d->g < 0)
		d->g = 0;
	if (d->b < 0)
		d->b = 0;
}
