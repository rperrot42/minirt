/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:05:20 by rperrot           #+#    #+#             */
/*   Updated: 2025/01/06 17:09:26 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "move.h"

void	move_plane(t_scene *scene, int x, int y, int z)
{
	int	i;

	i = -1;
	while (++i < scene->nb_planes)
	{
		scene->planes[i].p.x -= x;
		scene->planes[i].p.y -= y;
		scene->planes[i].p.z -= z;
		scene->planes[i].d += x * scene->planes[i].vector.x + y * scene->planes[i].vector.y + z * scene->planes[i].vector.z;
	}
	i = -1;
	while (++i < scene->nb_lights)
	{
		scene->lights[i].position.x -= x;
		scene->lights[i].position.y -= y;
		scene->lights[i].position.z -= z;
	}
	i = -1;
	while (++i < scene->nb_spheres)
	{
		scene->spheres[i].position.x -= x;
		scene->spheres[i].position.y -= y;
		scene->spheres[i].position.z -= z;
	}
	i = -1;
	while (++i < scene->nb_cylinders)
	{
		scene->cylinders[i].position.x -= x;
		scene->cylinders[i].position.y -= y;
		scene->cylinders[i].position.z -= z;
	}
}

static void	translation(t_move move, t_scene *scene, int deplacement)
{
	if (move == LEFT || move == BACK)
		deplacement = -deplacement;
	if (move == LEFT || move == RIGHT)
		move_plane(scene, deplacement * cosf(scene->cameras.vector.x), \
	0, deplacement * sinf(scene->cameras.vector.x));
	else
		move_plane(scene, deplacement * sinf(scene->cameras.vector.x), \
	0, deplacement * cosf(scene->cameras.vector.x));
}

int	all_deplacement(t_scene *scene, int deplacement)
{
	if (scene->press_key.w_press == true)
		translation(FORWARD, scene, deplacement);
	if (scene->press_key.s_press == true)
		translation(BACK, scene, deplacement);
	if (scene->press_key.a_press == true)
		translation(LEFT, scene, deplacement);
	if (scene->press_key.d_press == true)
		translation(RIGHT, scene, deplacement);
	if (scene->press_key.sp_press == true)
		move_plane(scene, 0, deplacement, 0);
	if (scene->press_key.tab_press == true)
		move_plane(scene, 0, -deplacement, 0);
	return (0);
}
