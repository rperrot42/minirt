/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:55:59 by rperrot           #+#    #+#             */
/*   Updated: 2025/01/11 15:55:59 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "include.h"
#include "move.h"
#include "utils.h"

static void	rotate_point(t_point *p, double rotation, t_coordinate rotate)
{
	if (rotate == X)
	{
		p->y = cosf(rotation) * p->y - sinf(rotation) * p->z;
		p->z = sinf(rotation) * p->y + cosf(rotation) * p->z;
	}
	else if (rotate == Y)
	{
		p->x = cosf(rotation) * p->x + sinf(rotation) * p->z;
		p->z = -sinf(rotation) * p->x + cosf(rotation) * p->z;
	}
}

void	rotation_obj(t_scene *scene, double rotation, t_coordinate rotate)
{
	int		i;

	i = -1;
	while (++i < scene->nb_planes)
	{
		rotate_point(&scene->planes[i].p, rotation, rotate);
		rotate_point(&scene->planes[i].vector, rotation, rotate);
		scene->planes[i].d = (scene->planes[i].vector.x * scene->planes[i].p.x \
		+ scene->planes[i].vector.y * scene->planes[i].p.y + \
				scene->planes[i].vector.z * scene->planes[i].p.z) * -1;
	}
	i = -1;
	while (++i < scene->nb_cylinders)
	{
		rotate_point(&scene->cylinders[i].position, rotation, rotate);
		rotate_point(&scene->cylinders[i].vector, rotation, rotate);
		unit_vector(&scene->cylinders[i].vector);
	}
	i = -1;
	while (++i < scene->nb_lights)
		rotate_point(&scene->lights[i].position, rotation, rotate);
	i = -1;
	while (++i < scene->nb_spheres)
		rotate_point(&scene->spheres[i].position, rotation, rotate);
}
