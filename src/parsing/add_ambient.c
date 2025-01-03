/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:49:31 by sabitbol          #+#    #+#             */
/*   Updated: 2025/01/03 09:52:39 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	add_ambient(t_scene *scene, char *str)
{
	while (*str && *str == ' ')
		str++;
	if (*str)
		scene->ambient.intensity = ft_atof(&str);
	else
		return (print_error(E_FILE_PARS));
	if (errno)
		return (print_error(strerror(errno)));
	if (scene->ambient.intensity < 0 || scene->ambient.intensity > 1)
		return (print_error(E_FILE_BRIGHT));
	while (*str && *str == ' ')
		str++;
	if (*str)
		scene->ambient.color = get_color(&str);
	else
		return (print_error(E_FILE_PARS));
	if (errno)
	{
		return (print_error(strerror(errno)));
	}
	return (0);
}
