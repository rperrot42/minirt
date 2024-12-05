/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere->c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:53:26 by sabitbol          #+#    #+#             */
/*   Updated: 2024/12/02 17:55:19 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collison.h"
#include "angle.h"
#include <math.h>

t_point	intersection_sphere_line(t_line *line, t_sphere *sphere)
{
	float	A = line->vector.x * line->vector.x + line->vector.y * line->vector.y + line->vector.z * line->vector.z;
	float	B = 2 * ((line->position.x - sphere->position.x) * line->vector.x + (line->position.y - sphere->position.y) * line->vector.y + (line->position.z - sphere->position.z) * line->vector.z);
	float	C = (line->position.x - sphere->position.x) * (line->position.x - sphere->position.x) + (line->position.y - sphere->position.y) * (line->position.y - sphere->position.y) + (line->position.z - sphere->position.z) * (line->position.z - sphere->position.z) - sphere->radius * sphere->radius;

	float	b4ac = B * B - 4 * A * C;
	if (b4ac < 0)
	{
		t_point p;
		p.x = 0;
		p.y = 0;
		p.z = INFINITY;
		return (p);
	}
	float	t1 = (-B - sqrt(b4ac)) / (2 * A);
	float	t2 = (-B + sqrt(b4ac)) / (2 * A);

	t_point	p1;
	t_point	p2;

	if (t1 <= t2)
	{
		p1.x = line->position.x + t1 * line->vector.x;
		p1.y = line->position.y + t1 * line->vector.y;
		p1.z = line->position.z + t1 * line->vector.z;
		return (p1);
	}
	p2.x = line->position.x + t2 * line->vector.x;
	p2.y = line->position.y + t2 * line->vector.y;
	p2.z = line->position.z + t2 * line->vector.z;
	return (p2);
}

t_sphere    *get_closest_sphere(t_line *line, t_scene *scene, t_line_color *l)
{
    t_sphere *obj;
    t_point p_temp;
    int     i;

    i = -1;
    obj = scene->spheres;
	if (line->vector.z == 0)
		line->vector.z = 1e-4;
    while (++i < scene->nb_spheres)
    {
        p_temp = intersection_sphere_line(line, scene->spheres + i);
        if (p_temp.z < l->position.z && p_temp.z > 0)
        {
            obj = scene->spheres + i;
            l->position = p_temp;
			l->type = SPHERE;
        }
    }
	if (l->position.z != INFINITY && l->type == SPHERE)
    {
        l->color = obj->color;
		l->vector = get_line_2point(&obj->position, &l->position).vector;
    }
    return (obj);
}
