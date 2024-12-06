/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:01:14 by sabitbol          #+#    #+#             */
/*   Updated: 2024/12/06 15:31:05 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "angle.h"

int add_cylinder(t_scene *scene, char *str)
{
    t_cylinder  cylinder;

    while (*str && *str == ' ')
        str++;
    if (*str)
        cylinder.position = get_point(&str);
    else
        return (print_error(E_FILE_PARS));
    if (errno)
        return (print_error(strerror(errno)));
    while (*str && *str == ' ')
        str++;
    if (*str)
    {
        cylinder.vector = get_vector(&str);
    }
    else
        return (print_error(E_FILE_PARS));
    if (errno)
        return (print_error(strerror(errno)));
    while (*str && *str == ' ')
        str++;
    if (*str)
        cylinder.radius = ft_atof(&str) / 2;
    else
        return (print_error(E_FILE_PARS));
    if (errno)
		return (print_error(strerror(errno)));
	while (*str && *str == ' ')
		str++;
    if (*str)
        cylinder.height = ft_atof(&str);
    else
        return (print_error(E_FILE_PARS));
    if (errno)
        return (print_error(strerror(errno)));
    while (*str && *str == ' ')
        str++;
    if (*str)
        cylinder.color = get_color(&str);
    else
        return (print_error(E_FILE_PARS));
    if (errno)
        return (print_error(strerror(errno)));
    if (ft_realloc((void **)&scene->cylinders, &scene->nb_cylinders, sizeof(t_cylinder), (void *)&cylinder))
        return (print_error(E_MALLOC));
    return (0);
}
