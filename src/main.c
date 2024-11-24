/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:24:17 by rperrot           #+#    #+#             */
/*   Updated: 2024/11/24 16:27:02 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "parsing.h"
#include "mini_rt.h"
#include "init.h"
#include "draw.h"

void	print_scene(t_scene scene);

int	main(int argc, char **argv)
{
	int		fd;
	int		return_value;
	t_scene	scene;

	errno = 0;
	if (argc != 2)
		return print_error(E_NB_ARGS);
	fd = check_file(argv[1]);
	if (fd == -1)
		return (1);
	return_value = ft_readline(fd, &scene);
	if (init_window(&scene))
		return (1);
	if (!return_value)
		hooking(&scene);
	else
	{
		free_scene(&scene);
		return (1);
	}
	free_scene(&scene);
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
		printf(" -Intensity: %f\n", scene.lights[i].intensity);
		printf(" -Color: %d %d %d\n", scene.lights[i].color.r, scene.lights[i].color.g, scene.lights[i].color.b);
	}
	printf (" \n------- cylindre -----------\n\n");
	for (int i = 0; i < scene.nb_cylinders; i++)
	{
		printf("cylindre [%d]:\n", i + 1);
		printf(" -Position: %f %f %f\n", scene.cylinders[i].position.x,scene.cylinders[i].position.y, scene.cylinders[i].position.z);
		printf(" -diametre: %f\n", scene.cylinders[i].diameter);
		printf(" -Color: %d %d %d\n",scene.cylinders[i].color.r,scene.cylinders[i].color.g,scene.cylinders[i].color.b);
		printf(" -Direction: %f %f %f\n", scene.cylinders[i].vector.x,scene.cylinders[i].vector.y,scene.cylinders[i].vector.z);
		printf(" -Height: %f\n", scene.cylinders[i].height);
	}
	printf (" \n------- planes -----------\n\n");

	for (int i = 0; i < scene.nb_planes; i++)
	{
		printf("planes [%d]:\n", i + 1);
		printf(" -d value: %f\n", scene.planes[i].d);
		printf(" -vector: %f %f %f\n",scene.planes[i].vector.x,scene.planes[i].vector.y,scene.planes[i].vector.z);
		printf(" -Color: %d %d %d\n",scene.planes[i].color.r,scene.planes[i].color.g,scene.planes[i].color.b);
	}
	printf (" \n------- spheres -----------\n\n");
	for (int i = 0; i < scene.nb_spheres; i++)
	{
		printf("Spheres [%d]:\n", i + 1);
		printf(" -position: %f %f %f\n", scene.spheres[i].position.x,scene.spheres[i].position.y,scene.spheres[i].position.z);
		printf(" -radius: %f\n",scene.spheres[i].radius);
		printf(" -Color: %d %d %d\n",scene.spheres[i].color.r,scene.spheres[i].color.g,scene.spheres[i].color.b);
	}
	printf("oui.nb_planes = %d\n", scene.nb_planes);
}
