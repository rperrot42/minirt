/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:53:26 by sabitbol          #+#    #+#             */
/*   Updated: 2024/11/29 14:27:12 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collison.h"
#include "angle.h"
#include <math.h>

t_point	intersection_sphere_line(t_line *line, t_sphere *sphere)
{
	t_point	p1;
	t_point	p2;
	float	t1;
	float	t2;
	float	b4ac;

	b4ac = pow(2 * ((line->position.x - sphere->position.x) * line->vector.x + (line->position.y - sphere->position.y) * line->vector.y + (line->position.z - sphere->position.z) * line->vector.z), 2) \
	- 4 * (line->vector.x * line->vector.x + line->vector.y * line->vector.y + line->vector.z * line->vector.z) * \
	(pow(line->position.x - sphere->position.x, 2) + pow(line->position.y - sphere->position.y, 2) + pow(line->position.z - sphere->position.z, 2) - sphere->radius * sphere->radius);
	if (b4ac < 0)
	{
		// printf("Line position: (%f, %f, %f)\n", line->position.x, line->position.y, line->position.z);
		// printf("Sphere position: (%f, %f, %f)\n", sphere->position.x, sphere->position.y, sphere->position.z);
		// printf("Direction vector: (%f, %f, %f)\n", line->vector.x, line->vector.y, line->vector.z);
		// printf("Discriminant: %f\n", b4ac);
		p1.x = 0;
		p1.y = 0;
		p1.z = INFINITY;
		return (p1);
	}
	t1 = -((2 * ((line->position.x - sphere->position.x) * line->vector.x + (line->position.y - sphere->position.y) * line->vector.y + (line->position.z - sphere->position.z) * line->vector.z)) + sqrt(b4ac)) / (2 * line->vector.x * line->vector.x + line->vector.y * line->vector.y + line->vector.z * line->vector.z);
	t2 = -((2 * ((line->position.x - sphere->position.x) * line->vector.x + (line->position.y - sphere->position.y) * line->vector.y + (line->position.z - sphere->position.z) * line->vector.z)) - sqrt(b4ac)) / (2 * line->vector.x * line->vector.x + line->vector.y * line->vector.y + line->vector.z * line->vector.z);
	p1.x = line->position.x + t1 * line->vector.x;
	p1.y = line->position.y + t1 * line->vector.y;
	p1.z = line->position.z + t1 * line->vector.z;
	p2.x = line->position.x + t2 * line->vector.x;
	p2.y = line->position.y + t2 * line->vector.y;
	p2.z = line->position.z + t2 * line->vector.z;
	if (point_between(line->position, p1, p2))
		return (p2);
	return (p1);
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
		//printf("sphere : %f / %f / %f\n", p_temp.x, p_temp.y, p_temp.z);
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
