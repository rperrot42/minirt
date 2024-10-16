/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:01:43 by sabitbol          #+#    #+#             */
/*   Updated: 2024/10/16 18:03:41 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int add_sphere(t_scene *scene, char *str)
{
    t_sphere    sphere;

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
        sphere.radius = ft_atof(&str);
    else
        return (print_error(E_FILE_PARS));
    if (errno)
        return (print_error(strerror(errno)));
    while (*str && *str == ' ')
        str++;
    if (*str)
        sphere.color = get_color(&str);
    else
        return (print_error(E_FILE_PARS));
    if (errno)
        return (print_error(strerror(errno)));
    if (ft_realloc((void **)&scene->spheres, &scene->nb_spheres, sizeof(t_sphere), (void *)&sphere))
        return (print_error(E_MALLOC));
    return (0);
}
