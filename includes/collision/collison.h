/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collison.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:40:45 by rperrot           #+#    #+#             */
/*   Updated: 2024/11/27 21:13:05 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define COLLISON_H

# include "struct.h"
# include "include.h"

t_point intersection_plane_line(t_line *line, t_plane *plane);
t_point	intersection_sphere_line(t_line *line, t_sphere *sphere);
int	intersection_obj_line(t_scene *scene, void *obj, t_line_color *l, t_line *line);
void    *get_closest_plan(t_line *line, t_scene *scene, t_line_color *l);
void	*get_closest_obj(t_line *line, t_scene *scene, t_line_color *l);
t_color	get_color_plan(t_scene *scene, t_plane *plan, t_point *p, t_line *line);
t_sphere    *get_closest_sphere(t_line *line, t_scene *scene, t_line_color *l);
t_color	get_color_obj(t_scene *scene, void *obj, t_line_color *l, t_line *line);

#endif //MINIRT_COLLISON_H
