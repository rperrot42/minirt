/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:35:25 by rperrot           #+#    #+#             */
/*   Updated: 2024/11/26 19:13:38 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collison.h"
#include "angle.h"
#include "color.h"
#include <math.h>
t_point	intersection_sphere_line(t_line *line, t_sphere *sphere);

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
        p_temp = intersection_plane_line(line, scene->planes + i);
        if (p_temp.z < p->z && p_temp.z > 0)
        {
            obj = scene->planes + i;
            *p = p_temp;
        }
    }
    return (obj);
}

t_color	get_color_plan(t_scene *scene, t_plane *plan, t_point *p, t_line *line)
{
	t_line lineLight = get_line_2point(&scene->lights[0].position, p);
	int i = -1;
	while (++i < scene->nb_planes)
    {
        if (plan != scene->planes + i && scalar_product(lineLight.vector, scene->planes[i].vector) != 0)
        {
            t_point q = intersection_plane_line(&lineLight, scene->planes + i);
            if (q.z != -INFINITY && point_between(lineLight.position, *p, q))
                return (get_ambiant_color(plan->color, scene));
        }
    }
	// i = -1;
	// while (++i < scene->nb_spheres)
    // {
    //     t_point q = intersection_sphere_line(&lineLight, scene->spheres + i);
    //     if (q.z != -INFINITY && point_between(lineLight.position, *p, q))
    //         return (get_ambiant_color(plan->color, scene));
    // }
    float   scalar_light_obj = scalar_product(lineLight.vector, plan->vector);
    float   scalar_cam_obj = scalar_product(line->vector, plan->vector);
	if ((scalar_light_obj < 0 && scalar_cam_obj > 0) || (scalar_light_obj > 0 && scalar_cam_obj < 0))
		return (get_ambiant_color(plan->color, scene));
	return (get_multiple_color(plan->color, scene, fabs(scalar_light_obj)));
}
