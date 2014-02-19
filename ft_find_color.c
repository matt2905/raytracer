/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 09:43:42 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/16 20:04:05 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <libft.h>
#include "ft_rtv1.h"

extern t_tab_obj	g_obj[5];

static t_vector		ft_get_normal(t_object obj, t_vector inter)
{
	t_vector	normal;

	if (ft_strcmp(obj.type, "sphere") == 0)
		normal = ft_vector_sub(obj.pos, inter);
	else
		normal = obj.axe;
	normal = ft_vector_normalize(normal);
	return (normal);
}

static void			ft_get_color(t_object obj, t_data *d, int i, t_vector n)
{
	double			alpha;

	alpha = ft_vector_dot(d->lights[i].dir, n);
	d->r += obj.rgb[0] * alpha * d->lights[i].coef;
	d->r += d->lights[i].rgb[0] * alpha * d->lights[i].coef;
	if (d->r < 0)
		d->r = 0;
	if (d->r > 255)
		d->r = 255;
	d->g += obj.rgb[1] * alpha * d->lights[i].coef;
	d->g += d->lights[i].rgb[1] * alpha * d->lights[i].coef;
	if (d->g < 0)
		d->g = 0;
	if (d->g > 255)
		d->g = 255;
	d->b += obj.rgb[2] * alpha * d->lights[i].coef;
	d->b += d->lights[i].rgb[2] * alpha * d->lights[i].coef;
	if (d->b < 0)
		d->b = 0;
	if (d->b > 255)
		d->b = 255;
}

static int			ft_search_inter(t_data *d, int i, int obj, t_vector o)
{
	int			k;
	int			j;
	double		alpha;
	t_vector	v;

	j = -1;
	v = d->lights[i].dir;
	while (++j < d->nb_objects)
	{
		k = -1;
		if (j != obj)
		{
			while (g_obj[++k].type != NULL)
			{
				if (ft_strcmp(d->objects[j].type, g_obj[k].type) == 0)
				{
					alpha = g_obj[k].func(d->objects[j], v, o);
					if (alpha > 0.0 && alpha < HUGE_VAL)
						return (1);
				}
			}
		}
	}
	return (0);
}

static void			ft_get_shadow(t_data *d)
{
	d->r -= d->r * 0.3;
	d->g -= d->g * 0.3;
	d->b -= d->b * 0.3;
}

void				ft_find_color(double alpha, t_data *d, int obj)
{
	int				i;
	t_vector		inter;
	t_vector		normal;

	i = -1;
	d->r = d->objects[obj].rgb[0];
	d->g = d->objects[obj].rgb[1];
	d->b = d->objects[obj].rgb[2];
	inter = ft_vector_intercept(d->cam.dir, d->cam.pos, alpha);
	normal = ft_get_normal(d->objects[obj], inter);
	while (++i < d->nb_lights)
	{
		d->lights[i].dir = ft_vector_sub(d->lights[i].pos, inter);
		d->lights[i].dir = ft_vector_normalize(d->lights[i].dir);
		if (ft_search_inter(d, i, obj, d->lights[i].pos) == 0)
			ft_get_color(d->objects[obj], d, i, normal);
		else
			ft_get_shadow(d);
	}
}