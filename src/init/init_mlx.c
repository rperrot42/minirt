/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:56:07 by sabitbol          #+#    #+#             */
/*   Updated: 2024/10/24 14:20:29 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mini_rt.h"
#include "struct.h"
#include "error.h"

int init_window(t_scene *scene)
{
    scene->mlx = mlx_init();
    if (!scene->mlx)
        return (print_error(E_MLX_INIT));
    scene->window = mlx_new_window(scene->mlx, W_WIDTH, W_HEIGHT, "miniRT");
    if (!scene->window)
        return (print_error(E_MLX_WINDOW));
    scene->img.img = mlx_new_image(scene->mlx, W_WIDTH, W_HEIGHT);
    if (!scene->img.img)
        return (print_error(E_MLX_IMG));
    scene->img.addr = mlx_get_data_addr(scene->img.img, \
    &scene->img.bits_per_pixel, &scene->img.line_length, &scene->img.endian);
    return (0);
}
