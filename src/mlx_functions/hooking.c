/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:29:15 by sabitbol          #+#    #+#             */
/*   Updated: 2024/11/02 16:12:47 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "mlx.h"
#include "include.h"
#include "draw.h"

int	key_press(int keycode, t_scene *scene)
{
	printf("keycode: %d\n", keycode);
	if (keycode == KEY_ESC)
		free_scene(scene);
	return (0);
}

void	hooking(t_scene *scene)
{
	draw_window(scene);
	printf("wds\n");
	//mlx_loop_hook(scene->window,  draw_window, scene);
	mlx_hook(scene->window, 17,  0L, free_scene, scene);
	mlx_hook(scene->window, 2,  (1L << 0), key_press, scene);
	mlx_loop(scene->mlx);
}
