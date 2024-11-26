/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:51:09 by sabitbol          #+#    #+#             */
/*   Updated: 2024/11/26 12:01:51 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <math.h>

t_line	get_line_2point(t_point *a, t_point *b)
{
	t_line line;

	line.vector.x = b->x - a->x;
	line.vector.y = b->y - a->y;
	line.vector.z = b->z - a->z;
	line.position = *a;
	return (line);
}
