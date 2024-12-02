/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:24:17 by rperrot           #+#    #+#             */
/*   Updated: 2024/12/02 15:59:36 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "parsing.h"
#include "mini_rt.h"
#include "init.h"
#include "utils.h"

void	print_scene(t_scene s);

int	main(int argc, char **argv)
{
	int		fd;
	int		return_value;
	t_scene	scene;

	errno = 0;
	scene = (t_scene){0};
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

void print_scene(t_scene s)
{
	printf("-------- Ambient light: ------\n");
	printf(" -Intensity: %f\n", s.ambient.intensity);
	printf(" -Color: %d %d %d\n", s.ambient.color.r, s.ambient.color.g, s.ambient.color.b);
	printf(" -------- Camera: --------\n");
	printf(" -Position: %f %f %f\n", s.cameras.position.x, s.cameras.position.y, s.cameras.position.z);
	printf(" -Orientation: %f %f %f\n", s.cameras.vector.x, s.cameras.vector.y, s.cameras.vector.z);
	printf(" -Fov: %f\n", s.cameras.fov);
	printf (" \n------- lights -----------\n\n");
	for (int i = 0; i < s.nb_lights; i++)
	{
		printf("Light [%d]:\n", i + 1);
		printf(" -Position: %f %f %f\n", s.lights[i].position.x, s.lights[i].position.y, s.lights[i].position.z);
		printf(" -Intensity: %f\n", s.lights[i].intensity);
		printf(" -Color: %d %d %d\n", s.lights[i].color.r, s.lights[i].color.g, s.lights[i].color.b);
	}
	printf (" \n------- cylindre -----------\n\n");
	for (int i = 0; i < s.nb_cylinders; i++)
	{
		printf("cylindre [%d]:\n", i + 1);
		printf(" -Position: %f %f %f\n", s.cylinders[i].position.x,s.cylinders[i].position.y, s.cylinders[i].position.z);
		printf(" -diametre: %f\n", s.cylinders[i].diameter);
		printf(" -Color: %d %d %d\n",s.cylinders[i].color.r,s.cylinders[i].color.g,s.cylinders[i].color.b);
		printf(" -Direction: %f %f %f\n", s.cylinders[i].vector.x,s.cylinders[i].vector.y,s.cylinders[i].vector.z);
		printf(" -Height: %f\n", s.cylinders[i].height);
	}
	printf (" \n------- planes -----------\n\n");

	for (int i = 0; i < s.nb_planes; i++)
	{
		printf("planes [%d]:\n", i + 1);
		printf(" -d value: %f\n", s.planes[i].d);
		printf(" -vector: %f %f %f\n",s.planes[i].vector.x,s.planes[i].vector.y,s.planes[i].vector.z);
		printf(" -Color: %d %d %d\n",s.planes[i].color.r,s.planes[i].color.g,s.planes[i].color.b);
	}
	printf (" \n------- spheres -----------\n\n");
	for (int i = 0; i < s.nb_spheres; i++)
	{
		printf("Spheres [%d]:\n", i + 1);
		printf(" -position: %f %f %f\n", s.spheres[i].position.x,s.spheres[i].position.y,s.spheres[i].position.z);
		printf(" -radius: %f\n",s.spheres[i].radius);
		printf(" -Color: %d %d %d\n",s.spheres[i].color.r,s.spheres[i].color.g,s.spheres[i].color.b);
	}
}
