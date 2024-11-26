/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:16:23 by sabitbol          #+#    #+#             */
/*   Updated: 2024/11/25 17:45:47 by sabitbol         ###   ########.fr       */
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
#include <stdio.h>
t_color	get_multiple_color(t_color obj, t_scene *scene, float scalar_product)
{
	t_color	color;
	float		c;

	c = (float)((float)obj.r / 255) * ((scene->lights->color.r * scene->lights->intensity) + (scene->ambient.color.r * scene->ambient.intensity));
	// printf("r : %f\n", c);
	if (c > obj.r)
		color.r = obj.r * scalar_product;
	else
		color.r = c * scalar_product;
	c = (float)((float)obj.g / 255) * ((scene->lights->color.g * scene->lights->intensity) + (scene->ambient.color.g * scene->ambient.intensity));
	// printf("g : %f\n", c);
	if (c > obj.g)
		color.g = obj.g * scalar_product;
	else
		color.g = c * scalar_product;
	c = (float)((float)obj.b / 255) * ((scene->lights->color.b * scene->lights->intensity) + (scene->ambient.color.b * scene->ambient.intensity));
	// printf("b : %f\n", c);
	if (c > obj.b)
		color.b = obj.b * scalar_product;
	else
		color.b = c * scalar_product;
	// printf("r : %d\n", color.r);
	// printf("g : %d\n", color.g);
	// printf("b : %d\n", color.b);
	return (color);
}

t_color	get_ambiant_color(t_color obj, t_scene *scene)
{
	t_color	c;

	c.r = ((float)obj.r / 255) * scene->ambient.color.r * scene->ambient.intensity;
	c.g = ((float)obj.g / 255) * scene->ambient.color.g * scene->ambient.intensity;
	c.b = ((float)obj.b / 255) * scene->ambient.color.b * scene->ambient.intensity;
	return (c);
}

int color_to_int(t_color color)
{
	return (create_trgb(0, color.r, color.g, color.b));
}