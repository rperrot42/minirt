/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_second_degre.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:30:53 by rperrot           #+#    #+#             */
/*   Updated: 2024/12/02 18:32:04 by rperrot          ###   ########.fr       */
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
