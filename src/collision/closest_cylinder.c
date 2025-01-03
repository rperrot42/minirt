/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:45:13 by sabitbol          #+#    #+#             */
/*   Updated: 2025/01/03 17:00:28 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collison.h"
#include "angle.h"
#include <math.h>

static void	set_line_light(t_line_color *l, t_cylinder *obj);
static void	calc_vector(t_line_color *l, t_cylinder *obj);

t_cylinder	*get_closest_cylinder(t_line *line, t_scene *scene, t_line_color *l)
{
	t_cylinder	*obj;
	t_point		p_temp;
	int			i;
	int			cylinder_end;

	i = -1;
	cylinder_end = 0;
	obj = scene->cylinders;
	if (line->vector.z == 0)
		line->vector.z = 1e-4;
	while (++i < scene->nb_cylinders)
	{
		p_temp = intersection_cylinder_line(line, scene->cylinders + i, \
		&cylinder_end);
		if (p_temp.z < l->position.z && p_temp.z > 0)
		{
			obj = scene->cylinders + i;
			l->position = p_temp;
			l->type = CYLINDER;
			l->cylinder_end = cylinder_end;
		}
	}
	if (l->position.z != INFINITY && l->type == CYLINDER)
		set_line_light(l, obj);
	return (obj);
}

static void	set_line_light(t_line_color *l, t_cylinder *obj)
{
	l->color = obj->color;
	if (l->cylinder_end == 0)
		calc_vector(l, obj);
	else if (l->cylinder_end == 1)
		l->vector = obj->vector;
	else if (l->cylinder_end == 2)
	{
		l->vector.x = -obj->vector.x;
		l->vector.y = -obj->vector.y;
		l->vector.z = -obj->vector.z;
	}
}

static void	calc_vector(t_line_color *l, t_cylinder *obj)
{
	t_point	vop;
	float	d;
	t_point	c;
	float	temp_res;

	vop = get_line_2point(&obj->position, &l->position).vector;
	temp_res = (vop.x * vop.x + vop.y * vop.y + vop.z * vop.z) \
	- obj->radius * obj->radius;
	if (temp_res <= 0)
		d = 0;
	else if (scalar_product(get_line_2point(&l->position, \
	&obj->position).vector, obj->vector) < 0)
		d = sqrt(temp_res);
	else
		d = -sqrt(temp_res);
	c.x = obj->position.x + d * obj->vector.x;
	c.y = obj->position.y + d * obj->vector.y;
	c.z = obj->position.z + d * obj->vector.z;
	l->vector = get_line_2point(&c, &l->position).vector;
}
