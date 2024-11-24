/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:42:51 by sabitbol          #+#    #+#             */
/*   Updated: 2024/11/24 23:59:36 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "collison.h"
#include "mini_rt.h"
#include "angle.h"
#include "math.h"
#include "color.h"
#include "mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * data->bits_per_pixel);
	*(unsigned int*)dst = color;
}

t_plane    *get_closest_plan(t_line *line, t_scene *scene, t_point *p)
{
    t_plane *obj;
    t_point p_temp;
    int     i;

    i = -1;
    obj = scene->planes;
	if (line->vector.z == 0)
		line->vector.z = 1e-4;
    while (++i < scene->nb_planes)
    {
        p_temp = intersection_plane_line(line, &scene->planes[i]);
        if (p_temp.z < p->z && p_temp.z > 0)
        {
            obj = &scene->planes[i];
            *p = p_temp;
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

t_color    draw_pixel(t_scene *scene, t_line *line)
{
    t_point p;
    t_plane *plan;
	t_line	lineLight;
	p = (t_point){0, 0, INFINITY};

    plan = get_closest_plan(line, scene, &p);
	if (p.z == -1)
    {
        t_color c;
        c.r = 0;
        c.g = 0;
        c.b = 0;
		return (c);
    }
	lineLight = get_line_2point(&scene->lights[0].position, &p);
    float   scalar_light_obj = scalar_product(lineLight.vector, plan->vector);
    float   scalar_cam_obj = scalar_product(scene->cameras.vector, plan->vector);
	if ((scalar_light_obj < 0 && scalar_cam_obj > 0) || (scalar_light_obj > 0 && scalar_cam_obj < 0))
    {
        t_color c;
        c.r = 0;
        c.g = 0;
        c.b = 0;
		return (c);
    }
	return (get_multiple_color(plan->color, scene, fabs(scalar_light_obj)));
}

int draw_window(t_scene *scene)
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
			my_mlx_pixel_put(&scene->img, x, y, color_to_int(draw_pixel(scene, &line)));
            x++;
        }
        y++;
    }
	mlx_put_image_to_window(scene->mlx, scene->window, scene->img.img, 0, 0);
	return (0);
}
