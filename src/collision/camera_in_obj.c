/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_in_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:59:24 by sabitbol          #+#    #+#             */
/*   Updated: 2025/01/11 19:39:43 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "angle.h"
#include <math.h>

#include "stdio.h"

int	camera_in_sphere(t_scene *scene, t_sphere *sphere);
int	camera_in_cylinder(t_scene *scene, t_cylinder *cylinder);

int	camera_in_obj(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < scene->nb_spheres)
	{
		if (camera_in_sphere(scene, scene->spheres + i))
			return (1);
		i++;
	}
	i = 0;
	while (i < scene->nb_cylinders)
	{
		if (camera_in_cylinder(scene, scene->cylinders + i)){
			printf("ouistiti\n");return (1);}
		i++;
	}
	return (0);
}

int	camera_in_sphere(t_scene *scene, t_sphere *sphere)
{
	if (calc_norm(get_line_2point(&scene->cameras.position, &sphere->position).vector) < sphere->radius)
		return (1);
	return (0);
}


int	camera_in_cylinder(t_scene *scene, t_cylinder *cylinder)
{
	float	hypot;
	float	alpha;
	float	length;
	t_point	p;

	hypot = calc_norm(get_line_2point(&scene->cameras.position, &cylinder->position).vector);
	if (hypot == 0)
		return (1);
	alpha = scalar_product(cylinder->vector, get_line_2point(&scene->cameras.position, &cylinder->position).vector);
	length = alpha * hypot;
	p.x = cylinder->position.x + cylinder->vector.x * length;
	p.y = cylinder->position.y + cylinder->vector.y * length;
	p.z = cylinder->position.z + cylinder->vector.z * length;
	if (calc_norm(get_line_2point(&p, &cylinder->position).vector) > cylinder->height / 2)
		return (1);
	if (sqrt(hypot * hypot - length * length) > cylinder->radius)
		return (1);
	return (0);
}
