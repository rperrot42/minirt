/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_in_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:59:24 by sabitbol          #+#    #+#             */
/*   Updated: 2025/01/12 13:36:11 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "angle.h"
#include <math.h>

#include "stdio.h"

int	point_in_sphere(t_sphere *sphere, t_point *q);
int	point_in_cylinder(t_cylinder *cylinder, t_point *q);

int	point_in_obj(t_scene *scene, t_point *q)
{
	int	i;

	i = 0;
	while (i < scene->nb_spheres)
	{
		if (point_in_sphere(scene->spheres + i, q))
			return (1);
		i++;
	}
	i = 0;
	while (i < scene->nb_cylinders)
	{
		if (point_in_cylinder(scene->cylinders + i, q)){
			return (1);
		}
		i++;
	}
	return (0);
}

int	point_in_sphere(t_sphere *sphere, t_point *q)
{
	if (calc_norm(get_line_2point(q, &sphere->position).vector) < sphere->radius)
		return (1);
	return (0);
}


int	point_in_cylinder(t_cylinder *cylinder, t_point *q)
{
	float	hypot;
	float	alpha;
	float	length;
	t_point	p;

	hypot = calc_norm(get_line_2point(q, &cylinder->position).vector);
	if (hypot == 0)
		return (1);
	alpha = scalar_product(cylinder->vector, get_line_2point(q, &cylinder->position).vector);		
	printf("alpha:%f\n", alpha);
	length = alpha * hypot;
	p.x = cylinder->position.x + cylinder->vector.x * length;
	p.y = cylinder->position.y + cylinder->vector.y * length;
	p.z = cylinder->position.z + cylinder->vector.z * length;
	printf("hauteur:%f | %f\n", calc_norm(get_line_2point(&p, &cylinder->position).vector), cylinder->height / 2);
	printf("largeur:%f | %f\n", sqrt(hypot * hypot - length * length), cylinder->radius);
	if (calc_norm(get_line_2point(&p, &cylinder->position).vector) < cylinder->height / 2 && sqrt(hypot * hypot - length * length) < cylinder->radius)
		return (1);
	return (0);
}
