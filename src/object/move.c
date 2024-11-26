/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:05:20 by rperrot           #+#    #+#             */
/*   Updated: 2024/11/24 20:05:20 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "move.h"

void	move_plane(t_scene *scene, int x, int y, int z)
{
	int i;

	i = -1;
	while (++i < scene->nb_planes)
	{
		scene->planes[i].p.x += x;
		scene->planes[i].p.y += y;
		scene->planes[i].p.z += z;
		scene->planes[i].d += x * scene->planes[i].vector.x + y * scene->planes[i].vector.y + z * scene->planes[i].vector.z;
	}
	i = -1;
	while (++i < scene->nb_lights)
	{
		scene->lights[i].position.x -= x;
		scene->lights[i].position.y -= y;
		scene->lights[i].position.z -= z;
	}
}