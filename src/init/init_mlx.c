/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:56:07 by sabitbol          #+#    #+#             */
/*   Updated: 2024/10/23 21:23:35 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "struct.h"
#include "mini_rt.h"

int init_window(t_scene *scene)
{
    scene->mlx = mlx_init();
    if (!init_mlx)
        return (1);
    scene->window = mlx_new_window(scene->mlx, W_WITDH, W_HEIGHT, "miniRT");
    if (!scene->window)
        return (1);
    scene->img.img = mlx_new_image(scene->mlx, W_WITDH, W_HEIGHT);
    if (!scene->img)
        return (1);
    scene->img.addr = mlx_get_data_addr(scene->img.img, \
    &scene->img.bits_per_pixel, &scene->img.line_lengh, &scene->img.endian);
    return (0);
}
