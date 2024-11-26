/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:29:15 by sabitbol          #+#    #+#             */
/*   Updated: 2024/11/26 19:23:02 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "move.h"
#include "mlx.h"
#include "include.h"
#include "draw.h"

static void translation(t_move move, t_scene *scene);

int button_press(int keycode, int x, int y, t_scene *scene)
{
	if (keycode == LEFT_CLICK)
	{
		scene->move_mouse.left_click = true;
		scene->move_mouse.last_position_x = x;
		scene->move_mouse.last_position_y = y;
	}
	return (0);
}

int button_release(int keycode, int x, int y, t_scene *scene)
{
	(void)x;
	(void)y;
	if (keycode == LEFT_CLICK)
		scene->move_mouse.left_click = false;
	return (0);
}

int	key_press(int keycode, t_scene *scene)
{
	// printf("keycode : %d\n", keycode);
	if (keycode == KEY_ESC)
		free_scene(scene);
	else if (keycode == KEY_W)
		translation(FORWARD, scene);
	else if (keycode == KEY_S)
		translation(BACK, scene);
	else if (keycode == KEY_A)
		translation(LEFT, scene);
	else if (keycode == KEY_D)
		translation(RIGHT, scene);
	else if (keycode == KEY_SP)
		move_plane(scene, 0, 1, 0);
	else if (keycode == KEY_SHIFT)
		move_plane(scene, 0,-1, 0);
	return (0);
}

int	motion_notify(int x, int y, t_scene *scene)
{
	if (scene->move_mouse.left_click)
	{
		scene->cameras.vector.x += (x - scene->move_mouse.last_position_x) * 0.01;
		scene->cameras.vector.y += (y - scene->move_mouse.last_position_y) * 0.01;
		scene->move_mouse.last_position_x = x;
		scene->move_mouse.last_position_y = y;
	}
	return (0);
}

void	hooking(t_scene *scene)
{
	draw_window(scene);
	mlx_hook(scene->window, 17,  0L, free_scene, scene);
	mlx_hook(scene->window, 2,  (1L << 0), key_press, scene);
	mlx_hook(scene->window, 4, 1L << 2, button_press, scene);
	mlx_hook(scene->window, 5, 1L << 3, button_release, scene);
	mlx_hook(scene->window, 6, 1L << 6, motion_notify, scene);
	mlx_loop_hook(scene->mlx, draw_window, scene);
	mlx_loop(scene->mlx);
}

static void translation(t_move move, t_scene *scene)
{
	int positive;

	positive = 1;
	if (move == LEFT || move == BACK)
		positive = -1;
	if (move == LEFT || move == RIGHT)
		move_plane(scene, positive * cosf(scene->cameras.vector.x), 0, -1 * positive * sinf(scene->cameras.vector.x));
	else
		move_plane(scene, positive * sinf(scene->cameras.vector.x), 0, -1 * positive * cosf(scene->cameras.vector.x));
}
