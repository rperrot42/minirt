/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_angle_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:44:50 by sabitbol          #+#    #+#             */
/*   Updated: 2024/10/25 18:42:16 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <math.h>

float   get_angle_plan(t_point p, t_point q, t_plane *plan)
{
    return (acos((q.x - p.x) * plan->vector.x + (q.y - p.y) * plan->vector.y + (q.z - p.z) * plan->vector.z / \
    sqrt((q.x - p.x) * (q.x - p.x) + (q.y - p.y) * (q.y - p.y) + (q.z - p.z) * (q.z - p.z)) * \
    sqrt(plan->vector.x * plan->vector.x + plan->vector.y * plan->vector.y + plan->vector.z * plan->vector.z)));
}

// angle = arcos( PQ⋅plan / ∥PQ∥⋅∥plan∥ )
// return (angle);