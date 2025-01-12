/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene_black.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:35:19 by rperrot           #+#    #+#             */
/*   Updated: 2025/01/12 17:35:19 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "draw.h"
#include "mlx.h"

void	draw_scene_black(t_scene *scene)
{
	int	x;
	int	y;

	y = -1;
	while (++y < LENGTH)
	{
		x = -1;
		while (++x < LENGTH)
		{
			my_mlx_pixel_put(&scene->img, x, y, 0);
		}
	}
	mlx_put_image_to_window(scene->mlx, scene->window, scene->img.img, 0, 0);
}
