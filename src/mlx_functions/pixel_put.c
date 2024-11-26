/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:42:51 by sabitbol          #+#    #+#             */
/*   Updated: 2024/11/26 19:20:11 by sabitbol         ###   ########.fr       */
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

t_color    draw_pixel(t_scene *scene, t_line *line)
{
    t_point p;
    t_point q;
    t_plane *plan;
    t_sphere    *sphere;
	p = (t_point){0, 0, INFINITY};
    q = (t_point){0, 0, INFINITY};

    plan = get_closest_plan(line, scene, &p);
    sphere = get_closest_sphere(line, scene, &q);
	if (p.z == -INFINITY)
    {
        t_color c = {0};
		return (c);
    }
    if (p.z < q.z)
        return (get_color_plan(scene, plan, &p, line));
    return (sphere->color);
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
