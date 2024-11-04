/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:28:18 by rperrot           #+#    #+#             */
/*   Updated: 2024/11/02 16:12:03 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "include.h"
#include "struct.h"
#include "mlx.h"
#include "init.h"

int	free_scene(t_scene *scene)
{
	if (scene->cylinders)
		free(scene->cylinders);
	if (scene->planes)
		free(scene->planes);
	if (scene->spheres)
		free(scene->spheres);
	if (scene->lights)
		free(scene->lights);
	if (scene->img.img)
		mlx_destroy_image(scene->mlx, scene->img.img);
	if (scene->window)
		mlx_destroy_window(scene->mlx, scene->window);
	if (scene->mlx)
	{
		mlx_destroy_display(scene->mlx);
		free(scene->mlx);
	}
	exit(0);
}
