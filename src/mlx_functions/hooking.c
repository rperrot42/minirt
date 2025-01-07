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
#include "move.h"
#include "mlx.h"
#include "include.h"
#include "draw.h"
#include "utils.h"

static void	rotation_obj(t_scene *scene, float rotation, t_coordinate rotate);

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

int	key_press(int keycode, t_scene *scene)
{
	if (keycode == KEY_ESC)
		free_scene(scene);
	else if (keycode == KEY_W)
		scene->press_key.w_press = true;
	else if (keycode == KEY_S)
		scene->press_key.s_press = true;
	else if (keycode == KEY_A)
		scene->press_key.a_press = true;
	else if (keycode == KEY_D)
		scene->press_key.d_press = true;
	else if (keycode == KEY_SP)
		scene->press_key.sp_press = true;
	else if (keycode == KEY_TAB)
		scene->press_key.tab_press = true;
	return (0);
}

int	key_release(int keycode, t_scene *scene)
{
	if (keycode == KEY_W)
		scene->press_key.w_press = false;
	else if (keycode == KEY_S)
		scene->press_key.s_press = false;
	else if (keycode == KEY_A)
		scene->press_key.a_press = false;
	else if (keycode == KEY_D)
		scene->press_key.d_press = false;
	else if (keycode == KEY_SP)
		scene->press_key.sp_press = false;
	else if (keycode == KEY_TAB)
		scene->press_key.tab_press = false;
	return (0);
}

int	motion_notify(int x, int y, t_scene *scene)
{
	if (scene->move_mouse.left_click)
	{
		rotation_obj(scene, (x - scene->move_mouse.last_position_x) \
		* 0.01, Y);
		rotation_obj(scene, (y - scene->move_mouse.last_position_y) \
		* 0.01, X);
		scene->move_mouse.last_position_x = x;
		scene->move_mouse.last_position_y = y;
	}
	return (0);
}

void	hooking(t_scene *scene)
{
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

static void	rotate_point(t_point *p, float rotation, t_coordinate rotate)
{
	if (rotate == X)
	{
		p->y = cosf(rotation) * p->y - sinf(rotation) * p->z;
		p->z = sinf(rotation) * p->y + cosf(rotation) * p->z;
	}
	else if (rotate == Y)
	{
		p->x = cosf(rotation) * p->x + sinf(rotation) * p->z;
		p->z = -sinf(rotation) * p->x + cosf(rotation) * p->z;
	}
}

static void	rotation_obj(t_scene *scene, float rotation, t_coordinate rotate)
{
	int		i;

	i = -1;
	if (rotation > 0.1)
		rotation = 0.1;
	while (++i < scene->nb_planes)
	{
		rotate_point(&scene->planes[i].p, rotation, rotate);
		rotate_point(&scene->planes[i].vector, rotation, rotate);
		scene->planes[i].d = (scene->planes[i].vector.x * scene->planes[i].p.x + scene->planes[i].vector.y * scene->planes[i].p.y + \
				scene->planes[i].vector.z * scene->planes[i].p.z) * -1;
	}
	i = -1;
	while (++i < scene->nb_cylinders)
	{
		rotate_point(&scene->cylinders[i].position, rotation, rotate);
		rotate_point(&scene->cylinders[i].vector, rotation, rotate);
		unit_vector(&scene->cylinders[i].vector);
	}
	i = -1;
	while (++i < scene->nb_lights)
		rotate_point(&scene->lights[i].position, rotation, rotate);
	i = -1;
	while (++i < scene->nb_spheres)
		rotate_point(&scene->spheres[i].position, rotation, rotate);
}
