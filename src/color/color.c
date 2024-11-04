/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:16:23 by sabitbol          #+#    #+#             */
/*   Updated: 2024/11/02 14:47:43 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

t_color	get_multiple_color(t_color obj, t_color light)
{
	t_color	color;

	color.r = obj.r * light.r / 255;
	color.g = obj.g * light.g / 255;
	color.b = obj.b * light.b / 255;
	return (color);
}

int color_to_int(t_color color)
{
	return (create_trgb(0, color.r, color.g, color.b));
}