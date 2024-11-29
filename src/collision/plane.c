/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:35:25 by rperrot           #+#    #+#             */
/*   Updated: 2024/11/28 16:10:08 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collison.h"
#include "angle.h"
#include "color.h"
#include <math.h>

t_point intersection_plane_line(t_line *line, t_plane *plane)
{
	float t;
	t_point point;

	t = -(plane->d + (plane->vector.x * line->position.x + plane->vector.y * line->position.y + plane->vector.z * line->position.z)) \
	/ (plane->vector.x * line->vector.x + plane->vector.y * line->vector.y + plane->vector.z * line->vector.z);
	if (fabs(t) < 1e-6)
			return (t_point){0, 0, INFINITY};
	point.x = line->vector.x * t + line->position.x;
	point.y = line->vector.y * t + line->position.y;
	point.z = line->vector.z * t + line->position.z;
	return (point);
}

void    *get_closest_plan(t_line *line, t_scene *scene, t_line_color *l)
{
    t_plane *obj;
    t_point p_temp;
    int     i;

    i = -1;
    obj = scene->planes;
    while (++i < scene->nb_planes)
    {
        p_temp = intersection_plane_line(line, scene->planes + i);
        if (p_temp.z < l->position.z && p_temp.z > 0)
        {
            obj = scene->planes + i;
            l->position = p_temp;
            l->type = PLANE;
        }
    }
    if (l->position.z != INFINITY && l->type == PLANE)
    {
        l->vector = obj->vector;
        l->color = obj->color;
        l->type = PLANE;
    }
    // printf("r : %d\n", l->color.r);
    // printf("g : %d\n", l->color.g);
    // printf("b : %d\n", l->color.b);
    // printf("Vx : %f\n", l->vector.x);
    // printf("Vy : %f\n", l->vector.y);
    // printf("Vz : %f\n", l->vector.z);
    // printf("Px : %f\n", l->position.x);
    // printf("Py : %f\n", l->position.y);
    // printf("Pz : %f\n", l->position.z);
    return (obj);
}
