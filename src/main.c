/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:24:17 by rperrot           #+#    #+#             */
/*   Updated: 2024/10/16 01:13:41 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "error.h"
#include "parsing.h"
void print_scene(t_scene scene);

int main(int argc, char **argv)
{
	int fd;

	errno = 0;
	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, E_NB_ARGS);
		return (1);
	}
	fd = check_file(argv[1]);
	if (fd == -1)
		return (1);
	t_scene oui = readline(fd);
	if (!errno)
	 	print_scene(oui);
	else
		return (1);
	return (0);
}

void print_scene(t_scene scene)
{
	printf("Ambient light:\n");
	printf("Intensity: %f\n", scene.ambient.intensity);
	printf("Color: %d %d %d\n", scene.ambient.color.r, scene.ambient.color.g, scene.ambient.color.b);
	printf("Camera:\n");
	printf("Position: %f %f %f\n", scene.cameras.position.x, scene.cameras.position.y, scene.cameras.position.z);
	printf("Orientation: %f %f %f\n", scene.cameras.vector.x, scene.cameras.vector.y, scene.cameras.vector.z);
	printf("Fov: %f\n", scene.cameras.fov);
}