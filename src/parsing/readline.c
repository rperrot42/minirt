/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:57:36 by rperrot           #+#    #+#             */
/*   Updated: 2025/01/11 16:14:25 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "angle.h"
#include "move.h"

static void	rotate_camera(t_scene *scene);

static int	error_camera_ambient(t_bool camera, t_bool ambient, t_scene *scene);

int	ft_readline(int fd, t_scene *scene)
{
	char	*line;
	t_bool	camera;
	t_bool	ambient;

	line = get_next_line(fd);
	camera = false;
	ambient = false;
	ft_memset(scene, 0, sizeof(t_scene));
	while (line)
	{
		if (add_elem(scene, line, &camera, &ambient))
			return (free(line), 1);
		free(line);
		line = get_next_line(fd);
	}
	rotate_camera(scene);
	if (camera == false || ambient == false || scene->lights == false)
		return (error_camera_ambient(camera, ambient, scene));
	return (0);
}

static int	error_camera_ambient(t_bool camera, t_bool ambient, t_scene *scene)
{
	errno = 1;
	if (camera == false)
		ft_dprintf(STDERR_FILENO, "Error: %s", E_NOT_CAMERAS);
	if (ambient == false)
		ft_dprintf(STDERR_FILENO, "Error: %s", E_NOT_AMBIENT);
	if (scene->lights == false)
		ft_dprintf(STDERR_FILENO, "Error: %s", E_NOT_LIGHTS);
	return (1);
}

static void	rotate_camera(t_scene *scene)
{
	t_point	camera_vector;
	double	rotation_x;
	double	rotation_y;
	int		i;

	camera_vector = scene->cameras.vector;
	rotation_y = atan2(camera_vector.x, camera_vector.z);
	rotation_x = -asin(camera_vector.y / calc_norm(camera_vector));
	i = -1;
	while (++i < 100)
	{
		rotation_obj(scene, -rotation_x / 100, X);
		rotation_obj(scene, -rotation_y / 100, Y);
	}
	scene->cameras.vector = (t_point){0};
}
