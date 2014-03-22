/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 13:28:21 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/19 17:53:16 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <libft.h>
#include "ft_rt.h"

static void		ft_search_inter(t_data *d, float x, float y, float z)
{
	int				i;
	t_vector		target;
	unsigned int	color;
	double			alpha;

	i = -1;
	color = 0x000000;
	target.x = x;
	target.y = y;
	target.z = z;
	target = ft_vector_rotation_x(target, d->cam.rot.x);
	target = ft_vector_rotation_y(target, d->cam.rot.y);
	target = ft_vector_rotation_z(target, d->cam.rot.z);
	d->cam.dir = ft_vector_sub(d->cam.pos, target);
	d->cam.dir = ft_vector_normalize(d->cam.dir);
	if ((alpha = ft_find_inter(d, &i)) != HUGE_VAL)
	{
		ft_find_color(alpha, d, i);
		color = color + ((int)d->r << 16) + ((int)d->g << 8) + (int)d->b;
	}
	color = mlx_get_color_value(d->mlx, color);
	d->r = (color & 0xFF0000) / 65536;
	d->g = (color & 0xFF00) / 256;
	d->b = (color & 0xFF);
}

static void		ft_put_pixel_to_image(t_data *d, int x, int y)
{
	int		ret;

	ret = y * d->sizeline + x * d->bpp / 8;
	if (d->endian == 0)
	{
		d->data[ret] = d->b;
		d->data[ret + 1] = d->g;
		d->data[ret + 2] = d->r;
	}
	else
	{
		d->data[ret] = d->r;
		d->data[ret + 1] = d->g;
		d->data[ret + 2] = d->b;
	}
}

void			ft_raytracing(t_data *d)
{
	int		x;
	int		y;
	float	z;
	float	w;
	float	h;

	y = -1;
	z = fabs(d->width / (2.0 * tan(M_PI * (d->fov / 2.0) / 180.0)));
	w = (float)d->width / 2.00 + 0.5;
	h = (float)d->height / 2.00 + 0.5;
	while (++y <= d->height)
	{
		x = -1;
		while (++x < d->width)
		{
			ft_search_inter(d, (float)x - w, (float)y - h, z);
			ft_put_pixel_to_image(d, x, d->height - y);
		}
	}
}
