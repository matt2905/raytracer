/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 13:28:40 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/14 19:41:00 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_rt.h"

void			ft_init_object(t_object *new)
{
	new->name = NULL;
	new->type = NULL;
	new->pos.x = 0.0;
	new->pos.y = 0.0;
	new->pos.z = 0.0;
	new->axe.x = 0.0;
	new->axe.y = 0.0;
	new->axe.z = 0.0;
	new->material.r = 0;
	new->material.g = 0;
	new->material.b = 0;
	new->material.diffuse = 0.0;
	new->material.specular = 0.0;
	new->material.shininess = 0.0;
	new->material.transparent = 0.0;
	new->material.reflective = 0.0;
	new->material.refraction = 0.0;
}

static t_file	*ft_new_line(char *line)
{
	t_file	*new;
	char	*tmp;

	new = (t_file *)malloc(sizeof(t_file));
	new->next = NULL;
	tmp = line;
	while (ft_isprint(*tmp) == 0)
		tmp++;
	new->line = ft_strdup(tmp);
	free(line);
	return (new);
}

void			ft_add_file(t_file **file, char *line)
{
	if (*file == NULL)
		*file = ft_new_line(line);
	else
		ft_add_file(&((*file)->next), line);
}
