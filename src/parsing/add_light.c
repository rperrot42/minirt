/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:50:07 by sabitbol          #+#    #+#             */
/*   Updated: 2025/01/03 10:08:27 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	add_light_color(t_scene *scene, char *str, t_light *light);

int	add_light(t_scene *scene, char *str)
{
	t_light	light;

	while (*str && *str == ' ')
		str++;
	if (*str)
		light.position = get_point(&str);
	else
		return (print_error(E_FILE_PARS));
	if (errno)
		return (print_error(strerror(errno)));
	while (*str && *str == ' ')
		str++;
	if (*str)
		light.intensity = ft_atof(&str);
	else
		return (print_error(E_FILE_PARS));
	if (light.intensity < 0 || light.intensity > 1)
		return (print_error(E_FILE_BRIGHT));
	if (errno)
		return (print_error(strerror(errno)));
	return (add_light_color(scene, str, &light));
}

static int	add_light_color(t_scene *scene, char *str, t_light *light)
{
	while (*str && *str == ' ')
		str++;
	if (*str)
		light->color = get_color(&str);
	else
		return (print_error(E_FILE_PARS));
	if (errno)
		return (print_error(strerror(errno)));
	if (ft_realloc((void **)&scene->lights, &scene->nb_lights, \
	sizeof(t_light), (void *)light))
		return (print_error(E_MALLOC));
	return (0);
}
