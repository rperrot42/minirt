/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:01:40 by sabitbol          #+#    #+#             */
/*   Updated: 2024/12/10 13:22:56 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int add_plane(t_scene *scene, char *str)
{
    t_plane plane;

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
    unit_vector(&plane.vector);
    while (*str && *str == ' ')
        str++;
    if (*str)
        plane.color = get_color(&str);
    else
        return (print_error(E_FILE_PARS));
    if (errno)
        return (print_error(strerror(errno)));
    plane.d = -(plane.p.x * plane.vector.x + plane.p.y * plane.vector.y + plane.p.z * plane.vector.z);
    if (ft_realloc((void **)&scene->planes, &scene->nb_planes, sizeof(t_plane), (void *)&plane))
        return (print_error(E_MALLOC));
    return (0);
}
