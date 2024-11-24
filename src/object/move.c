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

#include "move.h"

void	move_plane(t_scene *scene, int x, int y, int z)
{
	int i;

	i = -1;
	while (++i < scene->nb_planes)
	{
		scene->planes[i].d += x * scene->planes[i].vector.x + y * scene->planes[i].vector.y + z * scene->planes[i].vector.z;
	}
}