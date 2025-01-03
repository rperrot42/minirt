/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parametric_equation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:36:03 by sabitbol          #+#    #+#             */
/*   Updated: 2025/01/03 11:40:32 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_point	parametric_equation(t_line l, float t)
{
	t_point	p;

	p.x = l.position.x + t * l.vector.x;
	p.y = l.position.y + t * l.vector.y;
	p.z = l.position.z + t * l.vector.z;
	return (p);
}
