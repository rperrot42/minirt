/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:28:18 by rperrot           #+#    #+#             */
/*   Updated: 2024/10/16 21:28:22 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include "struct.h"

void	free_scene(t_scene *scene)
{
	if (scene)
	{
		free(scene->cylinders);
		free(scene->planes);
		free(scene->spheres);
		free(scene->lights);
	}
}
