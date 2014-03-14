/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/10 13:52:51 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/14 10:24:08 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RT_H
# define FT_RT_H

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct		s_obj
{
	double			a;
	double			b;
	double			c;
	float			delta;
	float			alpha1;
	float			alpha2;
}					t_obj;

typedef struct		s_vec
{
	t_vector		alpha;
	t_vector		beta;
	t_vector		gamma;
	t_vector		delta;
	t_vector		epsilon;
}					t_vec;

/*
**		misc	size of ray of sphere
**				constant of plane
*/

typedef struct		s_object
{
	t_vector		pos;
	t_vector		axe;
	double			misc;
	char			*name;
	char			*type;
	unsigned int	rgb[3];
}					t_object;

typedef struct		s_camera
{
	t_vector		pos;
	t_vector		dir;
	t_vector		rot;
}					t_camera;

typedef struct		s_light
{
	t_vector		pos;
	t_vector		dir;
	float			coef;
	unsigned int	rgb[3];
}					t_light;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	t_object		*objects;
	int				nb_objects;
	t_light			*lights;
	int				nb_lights;
	t_camera		cam;
	int				width;
	int				height;
	float			fov;
	double			r;
	double			g;
	double			b;
}					t_data;

typedef struct		s_tab_obj
{
	char			*type;
	double			(* func)(t_object, t_vector, t_vector);
}					t_tab_obj;

/*
**		for parsing
*/

typedef struct		s_file
{
	struct s_file	*next;
	char			*line;
}					t_file;

t_file			*ft_init(t_file **file, t_data *d, char *str);
void			ft_parsing(t_file *file, t_data *d);
void			ft_get_light(t_file *file, t_data *d);
void			ft_add_file(t_file **file, char *line);

void			ft_raytracing(t_data *d);
double			ft_find_inter(t_data *d, int *i);
void			ft_find_color(double alpha, t_data *d, int i);

/*
**		objects
*/

double			ft_cone(t_object obj, t_vector dir, t_vector o);
double			ft_plane(t_object obj, t_vector dir, t_vector o);
double			ft_sphere(t_object obj, t_vector dir, t_vector o);
double			ft_cylinder(t_object obj, t_vector dir, t_vector o);
t_vector		ft_get_normal_cylinder(t_object obj, t_vector inter);

/*
**		ft_vec_ope.c
*/

t_vector		ft_vector_add(t_vector a, t_vector b);
double			ft_vector_dot(t_vector a, t_vector b);
t_vector		ft_vector_sub(t_vector a, t_vector b);
t_vector		ft_vector_mult(t_vector a, double b);
t_vector		ft_vector_wedge(t_vector a, t_vector b);

/*
**		ft_vec_tools.c
*/

t_vector		ft_vector_normalize(t_vector v);
t_vector		ft_vector_copy(t_vector v);
t_vector		ft_vector_neg(t_vector v);
t_vector		ft_vector_intercept(t_vector v, t_vector o, double alpha);
double			ft_find_alpha(t_vector v, t_vector o, t_vector inter);

/*
**		ft_vec_rotation.c
*/

t_vector		ft_vector_rotation_x(t_vector v, double alpha);
t_vector		ft_vector_rotation_y(t_vector v, double alpha);
t_vector		ft_vector_rotation_z(t_vector v, double alpha);

#endif
