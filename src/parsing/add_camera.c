/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:00:19 by sabitbol          #+#    #+#             */
/*   Updated: 2024/10/16 21:36:37 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int  add_camera(t_scene *scene, char *str)
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
