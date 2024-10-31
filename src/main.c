/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:24:17 by rperrot           #+#    #+#             */
/*   Updated: 2024/10/25 16:40:25 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "error.h"
#include "parsing.h"
#include "collison.h"
#include "init.h"
#include "mini_rt.h"
#include "mlx.h"

void	print_scene(t_scene scene);

//int	main(int argc, char **argv)
//{
//	int		fd;
//	int		return_value;
//	t_scene	oui;
//
//	errno = 0;
//	if (argc != 2)
//		return print_error(E_NB_ARGS);
//	fd = check_file(argv[1]);
//	if (fd == -1)
//		return (1);
//	return_value = ft_readline(fd, &oui);
//	if (!return_value)
//		print_scene(oui);
//	else
//	{
//		free_scene(&oui);
//		return (1);
//	}
//	free_scene(&oui);
//	return (0);
//}

// int main(){
// 	t_new_plane plane;
// 	plane.vector.x  = 4;
// 	plane.vector.y= -1;
// 	plane.vector.z = 3;
// 	plane.d = 1;
// 	t_line line;
// 	line.vector.x = 4;
// 	line.vector.y = -1;
// 	line.vector.z = 3;
// 	line.position.x = -5;
// 	line.position.y = -1;
// 	line.position.z = 0;
// 	t_point point =  intersection_plane_line(&line, &plane);
// 	printf("%f %f %f\n", point.x, point.y, point.z);
// }

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	close_win(int keycode, t_scene *scene)
{
	if (keycode == 65307)
	{
		free_scene(scene);
		exit(0);
	}
	return (0);
}


int	main(int argc, char **argv)
{
	t_scene	scene;
	int		fd;

	if (argc != 2)
		return (print_error(E_NB_ARGS));
	fd = check_file(argv[1]);
	if (fd == -1)
		return (1);
	if (ft_readline(fd, &scene) || init_window(&scene))
	{
		free_scene(&scene);
		return (2);
	}
	print_scene(scene);
	t_new_plane	plan;
	t_line line;
	t_point p;
	float fov = scene.cameras.fov * M_PI / 360;
	plan.d = scene.planes->position.x * scene.planes->vector.x + scene.planes->position.y \
	* scene.planes->vector.y +  scene.planes->position.z * scene.planes->vector.z;
	plan.vector = scene.planes->vector;
	int c = create_trgb(0, scene.planes->color.r, scene.planes->color.g, scene.planes->color.b);
	line.vector.z = 1;
	for (int y = 0; y < W_WIDTH; y++)
	{
		line.vector.y =tanf(((2.0 * y) -  W_HEIGHT) /( W_HEIGHT -2 ) * fov);
		for (int x = 0; x < W_HEIGHT; x++)
		{

			line.vector.x =  tanf(((2.0 * x) -  W_HEIGHT) / (W_HEIGHT - 2) * fov);
			printf("line.vector.x = %f %f %f %f\n", line.vector.x, line.vector.y, line.vector.z, line.vector.x * line.vector.x + line.vector.y * line.vector.y + line.vector.z * line.vector.z);
			p = intersection_plane_line(&line, &plan);
			if (p.z != -1)
				my_mlx_pixel_put(&scene.img, x, y, c);
		}
	}
	//mlx_put_image_to_window(scene.mlx, scene.window, scene.img.img, 0, 0);
	//mlx_hook(scene.window, 2, 1L<<0, close_win, &scene);
	//mlx_loop(scene.mlx);
	free_scene(&scene);
	printf("%f\n", fov);
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
		printf(" -Position: %f %f %f\n", scene.planes[i].position.x,scene.planes[i].position.y,scene.planes[i].position.z);
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
