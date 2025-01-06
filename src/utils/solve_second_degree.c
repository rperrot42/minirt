/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_second_degree.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:30:53 by rperrot           #+#    #+#             */
/*   Updated: 2025/01/06 13:07:56 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "struct.h"

t_second_degree solve_second_degre(float a, float b, float c)
{
	float			delta;
	t_second_degree result;

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return ((t_second_degree){INFINITY, INFINITY});
	if (delta == 0)
	{
		result.x1 = -b / (2 * a);
		result.x2 = INFINITY;
		return (result);
	}
	result.x1 = (-b - sqrt(delta)) / (2 * a);
	result.x2 = (-b + sqrt(delta)) / (2 * a);
	return (result);
}

float	second_degree_equation(float a, float b, float c)
{
	float			delta;
	t_second_degree result;

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (INFINITY);
	if (delta == 0)
		return (-b / (2 * a));
	result.x1 = (-b - sqrt(delta)) / (2 * a);
	result.x2 = (-b + sqrt(delta)) / (2 * a);
	if (result.x1 < result.x2)
		return (result.x1);
	return (result.x2);
}
