/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collison.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:40:45 by rperrot           #+#    #+#             */
/*   Updated: 2024/11/26 17:25:38 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define COLLISON_H
# include "struct.h"
# include "include.h"
t_point intersection_plane_line(t_line *line, t_plane *plane);
t_plane	*get_closest_plan(t_line *line, t_scene *scene, t_point *p);
t_color	get_color_plan(t_scene *scene, t_plane *plan, t_point *p, t_line *line);
t_sphere    *get_closest_sphere(t_line *line, t_scene *scene, t_point *p);

#endif //MINIRT_COLLISON_H
