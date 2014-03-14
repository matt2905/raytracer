/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 15:02:58 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/03 13:30:43 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_rt.h"

static void			ft_get_color(t_file **file, t_object *new)
{
	if (ft_strcmp((*file)->line, "color") == 0)
	{
		if (*file && (*file)->next)
		{
			*file = (*file)->next;
			new->rgb[0] = ft_atoh((*file)->line);
		}
		if (*file && (*file)->next)
		{
			*file = (*file)->next;
			new->rgb[1] = ft_atoh((*file)->line);
		}
		if (*file && (*file)->next)
		{
			*file = (*file)->next;
			new->rgb[2] = ft_atoh((*file)->line);
		}
	}
}

static void			ft_get_inter(t_file **file, t_object *new, int flag)
{
	if (flag == 1 && ft_strcmp((*file)->line, "origin") == 0)
	{
		*file = (*file)->next;
		new->pos.x = ft_atof((*file)->line);
		*file = (*file)->next;
		new->pos.y = ft_atof((*file)->line);
		*file = (*file)->next;
		new->pos.z = ft_atof((*file)->line);
		*file = (*file)->next;
	}
	if (flag == 2 && ft_strcmp((*file)->line, "rotation") == 0)
	{
		*file = (*file)->next;
		new->axe.x = ft_atof((*file)->line);
		*file = (*file)->next;
		new->axe.y = ft_atof((*file)->line);
		*file = (*file)->next;
		new->axe.z = ft_atof((*file)->line);
		*file = (*file)->next;
	}
}

static void			ft_init_object(t_object *new)
{
	new->name = NULL;
	new->type = NULL;
	new->pos.x = 0.0;
	new->pos.y = 0.0;
	new->pos.z = 0.0;
	new->axe.x = 0.0;
	new->axe.y = 0.0;
	new->axe.z = 0.0;
	new->rgb[0] = 0.0;
	new->rgb[1] = 0.0;
	new->rgb[2] = 0.0;
}

static t_object		ft_new_object(t_file **file)
{
	t_object	new;

	ft_init_object(&new);
	*file = (*file)->next;
	if (ft_strcmp((*file)->line, "name") == 0)
	{
		*file = (*file)->next;
		new.name = ft_strdup((*file)->line);
		*file = (*file)->next;
	}
	if (ft_strcmp((*file)->line, "inter") == 0)
	{
		*file = (*file)->next;
		ft_get_inter(file, &new, 1);
		ft_get_inter(file, &new, 2);
		new.type = ft_strdup((*file)->line);
		*file = (*file)->next;
		if (ft_strcmp((*file)->line, "color") != 0)
		{
			new.misc = ft_atof((*file)->line);
			*file = (*file)->next;
		}
	}
	ft_get_color(file, &new);
	return (new);
}

void				ft_parsing(t_file *file, t_data *d)
{
	t_file	*tmp;
	int		i;

	i = 0;
	d->nb_objects = 0;
	tmp = file;
	while (tmp)
	{
		if (ft_strcmp(tmp->line, "Object") == 0)
			d->nb_objects++;
		tmp = tmp->next;
	}
	if (d->nb_objects == 0)
	{
		ft_putendl_fd("No object", 2);
		exit(EXIT_FAILURE);
	}
	d->objects = (t_object *)malloc(sizeof(t_object) * d->nb_objects);
	while (file && ft_strcmp(file->line, "Light"))
	{
		if (ft_strcmp(file->line, "Object") == 0)
			d->objects[i++] = ft_new_object(&file);
		else
			file = file->next;
	}
}
