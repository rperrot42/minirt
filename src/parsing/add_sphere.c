/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:50:26 by sabitbol          #+#    #+#             */
/*   Updated: 2025/01/03 10:14:31 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	add_sphere_color(t_scene *scene, char *str, t_sphere *sphere);

int	add_sphere(t_scene *scene, char *str)
{
	t_sphere	sphere;

	while (*str && *str == ' ')
		str++;
	if (*str)
		sphere.position = get_point(&str);
	else
		return (print_error(E_FILE_PARS));
	if (errno)
		return (print_error(strerror(errno)));
	while (*str && *str == ' ')
		str++;
	if (*str)
		sphere.radius = ft_atof(&str) / 2;
	else
		return (print_error(E_FILE_PARS));
	if (errno)
		return (print_error(strerror(errno)));
	while (*str && *str == ' ')
		str++;
	return (add_sphere_color(scene, str, &sphere));
}

static int	add_sphere_color(t_scene *scene, char *str, t_sphere *sphere)
{
	if (*str)
		sphere->color = get_color(&str);
	else
		return (print_error(E_FILE_PARS));
	if (errno)
		return (print_error(strerror(errno)));
	if (ft_realloc((void **)&scene->spheres, &scene->nb_spheres, \
	sizeof(t_sphere), (void *)sphere))
		return (print_error(E_MALLOC));
	if (!ft_had_whitespace(str))
		return (print_error(E_END_LINE));
	return (0);
}
