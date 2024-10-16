/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:35:47 by rperrot           #+#    #+#             */
/*   Updated: 2024/10/16 20:59:23 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_PARSING_H
# define MINIRT_PARSING_H

# include "struct.h"
# include "include.h"
# include "error.h"

int check_file(char *file_name);
t_color	get_color(char **line);
t_point	get_point(char **line);
t_point	get_vector(char **line);
int  add_ambient(t_scene *scene, char *str);
int  add_camera(t_scene *scene, char *str);
int add_light(t_scene *scene, char *str);
int add_sphere(t_scene *scene, char *str);
int add_plane(t_scene *scene, char *str);
int add_cylinder(t_scene *scene, char *str);
 t_bool  check_filename(char *str);
int ft_readline(int fd, t_scene *scene);
int add_elem(t_scene *scene, char *str, t_bool *camera, t_bool *ambient);

#endif
