/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:57:51 by sabitbol          #+#    #+#             */
/*   Updated: 2025/01/06 16:58:20 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collison.h"
#include "angle.h"
#include "utils.h"
#include <math.h>

t_point	intersection_sphere_line(t_line *line, t_sphere *sphere)
{
	t_point	p;

	p = parametric_equation(*line, second_degree_equation(line->vector.x * \
	line->vector.x + line->vector.y * line->vector.y + line->vector.z * \
	line->vector.z, 2 * ((line->position.x - sphere->position.x) * \
	line->vector.x + (line->position.y - sphere->position.y) * line->vector.y \
	+ (line->position.z - sphere->position.z) * line->vector.z), \
	(line->position.x - sphere->position.x) * (line->position.x - \
	sphere->position.x) + (line->position.y - sphere->position.y) * \
	(line->position.y - sphere->position.y) + (line->position.z - \
	sphere->position.z) * (line->position.z - sphere->position.z) - \
	sphere->radius * sphere->radius));
	return (p);
}

t_sphere	*get_closest_sphere(t_line *line, t_scene *scene, t_line_color *l)
{
	t_sphere	*obj;
	t_point		p_temp;
	int			i;

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
