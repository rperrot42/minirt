/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:51:09 by sabitbol          #+#    #+#             */
/*   Updated: 2024/11/28 17:53:31 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <math.h>
#include "angle.h"

t_line	get_line_2point(t_point *a, t_point *b)
{
	t_line line;

	line.vector.x = b->x - a->x;
	line.vector.y = b->y - a->y;
	line.vector.z = b->z - a->z;
	line.position = *a;
	return (line);
}

int	point_between(t_point a, t_point b, t_point c)
{
	if (scalar_product(get_line_2point(&a, &b).vector, get_line_2point(&a, &c).vector) < 0)
		return (0);
	if (sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z)) < \
		sqrt((c.x - a.x) * (c.x - a.x) + (c.y - a.y) * (c.y - a.y) + (c.z - a.z) * (c.z - a.z)))
		return (0);
	return (1);
}

float	calc_norm(t_point v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}
