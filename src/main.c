/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:24:17 by rperrot           #+#    #+#             */
/*   Updated: 2024/10/16 21:00:06 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "error.h"
#include "parsing.h"

void print_scene(t_scene scene);

int main(int argc, char **argv)
{
	int fd;
	t_scene oui;
	errno = 0;
	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, E_NB_ARGS);
		return (1);
	}
	fd = check_file(argv[1]);
	if (fd == -1)
		return (1);
	int return_value = ft_readline(fd, &oui);
	if (!return_value)
	 	print_scene(oui);
	else
		return (1);
	return (0);
}

void print_scene(t_scene scene)
{

	printf("-------- Ambient light: ------\n");
	printf(" -Intensity: %f\n", scene.ambient.intensity);
	printf(" -Color: %d %d %d\n", scene.ambient.color.r, scene.ambient.color.g, scene.ambient.color.b);
	printf(" -------- Camera: --------\n");
	printf(" -Position: %f %f %f\n", scene.cameras.position.x, scene.cameras.position.y, scene.cameras.position.z);
	printf(" -Orientation: %f %f %f\n", scene.cameras.vector.x, scene.cameras.vector.y, scene.cameras.vector.z);
	printf(" -Fov: %f\n", scene.cameras.fov);
	printf (" \n------- lights -----------\n\n");
	for (int i = 0; i < scene.nb_lights; i++)
	{
		printf("Light [%d]:\n", i + 1);
		printf(" -Position: %f %f %f\n", scene.lights[i].position.x, scene.lights[i].position.y, scene.lights[i].position.z);
		printf(" -Intensity: %f\n", scene.lights[i].ratio);
		printf(" -Color: %d %d %d\n", scene.lights[i].color.r, scene.lights[i].color.g, scene.lights[i].color.b);
	}
	printf (" \n------- cylindre -----------\n\n");
	for (int i = 0; i < scene.nb_cylinders; i++)
	{
		printf("cylindre [%d]:\n", i + 1);
		printf(" -Position: %f %f %f\n", scene.cylinders[i].origin.x,scene.cylinders[i].origin.y, scene.cylinders[i].origin.z);
		printf(" -diametre: %f\n", scene.cylinders[i].diameter);
		printf(" -Color: %d %d %d\n",scene.cylinders[i].color.r,scene.cylinders[i].color.g,scene.cylinders[i].color.b);
		printf(" -Direction: %f %f %f\n", scene.cylinders[i].direction.x,scene.cylinders[i].direction.y,scene.cylinders[i].direction.z);
		printf(" -Height: %f\n", scene.cylinders[i].height);
	}
	printf (" \n------- planes -----------\n\n");

	for (int i = 0; i < scene.nb_planes; i++)
	{
		printf("planes [%d]:\n", i + 1);
		printf(" -Position: %f %f %f\n", scene.planes[i].point.x,scene.planes[i].point.y,scene.planes[i].point.z);
		printf(" -vector: %f %f %f\n",scene.planes[i].vector.x,scene.planes[i].vector.y,scene.planes[i].vector.z);
		printf(" -Color: %d %d %d\n",scene.planes[i].color.r,scene.planes[i].color.g,scene.planes[i].color.b);
	}
	printf (" \n------- spheres -----------\n\n");
	for (int i = 0; i < scene.nb_spheres; i++)
	{
		printf("Spheres [%d]:\n", i + 1);
		printf(" -center: %f %f %f\n", scene.spheres[i].center.x,scene.spheres[i].center.y,scene.spheres[i].center.z);
		printf(" -radius: %f\n",scene.spheres[i].radius);
		printf(" -Color: %d %d %d\n",scene.spheres[i].color.r,scene.spheres[i].color.g,scene.spheres[i].color.b);
	}
	printf("oui.nb_planes = %d\n", scene.nb_planes);
}
