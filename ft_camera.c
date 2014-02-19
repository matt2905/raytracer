/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 11:56:25 by mmartin           #+#    #+#             */
/*   Updated: 2014/02/16 16:43:32 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include <get_next_line.h>
#include "ft_rtv1.h"

static void		ft_error(void)
{
	ft_putendl_fd("Wrong format file", 2);
	ft_putendl_fd("Example:", 2);
	ft_putendl_fd("scene", 2);
	ft_putendl_fd("\tname", 2);
	ft_putendl_fd("\t\texample", 2);
	ft_putendl_fd("\tcamera", 2);
	ft_putendl_fd("\t\torigin", 2);
	ft_putendl_fd("\t\t\tX", 2);
	ft_putendl_fd("\t\t\tY", 2);
	ft_putendl_fd("\t\t\tZ", 2);
	ft_putendl_fd("\trender", 2);
	ft_putendl_fd("\t\tmlx_all_objects", 2);
	ft_putendl_fd("\t\t\tWIDTH", 2);
	ft_putendl_fd("\t\t\tHEIGHT", 2);
	ft_putendl_fd("\tObjects", 2);
	ft_putendl_fd("\t\tname", 2);
	ft_putendl_fd("\t\t\texample_plane", 2);
	ft_putendl_fd("\t\tinter", 2);
	ft_putendl_fd("\t\t\tplane", 2);
	ft_putendl_fd("\t\tcolor", 2);
	ft_putendl_fd("\t\t\trgb", 2);
	ft_putendl_fd("\t\t\t\tR", 2);
	ft_putendl_fd("\t\t\t\tG", 2);
	ft_putendl_fd("\t\t\t\tB", 2);
	exit(EXIT_FAILURE);
}

static void		ft_camera(t_file **file, t_data *d)
{
	while ((*file) && (*file)->line && ft_strcmp((*file)->line, "render") != 0)
	{
		if (ft_strcmp((*file)->line, "origin") == 0)
		{
			*file = (*file)->next;
			d->cam.pos.x = ft_atof((*file)->line);
			*file = (*file)->next;
			d->cam.pos.y = ft_atof((*file)->line);
			*file = (*file)->next;
			d->cam.pos.z = ft_atof((*file)->line);
		}
		if (ft_strcmp((*file)->line, "rotation") == 0)
		{
			*file = (*file)->next;
			d->cam.rot.x = ft_atof((*file)->line);
			*file = (*file)->next;
			d->cam.rot.y = ft_atof((*file)->line);
			*file = (*file)->next;
			d->cam.rot.z = ft_atof((*file)->line);
		}
		*file = (*file)->next;
	}
}

static void		ft_render(t_file **file, t_data *d)
{
	if (ft_strcmp((*file)->line, "render") != 0)
	{
		while (ft_strcmp((*file)->line, "render") != 0)
			*file = (*file)->next;
	}
	if ((*file) && (*file)->line)
	{
		*file = (*file)->next;
		*file = (*file)->next;
		d->width = ft_atoi((*file)->line);
		*file = (*file)->next;
		d->height = ft_atoi((*file)->line);
		*file = (*file)->next;
		d->fov = ft_atoi((*file)->line);
	}
	if (d->width < 680 || d->height < 480)
	{
		ft_putendl_fd("Render is too small", 2);
		exit(EXIT_FAILURE);
	}
	if (d->width > 2560 || d->height > 1440)
	{
		ft_putendl_fd("Render is too large", 2);
		exit(EXIT_FAILURE);
	}
}

static void		ft_init_camera(t_data *d)
{
	d->cam.pos.x = 0.0;
	d->cam.pos.y = 0.0;
	d->cam.pos.z = 0.0;
	d->cam.rot.x = 0.0;
	d->cam.rot.y = 0.0;
	d->cam.rot.z = 0.0;
}

void			ft_init(t_file **file, t_data *d, char *str)
{
	int		fd;
	char	*line;

	if ((fd = open(str, O_RDONLY)) == -1)
		ft_error();
	get_next_line(fd, &line);
	if (ft_strcmp(line, "scene") != 0)
		ft_error();
	free(line);
	while (get_next_line(fd, &line))
		ft_add_file(file, line);
	close(fd);
	ft_init_camera(d);
	ft_camera(file, d);
	if ((*file) && (*file)->line)
		ft_render(file, d);
	else
		ft_error();
}
