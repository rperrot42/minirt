/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:44:52 by sabitbol          #+#    #+#             */
/*   Updated: 2024/12/10 13:25:38 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collison.h"
#include "angle.h"
#include <math.h>

t_point	intersection_cylinder_line(t_line *line, t_cylinder *cylinder)
{
	t_point	Va;

	Va.x = cylinder->vector.y * line->vector.z - cylinder->vector.z * line->vector.y;
	Va.y = cylinder->vector.z * line->vector.x - cylinder->vector.x * line->vector.z;
	Va.z = cylinder->vector.x * line->vector.y - cylinder->vector.y * line->vector.x;

	t_point	R0t;

	R0t.x = line->position.x - cylinder->position.x;
	R0t.y = line->position.y - cylinder->position.y;
	R0t.z = line->position.z - cylinder->position.z;

	t_point	Ra0;

	Ra0.x = cylinder->vector.y * R0t.z - cylinder->vector.z * R0t.y;
	Ra0.y = cylinder->vector.z * R0t.x - cylinder->vector.x * R0t.z;
	Ra0.z = cylinder->vector.x * R0t.y - cylinder->vector.y * R0t.x;
	// Ra0.x = cylinder->vector.x * cylinder->vector.x * (line->position.x - cylinder->position.x);
	// Ra0.y = cylinder->vector.y * cylinder->vector.y * (line->position.y - cylinder->position.y);
	// Ra0.z = cylinder->vector.z * cylinder->vector.z * (line->position.z - cylinder->position.z);

	float	A = Va.x * Va.x + Va.y * Va.y + Va.z * Va.z;
	float	B = 2 * (Ra0.x * Va.x + Ra0.y * Va.y + Ra0.z * Va.z);
	float	C = Ra0.x * Ra0.x + Ra0.y * Ra0.y + Ra0.z * Ra0.z - cylinder->radius * cylinder->radius;

	float	b4ac = B * B - 4 * A * C;
	if (b4ac < 0)
	{
		t_point p;
		p.x = 0;
		p.y = 0;
		p.z = INFINITY;
		return (p);
	}
	float	t1 = (-B - sqrt(b4ac)) / (2 * A);
	float	t2 = (-B + sqrt(b4ac)) / (2 * A);

	t_point	p1;
	t_point	p2;

	if (t1 <= t2 && t1 > 0)
	{
		p1.x = line->position.x + t1 * line->vector.x;
		p1.y = line->position.y + t1 * line->vector.y;
		p1.z = line->position.z + t1 * line->vector.z;
		return (p1);
	}
	p2.x = line->position.x + t2 * line->vector.x;
	p2.y = line->position.y + t2 * line->vector.y;
	p2.z = line->position.z + t2 * line->vector.z;
	return (p2);
}

t_cylinder    *get_closest_cylinder(t_line *line, t_scene *scene, t_line_color *l)
{
    t_cylinder *obj;
    t_point p_temp;
    int     i;

    i = -1;
    obj = scene->cylinders;
	if (line->vector.z == 0)
		line->vector.z = 1e-4;
    while (++i < scene->nb_cylinders)
    {
        p_temp = intersection_cylinder_line(line, scene->cylinders + i);
        if (p_temp.z < l->position.z && p_temp.z > 0)
        {
            obj = scene->cylinders + i;
            l->position = p_temp;
			l->type = CYLINDER;
        }
    }
	if (l->position.z != INFINITY && l->type == CYLINDER)
    {
        l->color = obj->color;

		t_point	Vop;

		Vop.x = l->position.x - obj->position.x;
		Vop.y = l->position.y - obj->position.y;
		Vop.z = l->position.z - obj->position.z;

		float	d = sqrt((Vop.x * Vop.x + Vop.y * Vop.y + Vop.z * Vop.z) - obj->radius * obj->radius);

		t_point	c;
		float	n = calc_norm(obj->vector);
		c.x = obj->position.x + d * (obj->vector.x / n);
		c.y = obj->position.y + d * (obj->vector.y / n);
		c.z = obj->position.z + d * (obj->vector.z / n);
		l->vector = get_line_2point(&c, &l->position).vector;
    }
    return (obj);
}
