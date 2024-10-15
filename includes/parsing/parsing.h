/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:35:47 by rperrot           #+#    #+#             */
/*   Updated: 2024/10/15 18:35:47 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_PARSING_H
#define MINIRT_PARSING_H
#include "struct.h"
#include "include.h"
int		check_file(const char *file_name);
t_color	get_color(char **line);
t_point	get_point(char **line);
t_point	get_vector(char **line);
#endif
