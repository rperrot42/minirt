/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:22:35 by rperrot           #+#    #+#             */
/*   Updated: 2024/11/24 20:55:41 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "libft.h"

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef struct s_sphere
{
	t_point	position;
	t_color	color;
	float	radius;
}	t_sphere;

typedef struct s_line{
	t_point	position;
	t_point	vector;
}	t_line;

typedef struct s_camera
{
	t_point	position;
	t_point	vector;
	float	fov;
}	t_camera;

typedef struct s_light
{
	t_point	position;
	t_color	color;
	float	intensity;
}	t_light;

typedef struct s_cylinder
{
	t_point	position;
	t_point	vector;
	float	diameter;
	float	height;
	t_color	color;
}	t_cylinder;

typedef struct s_plane
{
	float	d;
	t_point	vector;
	t_point	p;
	t_color	color;
}	t_plane;

typedef struct s_ambient
{
	t_color	color;
	float	intensity;
}	t_ambient;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_move_mouse
{
	int		last_position_x;
	int		last_position_y;
	t_bool	left_click;
}	t_move_mouse;

typedef struct s_scene
{
	t_ambient		ambient;
	t_sphere		*spheres;
	short			nb_spheres;
	t_light			*lights;
	short			nb_lights;
	t_camera		cameras;
	t_cylinder		*cylinders;
	short			nb_cylinders;
	t_plane			*planes;
	short			nb_planes;
	void			*mlx;
	void			*window;
	t_data			img;
	t_move_mouse	move_mouse;
}	t_scene;

typedef enum s_obj
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_obj;

typedef enum e_move
{
	LEFT,
	RIGHT,
	FORWARD,
	BACK
}	t_move;

#endif
