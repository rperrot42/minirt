/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:59:25 by sabitbol          #+#    #+#             */
/*   Updated: 2025/01/12 13:36:23 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "collison.h"
#include "mini_rt.h"
#include "math.h"
#include "color.h"
#include "mlx.h"
#include "move.h"
#include "utils.h"

static void	calculus_fps(t_scene *scene, long actual_fps);

static void	create_img(t_scene *scene);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * data->bits_per_pixel);
	*(unsigned int *)dst = color;
}

t_color	draw_pixel(t_scene *scene, t_line *line)
{
	t_line_color	l;
	t_color			c;
	void			*obj;

	l = (t_line_color){0};
	c = (t_color){0};
	l.position.z = INFINITY;
	if (line->vector.z == 0)
		line->vector.z = 1e-4;
	obj = get_closest_obj(line, scene, &l);
	if (l.position.z == INFINITY)
		return (c);
	return (get_color_obj(scene, obj, &l, line));
}

int	draw_window(t_scene *scene)
{
	long	actual_fps;

	actual_fps = ft_clock();
	all_deplacement(scene, actual_fps - scene->last_frame);
	create_img(scene);
	calculus_fps(scene, actual_fps);
	mlx_put_image_to_window(scene->mlx, scene->window, scene->img.img, 0, 0);
	return (0);
}

static void	create_img(t_scene *scene)
{
	int		y;
	int		x;
	float	avancement;
	t_line	line;

	line.position = scene->cameras.position;
	line.vector.z = Z_NEAR;
	avancement = tanf(scene->cameras.fov * M_PI / 360) * Z_NEAR * 2 / LENGTH;
	y = -1;
	while (++y < LENGTH)
	{
		x = -1;
		line.vector.y = -tanf(scene->cameras.fov * M_PI / 360) * Z_NEAR + \
		(LENGTH - y - 1) * avancement;
		while (++x < LENGTH)
		{
			line.vector.x = -tanf(scene->cameras.fov * M_PI / 360) * \
Z_NEAR + x * avancement;
			my_mlx_pixel_put(&scene->img, x, y, \
			color_to_int(draw_pixel(scene, &line)));
		}
	}
}

static void	calculus_fps(t_scene *scene, long actual_fps)
{
	scene->fps++;
	if (scene->second_actual != actual_fps / 100)
	{
		scene->second_actual = ft_clock() / 100;
		scene->last_fps = scene->fps;
		scene->fps = 0;
	}
	printf_fps(scene);
	scene->last_frame = actual_fps;
}
