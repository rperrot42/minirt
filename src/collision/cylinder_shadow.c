/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_shadow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:35:00 by sabitbol          #+#    #+#             */
/*   Updated: 2025/01/03 18:30:19 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collison.h"
#include "angle.h"
#include <math.h>
#include "utils.h"

static t_point	get_disk(t_line *line, t_cylinder *cylinder)
{
	t_plane	d;
	t_point	disk;

	d.vector = cylinder->vector;
	d.p.x = cylinder->position.x + d.vector.x * (cylinder->height / 2);
	d.p.y = cylinder->position.y + d.vector.y * (cylinder->height / 2);
	d.p.z = cylinder->position.z + d.vector.z * (cylinder->height / 2);
	d.d = -(d.p.x * d.vector.x + d.p.y * d.vector.y + d.p.z * d.vector.z);
	disk = intersection_plane_line(line, &d);
	if (disk.z != INFINITY && calc_norm(get_line_2point(&disk, &d.p).vector) <= \
	cylinder->radius)
		return (disk);
	d.vector.x = -cylinder->vector.x;
	d.vector.y = -cylinder->vector.y;
	d.vector.z = -cylinder->vector.z;
	d.p.x = cylinder->position.x + d.vector.x * (cylinder->height / 2);
	d.p.y = cylinder->position.y + d.vector.y * (cylinder->height / 2);
	d.p.z = cylinder->position.z + d.vector.z * (cylinder->height / 2);
	d.d = -(d.p.x * d.vector.x + d.p.y * d.vector.y + d.p.z * d.vector.z);
	disk = intersection_plane_line(line, &d);
	if (disk.z != INFINITY && calc_norm(get_line_2point(&disk, &d.p).vector) <= \
	cylinder->radius)
		return (disk);
	return (disk.z = INFINITY, disk);
}

t_point	intersection_cylinder_line_shadow(t_line *line, t_cylinder *cyl)
{
	t_point	p;
	t_point	va;
	t_point	ra0;
	t_point	disk;
	t_line	end;

	va = vectorial_product(vectorial_product(cyl->vector, line->vector), \
	cyl->vector);
	ra0 = vectorial_product(vectorial_product(cyl->vector, get_line_2point(\
	&cyl->position, &line->position).vector), cyl->vector);
	p = parametric_equation(*line, second_degree_equation(va.x * va.x + va.y * \
	va.y + va.z * va.z, 2 * (ra0.x * va.x + ra0.y * va.y + ra0.z * va.z), ra0.x \
	* ra0.x + ra0.y * ra0.y + ra0.z * ra0.z - cyl->radius * cyl->radius));
	disk = get_disk(line, cyl);
	if (disk.z != INFINITY)
		return (disk);
	end.position.x = cyl->position.x - cyl->vector.x * (cyl->height / 2);
	end.position.y = cyl->position.y - cyl->vector.y * (cyl->height / 2);
	end.position.z = cyl->position.z - cyl->vector.z * (cyl->height / 2);
	end = get_line_2point(&end.position, &cyl->position);
	if (sqrt((end.vector.x * end.vector.x + end.vector.y * end.vector.y + \
	end.vector.z * end.vector.z) + cyl->radius * cyl->radius) <= \
	calc_norm(get_line_2point(&p, &cyl->position).vector))
		return (p.z = INFINITY, p);
	return (p);
}
