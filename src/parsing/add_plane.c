/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:50:18 by sabitbol          #+#    #+#             */
/*   Updated: 2025/01/03 10:12:25 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	add_plane_color(t_scene *scene, char *str, t_plane *plane);

int	add_plane(t_scene *scene, char *str)
{
	t_plane	plane;

	while (*str && *str == ' ')
		str++;
	if (*str)
		plane.p = get_point(&str);
	else
		return (print_error(E_FILE_PARS));
	if (errno)
		return (print_error(strerror(errno)));
	while (*str && *str == ' ')
		str++;
	if (*str)
		plane.vector = get_vector(&str);
	else
		return (print_error(E_FILE_PARS));
	if (errno)
		return (print_error(strerror(errno)));
	while (*str && *str == ' ')
		str++;
	return (add_plane_color(scene, str, &plane));
}

static int	add_plane_color(t_scene *scene, char *str, t_plane *plane)
{
	if (*str)
		plane->color = get_color(&str);
	else
		return (print_error(E_FILE_PARS));
	if (errno)
		return (print_error(strerror(errno)));
	plane->d = -(plane->p.x * plane->vector.x + plane->p.y * \
	plane->vector.y + plane->p.z * plane->vector.z);
	if (ft_realloc((void **)&scene->planes, &scene->nb_planes, \
	sizeof(t_plane), (void *)plane))
		return (print_error(E_MALLOC));
	return (0);
}
