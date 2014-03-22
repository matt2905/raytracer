/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 18:15:03 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/22 18:21:47 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_rt.h"

void	ft_destroy_data(t_data *d)
{
	t_object	*obj;
	int			i;

	obj = d->objects;
	i = -1;
	while (++i < d->nb_objects)
	{
		free(obj[i].name);
		free(obj[i].type);
		free(obj);
	}
	if (d->nb_lights)
		free(d->lights);
}
