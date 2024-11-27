/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:58:10 by sabitbol          #+#    #+#             */
/*   Updated: 2024/11/27 17:44:39 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "angle.h"
#include "color.h"
#include "collison.h"
#include <math.h>

void	*get_closest_obj(t_line *line, t_scene *scene, t_line_color *l)
{
	void	*obj;
	
	obj = get_closest_plan(line, scene, l);
	return (obj);
}

t_color	get_color_obj(t_scene *scene, void *obj, t_line_color *l, t_line *line)
{
	if (intersection_obj_line(scene, obj, l, line))
		return (get_ambiant_color(l->color, scene));
	return (get_multiple_color(l->color, scene, fabs(l->scalar_light_obj)));
}

int	intersection_obj_line(t_scene *scene, void *obj, t_line_color *l, t_line *line)
{
	t_line	lineLight = get_line_2point(&scene->lights[0].position, &l->position);

	int i = -1;
	while (++i < scene->nb_planes)
    {
        if (obj != scene->planes + i && scalar_product(lineLight.vector, scene->planes[i].vector) != 0)
        {
            t_point p = intersection_plane_line(&lineLight, scene->planes + i);
            if (p.z != -INFINITY && point_between(lineLight.position, l->position, p))
                return (1);
        }
    }
	l->scalar_light_obj = scalar_product(lineLight.vector, l->vector);
    float	scalar_cam_obj = scalar_product(line->vector, l->vector);
	if ((l->scalar_light_obj < 0 && scalar_cam_obj > 0) || (l->scalar_light_obj > 0 && scalar_cam_obj < 0))
		return (1);
	return (0);
}
