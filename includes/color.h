/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:18:04 by sabitbol          #+#    #+#             */
/*   Updated: 2025/01/06 15:34:10 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include "struct.h"
# include "collison.h"

int		create_trgb(int t, int r, int g, int b);
t_color	get_multiple_color(t_color obj, t_scene *scene, float scalar_product);
int		color_to_int(t_color color);
t_color	get_ambiant_color(t_color obj, t_scene *scene);
t_color	get_color_obj(t_scene *scene, void *obj, t_line_color *l, t_line *line);
void	draw_scene_black(t_scene *scene);
#endif