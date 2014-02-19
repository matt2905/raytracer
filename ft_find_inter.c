/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_inter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 14:11:16 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/16 17:13:15 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <string.h>
#include <libft.h>
#include "ft_rtv1.h"

const t_tab_obj		g_obj[5] =
{
	{"sphere", ft_sphere},
	{"plane", ft_plane},
	{"cone", ft_cone},
	{"cylindre", ft_cylinder},
	{NULL, NULL}
};

double		ft_find_inter(t_data *d, int *i)
{
	int		k;
	int		save;
	double	alpha1;
	double	alpha2;

	alpha2 = HUGE_VAL;
	save = -1;
	while (++(*i) < d->nb_objects)
	{
		k = -1;
		while (g_obj[++k].type != NULL)
		{
			if (ft_strcmp(d->objects[*i].type, g_obj[k].type) == 0)
			{
				alpha1 = g_obj[k].func(d->objects[*i], d->cam.dir, d->cam.pos);
				if (alpha1 > 0.0 && (alpha1 < alpha2))
				{
					save = *i;
					alpha2 = alpha1;
				}
			}
		}
	}
	*i = save;
	return (alpha2);
}
