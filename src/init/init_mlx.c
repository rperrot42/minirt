/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:46:01 by sabitbol          #+#    #+#             */
/*   Updated: 2025/01/03 09:48:43 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mini_rt.h"
#include "struct.h"
#include "error.h"

int	init_window(t_scene *scene)
{
	scene->mlx = mlx_init();
	if (!scene->mlx)
		return (print_error(E_MLX_INIT));
	scene->window = mlx_new_window(scene->mlx, LENGTH, LENGTH, "miniRT");
	if (!scene->window)
		return (print_error(E_MLX_WINDOW));
	scene->img.img = mlx_new_image(scene->mlx, LENGTH, LENGTH);
	if (!scene->img.img)
		return (print_error(E_MLX_IMG));
	scene->img.addr = mlx_get_data_addr(scene->img.img, \
	&scene->img.bits_per_pixel, &scene->img.line_length, &scene->img.endian);
	scene->img.bits_per_pixel /= 8;
	return (0);
}
