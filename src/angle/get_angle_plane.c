/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_angle_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:44:50 by sabitbol          #+#    #+#             */
/*   Updated: 2024/11/24 18:25:10 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <math.h>

float get_angle_plan(t_line l, t_plane *plan, float dot_product)
{
    float   norm_pq = sqrt(l.vector.x * l.vector.x + l.vector.y * l.vector.y + l.vector.z * l.vector.z);
    float   norm_plan = sqrt(plan->vector.x * plan->vector.x + plan->vector.y * plan->vector.y + plan->vector.z * plan->vector.z);

    return (acos(dot_product / (norm_pq * norm_plan)));
}

// angle = arcos( PQ⋅plan / ∥PQ∥⋅∥plan∥ )
// return (angle);