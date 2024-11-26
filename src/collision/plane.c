/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:35:25 by rperrot           #+#    #+#             */
/*   Updated: 2024/11/26 12:06:02 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collison.h"
#include "angle.h"
#include <math.h>

t_point intersection_plane_line(t_line *line, t_plane *plane)
{
	float t;
	t_point point;

	t = -(plane->d + (plane->vector.x * line->position.x + plane->vector.y * line->position.y + plane->vector.z * line->position.z)) \
	/ (plane->vector.x * line->vector.x + plane->vector.y * line->vector.y + plane->vector.z * line->vector.z);
	if (fabs(t) < 1e-6)
			return (t_point){0, 0, -INFINITY};
	point.x = line->vector.x * t + line->position.x;
	point.y = line->vector.y * t + line->position.y;
	point.z = line->vector.z * t + line->position.z;
	return (point);
}

int	point_between(t_point a, t_point b, t_point c)
{
	if (scalar_product(get_line_2point(&a, &b).vector, get_line_2point(&a, &c).vector) < 0)
		return (0);
	if (sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z)) < \
		sqrt((c.x - a.x) * (c.x - a.x) + (c.y - a.y) * (c.y - a.y) + (c.z - a.z) * (c.z - a.z)))
		return (0);
	return (1);
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



