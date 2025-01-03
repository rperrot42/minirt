/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:49:43 by sabitbol          #+#    #+#             */
/*   Updated: 2025/01/03 09:53:00 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	add_camera(t_scene *scene, char *str)
{
	while (*str && *str == ' ')
		str++;
	if (*str)
		scene->cameras.position = get_point(&str);
	else
		return (print_error(E_FILE_PARS));
	if (errno)
		return (print_error(strerror(errno)));
	while (*str && *str == ' ')
		str++;
	if (*str)
		scene->cameras.vector = get_vector(&str);
	if (errno)
		return (print_error(strerror(errno)));
	while (*str && *str == ' ')
		str++;
	if (*str)
		scene->cameras.fov = ft_atof(&str);
	else
		return (print_error(E_FILE_PARS));
	if (errno)
		return (print_error(strerror(errno)));
	if (scene->cameras.fov < 0 || scene->cameras.fov > 180)
		return (print_error(E_FILE_FOV));
	return (0);
}
