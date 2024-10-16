/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:56:27 by sabitbol          #+#    #+#             */
/*   Updated: 2024/10/16 01:32:50 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int  print_error(char *error)
{
    dprintf(2, "%s", error);
    return (1);
}

int add_elem(t_scene *scene, char *str, t_bool *camera, t_bool *ambient)
{
    if (str[0] && str[1])
    {
        if (str[0] == 'A')
		{
			if (*ambient)
				return (print_error(E_FILE_INP));
			*ambient = true;
			return (add_ambient(scene, str + 1));
		}
        if (str[0] == 'C')
		{
			if (*camera)
				return (print_error(E_FILE_INP));
			*camera = true;
			return (add_camera(scene, str + 1));
		}
//        if (str[0] == 'L')
//            return (add_light(scene, str + 1));
//        if (str[0] == 's' && str[1] == 'p')
//            return (add_sphere(scene, str + 2));
//        if (str[0] == 'p' && str[1] == 'l')
//            return (add_plane(scene, str + 2));
//        if (str[0] == 'c' && str[1] == 'y')
//            return (add_cylinder(scene, str + 2));
    }
    return (0);
}

int  add_ambient(t_scene *scene, char *str)
{
    while (*str && *str == ' ')
        str++;
    if (*str)
        scene->ambient.intensity = ft_atof(&str);
    else
        return (1);
    if (errno)
        return (print_error(strerror(errno)));
    if (scene->ambient.intensity < 0 || scene->ambient.intensity > 1)
        return (print_error(E_FILE_INP)); 
    while (*str && *str == ' ')
        str++;
    if (*str)
        scene->ambient.color = get_color(&str);
    else
        return (1);
    if (errno)
	{
		return (print_error(strerror(errno)));
	}
	return (0);
}

int  add_camera(t_scene *scene, char *str)
{
    while (*str && *str == ' ')
        str++;
    if (*str)
        scene->cameras.position = get_point(&str);
    else
        return (1);
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
        return (1);
    if (errno)
        return (print_error(strerror(errno)));
    if (scene->cameras.fov < 0 || scene->cameras.fov > 180)
        return (print_error(E_FILE_INP));
    return (0);
}

//t_light    *add_light(t_scene *scene, char *str)
//{
//    t_light    *light;
//
//    light = malloc(sizeof(t_light));
//    if (!light)
//        return (print_error(E_MALLOC));
//    while (*str && *str == ' ')
//        str++;
//    if (*str)
//        light->position = get_point(&str);
//    else
//        return (NULL);
//    if (errno)
//        return (print_error(strerror(errno)));
//    while (*str && *str == ' ')
//        str++;
//    if (*str)
//        light->ratio = ft_atof(&str);
//    else
//        return (NULL);
//    if (light->ratio < 0 || light->ratio > 1)
//        return (print_error(E_FILE_INP));
//    if (errno)
//        return (print_error(strerror(errno)));
//    while (*str && *str == ' ')
//        str++;
//    if (*str)
//        light->color = get_color(&str);
//    else
//        return (NULL);
//    if (errno)
//        return (print_error(strerror(errno)));
//    return (light);
//}
//
//t_sphere  *add_sphere(t_scene *scene, char *str)
//{
//    t_sphere    *sphere;
//
//    sphere = malloc(sizeof(t_sphere));
//    if (!sphere)
//        return (NULL);
//    while (*str && *str == ' ')
//        str++;
//    if (*str)
//        sphere->center = get_point(&str);
//    else
//        return (NULL);
//    if (errno)
//        return (print_error(strerror(errno)));
//    while (*str && *str == ' ')
//        str++;
//    if (*str)
//        sphere->radius = ft_atof(&str);
//    else
//        return (NULL);
//    if (errno)
//        return (print_error(strerror(errno)));
//    while (*str && *str == ' ')
//        str++;
//    if (*str)
//        sphere->color = get_color(&str);
//    else
//        return (NULL);
//    if (errno)
//        return (print_error(strerror(errno)));
//}
//
//t_plane *add_plane(t_scene *scene, char *str)
//{
//    t_plane plane;
//
//    plane = malloc(sizeof(t_plane));
//    if (!plane)
//        return (NULL);
//    while (*str && *str == ' ')
//        str++;
//    if (*str)
//        plane->point = get_point(&str);
//    else
//        return (NULL);
//    if (errno)
//        return (print_error(strerror(errno)));
//    while (*str && *str == ' ')
//        str++;
//    if (*str)
//        plane->vector = get_vector(&str);
//    else
//        return (NULL);
//    if (errno)
//        return (print_error(strerror(errno)));
//    while (*str && *str == ' ')
//        str++;
//    if (*str)
//        plane->point = get_point(&str);
//    else
//        return (NULL);
//    if (errno)
//        return (print_error(strerror(errno)));
//}
//
//t_cylinder  *add_cylinder(t_scene *scene, char *str)
//{
//    t_cylinder  *cylinder;
//
//    cylinder = malloc(sizeof(t_cylinder));
//    if (!cylinder)
//        return (NULL);
//    while (*str && *str == ' ')
//        str++;
//    if (*str)
//        cylinder->point = get_point(&str);
//    else
//        return (NULL);
//    if (errno)
//        return (print_error(strerror(errno)));
//    while (*str && *str == ' ')
//        str++;
//    if (*str)
//        cylinder->direction = get_vector(&str);
//    else
//        return (NULL);
//    if (errno)
//        return (print_error(strerror(errno)));
//    while (*str && *str == ' ')
//        str++;
//    if (*str)
//        cylinder->diameter = ft_atof(&str);
//    else
//        return (NULL);
//    if (errno)
//        return (print_error(strerror(errno)));
//    while (*str && *str == ' ')
//        str++;
//    if (*str)
//        cylinder->height = ft_atof(&str);
//    else
//        return (NULL);
//    if (errno)
//        return (print_error(strerror(errno)));
//    while (*str && *str == ' ')
//        str++;
//    if (*str)
//        cylinder->color = get_color(&str);
//    else
//        return (NULL);
//    if (errno)
//        return (print_error(strerror(errno)));
//}
