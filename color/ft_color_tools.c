/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 16:44:13 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/18 19:03:55 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void	ft_coef_color(t_object obj, t_data *d, int i, t_vector n)
{
	double			alpha;
	double			diffuse;
	double			specular;

	diffuse = ft_diffuse_light(obj, d->lights[i], n);
	specular = ft_specular_light(obj, d->lights[i], n, d->cam.dir);
	alpha = diffuse + specular;
	d->r += diffuse * obj.material.r + specular * d->lights[i].rgb[0];
	d->g += diffuse * obj.material.g + specular * d->lights[i].rgb[1];
	d->b += diffuse * obj.material.b + specular * d->lights[i].rgb[2];
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
