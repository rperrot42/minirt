/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:43:34 by sabitbol          #+#    #+#             */
/*   Updated: 2024/10/31 11:13:27 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "mini_rt.h"

void    draw_window(t_scene *scene)
{
    int x;
    int y;

    y = 0;
    while (y < LENGTH)
    {
        x = 0;
        while (x < LENGTH)
        {
            draw_pixel(x, y, scene);
            x++;
        }
        y++;
    }
}

void    draw_pixel(int x, int y, t_scene *scene)
{
    
}
