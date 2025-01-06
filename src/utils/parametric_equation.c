/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parametric_equation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:36:03 by sabitbol          #+#    #+#             */
/*   Updated: 2025/01/06 13:22:08 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <math.h>

t_point	parametric_equation(t_line l, float t)
{
	t_point	p;

	if (t == INFINITY)
	{
		p.x = 0;
		p.y = 0;
		p.z = INFINITY;
		return (p);
	}
	p.x = l.position.x + t * l.vector.x;
	p.y = l.position.y + t * l.vector.y;
	p.z = l.position.z + t * l.vector.z;
	return (p);
}
