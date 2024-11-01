/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:42:51 by sabitbol          #+#    #+#             */
/*   Updated: 2024/10/31 14:50:36 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "collison.h"
#include "mini_rt.h"
#include "math.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * data->bits_per_pixel);
	*(unsigned int*)dst = color;
}

void    *get_closest_plan(t_line *line, t_scene *scene, t_point *p)
{
    t_plane *obj;
    t_point temp;
	int 	avancement;
    int     i;

    i = -1;
    obj = scene->planes;
	if (line->vector.z == 0)
		line->vector.z = 1e-4;
	avancement = (line->vector.z > 0) - (line ->vector.z < 0);
    while (++i < scene->nb_planes)
    {
        temp = intersection_plane_line(line, &scene->planes[i]);
        if (temp.z * avancement < p->z)
        {
            obj = &scene->planes[i];
            *p = temp;
        }
    }
    return (obj);
}
t_line	get_line_2point(t_point *a, t_point *b)
{
	t_line line;

	line.vector.x = b->x - a->x;
	line.vector.y = b->y - a->y;
	line.vector.z = b->z - a->z;
	line.position = *a;
	return (line);
}

void    draw_pixel(t_scene *scene, t_line *line)
{
    t_point p;
    t_plane *plan;

    p = intersection_plane_line(line, scene->planes);
    plan = get_closest_plan(line, scene, &p);
}

void    draw_window(t_scene *scene)
{
    int     x;
    int     y;
    t_line  line;
    float fov = scene->cameras.fov * M_PI / 360;

    y = 0;
    line = (t_line){0};
    line.vector.z = 1;
    while (y < LENGTH)
    {
        x = 0;
        line.vector.y = tanf(((2.0 * y) -  LENGTH) / (LENGTH - 2) * fov);
        while (x < LENGTH)
        {
            line.vector.x = tanf(((2.0 * x) -  LENGTH) / (LENGTH - 2) * fov);
            draw_pixel(scene, &line);
            x++;
        }
        y++;
    }
}
