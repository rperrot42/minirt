/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:22:35 by rperrot           #+#    #+#             */
/*   Updated: 2025/01/03 14:31:22 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft.h"

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef enum e_obj
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_obj;

typedef struct s_sphere
{
	t_point	position;
	t_color	color;
	double	radius;
}	t_sphere;

typedef struct s_line
{
	t_point	position;
	t_point	vector;
}	t_line;

typedef struct s_line_color
{
	t_point	position;
	t_point	vector;
	t_color	color;
	double	scalar_light_obj;
	t_obj	type;
	int		cylinder_end;
}	t_line_color;

typedef struct s_camera
{
	t_point	position;
	t_point	vector;
	double	fov;
}	t_camera;

typedef struct s_light
{
	t_point	position;
	t_color	color;
	double	intensity;
}	t_light;

typedef struct s_cylinder
{
	t_point	position;
	t_point	vector;
	double	radius;
	double	height;
	t_color	color;
}	t_cylinder;

typedef struct s_plane
{
	double	d;
	t_point	vector;
	t_point	p;
	t_color	color;
}	t_plane;

typedef struct s_ambient
{
	t_color	color;
	double	intensity;
}	t_ambient;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_move_mouse
{
	int		last_position_x;
	int		last_position_y;
	t_bool	left_click;
}	t_move_mouse;

typedef struct s_press_key
{
	t_bool	w_press;
	t_bool	s_press;
	t_bool	a_press;
	t_bool	d_press;
	t_bool	tab_press;
	t_bool	sp_press;
}	t_press_key;

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
	t_press_key		press_key;
	int				fps;
	int				second_actual;
	long			last_frame;
	int				last_fps;
	t_bool			light_in_obj;
}	t_scene;

typedef enum e_move
{
	LEFT,
	RIGHT,
	FORWARD,
	BACK
}	t_move;

typedef struct s_second_degree
{
	double	x1;
	double	x2;
}	t_second_degree;

typedef enum e_coordinate
{
	X,
	Y,
	Z
}	t_coordinate;

#endif
