/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:58:10 by sabitbol          #+#    #+#             */
/*   Updated: 2024/12/05 17:09:57 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "angle.h"
#include "color.h"
#include "collison.h"
#include <math.h>

void	*get_closest_obj(t_line *line, t_scene *scene, t_line_color *l)
{
	void	*plan;
	void	*sphere;
	void	*cylinder;
	
	if (scene->nb_planes > 0)
	{

		plan = get_closest_plan(line, scene, l);
	}
	if (scene->nb_spheres > 0)
	{
		sphere = get_closest_sphere(line, scene, l);
	}
	if (scene->nb_cylinders > 0)
	{
		cylinder = get_closest_cylinder(line, scene, l);
	}
	if (l->type == PLANE)
		return (plan);
	if (l->type == SPHERE)
		return (sphere);
	if (l->type == CYLINDER)
		return (cylinder);
	return (NULL);
}

t_color	get_color_obj(t_scene *scene, void *obj, t_line_color *l, t_line *line)
{
	if (intersection_obj_line(scene, obj, l, line))
		return (get_ambiant_color(l->color, scene));
	return (get_multiple_color(l->color, scene, fabs(l->scalar_light_obj)));
}

int	intersection_obj_line(t_scene *scene, void *obj, t_line_color *l, t_line *line)
{
	//-------------------------OTHER OBJECT------------------------------//
	t_line	lineLight = get_line_2point(&scene->lights[0].position, &l->position);
	int i;

	i = -1;
	while (++i < scene->nb_planes)
    {
        if (obj != scene->planes + i && scalar_product(lineLight.vector, scene->planes[i].vector) != 0)
        {
            t_point p = intersection_plane_line(&lineLight, scene->planes + i);
            if (p.z != INFINITY && point_between(lineLight.position, l->position, p))
                return (1);
        }
    }
	i = -1;
	while (++i < scene->nb_spheres)
    {
        if (obj != scene->spheres + i)
        {
            t_point p = intersection_sphere_line(&lineLight, scene->spheres + i);
            if (p.z != INFINITY && point_between(lineLight.position, l->position, p))
                return (1);
        }
    }
	i = -1;
	while (++i < scene->nb_cylinders)
    {
        if (obj != scene->cylinders + i)
        {
            t_point p = intersection_cylinder_line(&lineLight, scene->cylinders + i);
            if (p.z != INFINITY && point_between(lineLight.position, l->position, p))
                return (1);
        }
    }
	//-------------------------OTHER OBJECT------------------------------//

	//-------------------------OBJECT HIMSELF------------------------------//
	l->scalar_light_obj = scalar_product(lineLight.vector, l->vector);
	if (l->position.z != INFINITY)
	{
		if (l->type == PLANE)
		{
			//l->scalar_light_obj = scalar_product(lineLight.vector, l->vector);
			float	scalar_cam_obj = scalar_product(line->vector, l->vector);
			if ((l->scalar_light_obj < 0 && scalar_cam_obj > 0) || (l->scalar_light_obj > 0 && scalar_cam_obj < 0))
				return (1);
		}
		if (l->type == SPHERE || l->type == CYLINDER)
		{
			l->scalar_light_obj = scalar_product(get_line_2point(&l->position, &scene->lights[0].position).vector, l->vector);
			if (l->scalar_light_obj < 0)
				return (1);
		}
	}
	//-------------------------OBJECT HIMSELF------------------------------//
	return (0);
}
