/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:35:25 by rperrot           #+#    #+#             */
/*   Updated: 2024/11/24 23:39:23 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collison.h"
#include <math.h>

t_point intersection_plane_line(t_line *line, t_plane *plane)
{
	float t;
	t_point point;

	t = -plane->d / (plane->vector.x * line->vector.x + plane->vector.y * line->vector.y + plane->vector.z * line->vector.z);
	if (fabs(t) < 1e-6)
			return (t_point){0, 0, -1};
	point.x = line->vector.x * t;
	point.y = line->vector.y * t;
	point.z = line->vector.z * t;
	return (point);
}