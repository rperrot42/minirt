/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:08:58 by sabitbol          #+#    #+#             */
/*   Updated: 2025/01/06 16:12:22 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "angle.h"
#include "color.h"
#include "collison.h"
#include <math.h>

static int	inter_shad_plane(t_scene *scene, void *obj, t_line_color *l, \
t_line line_light)
{
	int		i;
	t_point	p;

	i = -1;
	while (++i < scene->nb_planes)
	{
		if (obj != scene->planes + i && scalar_product(\
		line_light.vector, scene->planes[i].vector) != 0)
		{
			p = intersection_plane_line(&line_light, scene->planes + i);
			if (p.z != INFINITY && point_between(line_light.position, \
			l->position, p))
				return (1);
		}
	}
	return (0);
}

static int	inter_shad_sphere(t_scene *scene, void *obj, t_line_color *l, \
t_line line_light)
{
	int		i;
	t_point	p;

	i = -1;
	while (++i < scene->nb_spheres)
	{
		if (obj != scene->spheres + i)
		{
			p = intersection_sphere_line(&line_light, scene->spheres + i);
			if (p.z != INFINITY && point_between(line_light.position, \
			l->position, p))
				return (1);
		}
	}
	return (0);
}

static int	inter_shad_cylinder(t_scene *scene, void *obj, t_line_color *l, \
t_line line_light)
{
	int		i;
	t_point	p;

	i = -1;
	while (++i < scene->nb_cylinders)
	{
		if (obj != scene->cylinders + i)
		{
			p = intersection_cylinder_line_shadow(&line_light, \
			scene->cylinders + i);
			if (p.z != INFINITY && point_between(line_light.position, \
			l->position, p))
				return (1);
		}
	}
	return (0);
}

void	*get_closest_obj(t_line *line, t_scene *scene, t_line_color *l)
{
	void	*plan;
	void	*sphere;
	void	*cylinder;

	if (scene->nb_planes > 0)
		plan = get_closest_plan(line, scene, l);
	if (scene->nb_spheres > 0)
		sphere = get_closest_sphere(line, scene, l);
	if (scene->nb_cylinders > 0)
		cylinder = get_closest_cylinder(line, scene, l);
	if (l->type == PLANE)
		return (plan);
	if (l->type == SPHERE)
		return (sphere);
	if (l->type == CYLINDER)
		return (cylinder);
	return (NULL);
}

int	intersection_obj_line(t_scene *scene, void *obj, t_line_color *l, \
t_line *line)
{
	t_line	line_light;

	line_light = get_line_2point(&scene->lights[0].position, &l->position);
	if (inter_shad_plane(scene, obj, l, line_light) || inter_shad_sphere(scene \
	, obj, l, line_light) || inter_shad_cylinder(scene, obj, l, line_light))
		return (1);
	if (l->position.z != INFINITY)
	{
		if (l->type == PLANE)
		{
			l->scalar_light_obj = scalar_product(line_light.vector, l->vector);
			if ((l->scalar_light_obj < 0 && scalar_product(line->vector, \
			l->vector) > 0) || (l->scalar_light_obj > 0 && scalar_product(\
			line->vector, l->vector) < 0))
				return (1);
		}
		if (l->type == SPHERE || l->type == CYLINDER)
		{
			l->scalar_light_obj = scalar_product(get_line_2point(&l->position, \
			&scene->lights[0].position).vector, l->vector);
			if (l->scalar_light_obj < 0)
				return (1);
		}
	}
	return (0);
}
