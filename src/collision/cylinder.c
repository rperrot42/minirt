/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:44:52 by sabitbol          #+#    #+#             */
/*   Updated: 2025/01/02 15:30:12 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collison.h"
#include "angle.h"
#include <math.h>

// static int	out_of_ends(t_line *line, t_cylinder *cylinder)
// {
// 	t_point	c1;
// 	t_point	c2;

// 	c1.x = cylinder->position.x - cylinder->vector.x * (cylinder->height / 2);
// 	c1.y = cylinder->position.y - cylinder->vector.y * (cylinder->height / 2);
// 	c1.z = cylinder->position.z - cylinder->vector.z * (cylinder->height / 2);

// 	c2.x = cylinder->position.x + cylinder->vector.x * (cylinder->height / 2);
// 	c2.y = cylinder->position.y + cylinder->vector.y * (cylinder->height / 2);
// 	c2.z = cylinder->position.z + cylinder->vector.z * (cylinder->height / 2);

// 	// float	scalar_c1_ray = scalar_product(get_line_2point(&c1, &line->vector).vector, cylinder->vector);
// 	// float	scalar_c2_ray = scalar_product(get_line_2point(&c2, &line->vector).vector, cylinder->vector);
// 	// printf("scalar c1 :%f\n", scalar_c1_ray);
// 	// printf("scalar c2 :%f\n\n\n", scalar_c2_ray);
// 	if (scalar_c1_ray > 0 && scalar_c2_ray < 0)
// 		return (0);
// 	return (1);
// }



t_point	intersection_cylinder_line(t_line *line, t_cylinder *cylinder, int *is_cylinder_end)
{
	//--------------------------CYLINDRE INFINI-------------------------//
	t_point	Va = vectorial_product(cylinder->vector, line->vector);
	Va = vectorial_product(Va, cylinder->vector);

	t_point R0t;

	R0t.x = line->position.x - cylinder->position.x;
	R0t.y = line->position.y - cylinder->position.y;
	R0t.z = line->position.z - cylinder->position.z;

	t_point	Ra0 = vectorial_product(cylinder->vector, R0t);
	Ra0 = vectorial_product(Ra0, cylinder->vector);

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

	t_point	p;
	if (t1 <= t2 && t1 > 0)
		t2 = t1;
	p.x = line->position.x + t2 * line->vector.x;
	p.y = line->position.y + t2 * line->vector.y;
	p.z = line->position.z + t2 * line->vector.z;
//--------------------------CYLINDRE INFINI--------------------------------//

//--------------------------BOUT DU CYLINDRE-------------------------------//
	t_plane	d1;
	d1.vector = cylinder->vector;
	d1.p.x = cylinder->position.x + d1.vector.x * (cylinder->height / 2);
	d1.p.y = cylinder->position.y + d1.vector.y * (cylinder->height / 2);
	d1.p.z = cylinder->position.z + d1.vector.z * (cylinder->height / 2);
	d1.d = -(d1.p.x * d1.vector.x + d1.p.y * d1.vector.y + d1.p.z * d1.vector.z);

	t_plane d2;
	d2.vector.x = -cylinder->vector.x;
	d2.vector.y = -cylinder->vector.y;
	d2.vector.z = -cylinder->vector.z;
	d2.p.x = cylinder->position.x + d2.vector.x * (cylinder->height / 2);
	d2.p.y = cylinder->position.y + d2.vector.y * (cylinder->height / 2);
	d2.p.z = cylinder->position.z + d2.vector.z * (cylinder->height / 2);
	d2.d = -(d2.p.x * d2.vector.x + d2.p.y * d2.vector.y + d2.p.z * d2.vector.z);

	t_point	disk;
	
	if (d1.p.z < d2.p.z && d1.p.z > 0)
	{
		disk = intersection_plane_line(line, &d1);
		if (disk.z != INFINITY && calc_norm(get_line_2point(&disk, &d1.p).vector) < cylinder->radius)
		{
			*is_cylinder_end = 1;
			return (disk);
		}
	}
	else if (d2.p.z < d1.p.z && d2.p.z > 0)
	{
		disk = intersection_plane_line(line, &d2);
		if (disk.z != INFINITY && calc_norm(get_line_2point(&disk, &d2.p).vector) < cylinder->radius)
		{
			*is_cylinder_end = 2;
			return (disk);
		}
	}
	//--------------------------BOUT DU CYLINDRE-------------------------------//

	//--------------------------CYLINDRE FINI----------------------------------//
	t_line	end;

	end.position.x = cylinder->position.x - cylinder->vector.x * (cylinder->height / 2);
	end.position.y = cylinder->position.y - cylinder->vector.y * (cylinder->height / 2);
	end.position.z = cylinder->position.z - cylinder->vector.z * (cylinder->height / 2);
	end = get_line_2point(&end.position, &cylinder->position);

	float	d = sqrt((end.vector.x * end.vector.x + end.vector.y * end.vector.y + end.vector.z * end.vector.z) + cylinder->radius * cylinder->radius);
	t_line	Vci = get_line_2point(&p, &cylinder->position);

	if (d < calc_norm(Vci.vector))
	{
		t_point p;
		p.x = 0;
		p.y = 0;
		p.z = INFINITY;
		return (p);
	}
	//--------------------------CYLINDRE FINI----------------------------------//
	*is_cylinder_end = 0;
	return (p);
}

t_cylinder    *get_closest_cylinder(t_line *line, t_scene *scene, t_line_color *l)
{
    t_cylinder *obj;
    t_point p_temp;
    int     i;
	int		cylinder_end = 0;

    i = -1;
    obj = scene->cylinders;
	if (line->vector.z == 0)
		line->vector.z = 1e-4;
    while (++i < scene->nb_cylinders)
    {
        p_temp = intersection_cylinder_line(line, scene->cylinders + i, &cylinder_end);
		// printf("%i yeee\n", cylinder_end);
		// if (cylinder_end == 2)
		// 	printf("yolo");
		// if (p_temp.z != INFINITY)
		// {
		// 	printf("cylinder_end :%d\n", cylinder_end);
		// 	printf("p_temp.z :%f\n", p_temp.z);
		// 	printf("l.position.z :%f\n", l->position.z);
		// }
        if (p_temp.z < l->position.z && p_temp.z > 0)
        {
            obj = scene->cylinders + i;
            l->position = p_temp;
			l->type = CYLINDER;
			l->is_cylinder_end = cylinder_end;
        }
    }
	if (l->position.z != INFINITY && l->type == CYLINDER)
    {
        l->color = obj->color;
		if (l->is_cylinder_end == 0)
		{
			t_point	Vop;

			Vop.x = l->position.x - obj->position.x;
			Vop.y = l->position.y - obj->position.y;
			Vop.z = l->position.z - obj->position.z;

			float	d = sqrt((Vop.x * Vop.x + Vop.y * Vop.y + Vop.z * Vop.z) - obj->radius * obj->radius);

			t_point	c;
			c.x = obj->position.x + d * obj->vector.x;
			c.y = obj->position.y + d * obj->vector.y;
			c.z = obj->position.z + d * obj->vector.z;
			l->vector = get_line_2point(&c, &l->position).vector;
		}
		else if (l->is_cylinder_end == 1)
			l->vector = obj->vector;
		else if (l->is_cylinder_end == 2)
		{
			l->vector.x = -obj->vector.x;
			l->vector.y = -obj->vector.y;
			l->vector.z = -obj->vector.z;
		}
    }
    return (obj);
}
