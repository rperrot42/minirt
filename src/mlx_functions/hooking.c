/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:37:07 by sabitbol          #+#    #+#             */
/*   Updated: 2025/01/07 13:20:13 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "mlx.h"
#include "include.h"
#include "draw.h"
#include "move.h"
#include "collison.h"

int	button_press(int keycode, int x, int y, t_scene *scene)
{
	if (keycode == LEFT_CLICK)
	{
		scene->move_mouse.left_click = true;
		scene->move_mouse.last_position_x = x;
		scene->move_mouse.last_position_y = y;
	}
	else if (keycode == ROLL_UP)
	{
		if (scene->cameras.fov <= 90)
			scene->cameras.fov += (scene->cameras.fov) * 0.03;
		else
			scene->cameras.fov += (179 - scene->cameras.fov) * 0.03;
	}
	else if (keycode == ROLL_DOWN)
	{
		if (scene->cameras.fov <= 90)
			scene->cameras.fov -= (scene->cameras.fov) * 0.03;
		else
			scene->cameras.fov -= (179 - scene->cameras.fov) * 0.03;
	}
	return (0);
}

int	button_release(int keycode, int x, int y, t_scene *scene)
{
	(void)x;
	(void)y;
	if (keycode == LEFT_CLICK)
		scene->move_mouse.left_click = false;
	return (0);
}

int	motion_notify(int x, int y, t_scene *scene)
{
	double	rotation_x;
	double	rotation_y;
	int		i;

	if (scene->move_mouse.left_click)
	{
		rotation_y = (x - scene->move_mouse.last_position_x) * 0.0001;
		rotation_x = (y - scene->move_mouse.last_position_y) * 0.0001;
		i = -1;
		while (++i < 100)
		{
			rotation_obj(scene, rotation_y, Y);
			rotation_obj(scene, rotation_x, X);
		}
		scene->move_mouse.last_position_x = x;
		scene->move_mouse.last_position_y = y;
	}
	return (0);
}

void	hooking(t_scene *scene)
{
	if (camera_in_obj(scene))
		mlx_put_image_to_window(scene->mlx, scene->window, scene->img.img, 0, 0);
	draw_window(scene);
	mlx_hook(scene->window, 17, 0L, free_scene, scene);
	mlx_hook(scene->window, 2, (1L << 0), key_press, scene);
	mlx_hook(scene->window, 3, (1L << 1), key_release, scene);
	mlx_hook(scene->window, 4, 1L << 2, button_press, scene);
	mlx_hook(scene->window, 5, 1L << 3, button_release, scene);
	mlx_hook(scene->window, 6, 1L << 6, motion_notify, scene);
	mlx_loop_hook(scene->mlx, draw_window, scene);
	mlx_loop(scene->mlx);
}
