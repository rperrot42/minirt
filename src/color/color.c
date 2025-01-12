/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:16:23 by sabitbol          #+#    #+#             */
/*   Updated: 2025/01/12 13:39:22 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "collison.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_color	get_multiple_color(t_color obj, t_scene *scene, float scalar_product)
{
	t_color		color;
	float		c;

	c = (float)((float)obj.r / 255) *((scene->lights->color.r * \
	scene->lights->intensity * scalar_product) + \
	(scene->ambient.color.r * scene->ambient.intensity));
	if (c > obj.r)
		color.r = obj.r;
	else
		color.r = c;
	c = (float)((float)obj.g / 255) *((scene->lights->color.g * \
	scene->lights->intensity * scalar_product) + (scene->ambient.color.g \
	* scene->ambient.intensity));
	if (c > obj.g)
		color.g = obj.g;
	else
		color.g = c;
	c = (float)((float)obj.b / 255) *((scene->lights->color.b * \
	scene->lights->intensity * scalar_product) + (scene->ambient.color.b * \
	scene->ambient.intensity));
	if (c > obj.b)
		color.b = obj.b;
	else
		color.b = c;
	return (color);
}

t_color	get_ambiant_color(t_color obj, t_scene *scene)
{
	t_color	c;

	c.r = ((float)obj.r / 255) * scene->ambient.color.r \
	* scene->ambient.intensity;
	c.g = ((float)obj.g / 255) * scene->ambient.color.g \
	* scene->ambient.intensity;
	c.b = ((float)obj.b / 255) * scene->ambient.color.b \
	* scene->ambient.intensity;
	return (c);
}

int	color_to_int(t_color color)
{
	return (create_trgb(0, color.r, color.g, color.b));
}

t_color	get_color_obj(t_scene *scene, void *obj, t_line_color *l, t_line *line)
{
	if (scene->light_in_obj || intersection_obj_line(scene, obj, l, line))
		return (get_ambiant_color(l->color, scene));
	return (get_multiple_color(l->color, scene, fabs(l->scalar_light_obj)));
}
