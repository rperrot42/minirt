/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:29:15 by sabitbol          #+#    #+#             */
/*   Updated: 2024/10/31 12:52:40 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "error.h"
#include "stdlib.h"
#include "mlx.h"
#include "draw.h"

int	close_win(int keycode, t_scene *scene)
{
	(void)keycode;(void)scene;
	//free_scene(scene);
	exit(0);
}
void	hooking(t_scene *scene)
{
	draw_window(scene);
	mlx_loop_hook(scene->window,  draw_window, scene);
	mlx_hook(scene->window, 17,  1L << 0, close_win, scene);
	mlx_loop(scene->mlx);
}
