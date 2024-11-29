/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:42:51 by sabitbol          #+#    #+#             */
/*   Updated: 2024/11/29 14:24:26 by sabitbol         ###   ########.fr       */
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * data->bits_per_pixel);
	*(unsigned int*)dst = color;
}

t_color    draw_pixel(t_scene *scene, t_line *line)
{
    t_line_color    l = (t_line_color){0};
    void    *obj;
    
    l.position.z = INFINITY;
    if (line->vector.z == 0)
		line->vector.z = 1e-4;
    obj = get_closest_obj(line, scene, &l);
	if (l.position.z == INFINITY)
    {
        t_color c = {0};
		return (c);
    }
    return (get_color_obj(scene, obj, &l, line));
}

int draw_window(t_scene *scene)
{
    int     x;
    int     y;
    t_line  line;
    float fov = scene->cameras.fov * M_PI / 360;
	long actual_fps;

    y = 0;
	actual_fps = ft_clock();
    line = (t_line){0};
    line.vector.z = 1;
	all_deplacement(scene, actual_fps - scene->last_fps);
    while (y < LENGTH)
    {
        x = 0;
        line.vector.y = -tanf(((2.0 * y) -  LENGTH) / (LENGTH - 2) * fov);
        while (x < LENGTH)
        {
            line.vector.x = tanf(((2.0 * x) -  LENGTH) / (LENGTH - 2) * fov);
			my_mlx_pixel_put(&scene->img, x, y, color_to_int(draw_pixel(scene, &line)));
            x++;
        }
        y++;
    }
	scene->fps++;
	if (scene->second_actual != actual_fps / 100)
	{
		printf("fps : %d\n", scene->fps);

		scene->second_actual = ft_clock() / 100;
		scene->fps = 0;
	}
	mlx_put_image_to_window(scene->mlx, scene->window, scene->img.img, 0, 0);
	scene->last_fps = actual_fps;
	return (0);
}
