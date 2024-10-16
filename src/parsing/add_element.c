/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:56:27 by sabitbol          #+#    #+#             */
/*   Updated: 2024/10/16 17:38:01 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int  print_error(char *error)
{
    dprintf(2, "%s", error);
    return (0);
}

int  add_elem(t_scene *scene, char *str, t_bool *camera, t_bool *ambient)
{
    if (str[0] && str[1])
    {
        if (str[0] == 'A')
		{
			if (*ambient)
				return (print_error(E_FILE_INP));
			return (add_ambient(scene, str + 1));
		}
        if (str[0] == 'C')
		{
			if (*camera)
				return (print_error(E_FILE_INP));
			return (add_camera(scene, str + 1));
		}
       if (str[0] == 'L')
           return (add_light(scene, str + 1));
       if (str[0] == 's' && str[1] == 'p')
           return (add_sphere(scene, str + 2));
       if (str[0] == 'p' && str[1] == 'l')
           return (add_plane(scene, str + 2));
       if (str[0] == 'c' && str[1] == 'y')
           return (add_cylinder(scene, str + 2));
    }
    return (1);
}

int  add_ambient(t_scene *scene, char *str)
{
    while (*str && *str == ' ')
        str++;
    if (*str)
        scene->ambient.intensity = ft_atof(&str);
    else
        return (print_error(E_FILE_PARSE));
    if (errno)
        return (print_error(strerror(errno)));
    if (scene->ambient.intensity < 0 || scene->ambient.intensity > 1)
        return (print_error(E_FILE_INP)); 
    while (*str && *str == ' ')
        str++;
    if (*str)
        scene->ambient.color = get_color(&str);
    else
        return (print_error(E_FILE_PARSE));
    if (errno)
	{
		return (print_error(strerror(errno)));
	}
	return (1);
}

int  add_camera(t_scene *scene, char *str)
{
    while (*str && *str == ' ')
        str++;
    if (*str)
        scene->cameras.position = get_point(&str);
    else
        return (print_error(E_FILE_PARSE));
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
        return (print_error(E_FILE_PARSE));
    if (errno)
        return (print_error(strerror(errno)));
    if (scene->cameras.fov < 0 || scene->cameras.fov > 180)
        return (print_error(E_FILE_INP));
    return (0);
}

int add_light(t_scene *scene, char *str)
{
    t_lights light;

    while (*str && *str == ' ')
        str++;
    if (*str)
        light.position = get_point(&str);
    else
        return (print_error(E_FILE_PARSE));
    if (errno)
        return (print_error(strerror(errno)));
    while (*str && *str == ' ')
        str++;
    if (*str)
        light.ratio = ft_atof(&str);
    else
        return (print_error(E_FILE_PARSE));
    if (light.ratio < 0 || light->ratio > 1)
        return (print_error(E_FILE_INP));
    if (errno)
        return (print_error(strerror(errno)));
    while (*str && *str == ' ')
        str++;
    if (*str)
        light.color = get_color(&str);
    else
        return (print_error(E_FILE_PARSE));
    if (errno)
        return (print_error(strerror(errno)));
    if (ft_realloc(&scene->lights, &scene->nb_lights, sizeof(t_lights), light))
        return (print_error(E_MALLOC));
   return (0);
}

int add_sphere(t_scene *scene, char *str)
{
    t_sphere    sphere;

    while (*str && *str == ' ')
        str++;
    if (*str)
        sphere.center = get_point(&str);
    else
        return (print_error(E_FILE_PARSE));
    if (errno)
        return (print_error(strerror(errno)));
    while (*str && *str == ' ')
        str++;
    if (*str)
        sphere.radius = ft_atof(&str);
    else
        return (print_error(E_FILE_PARSE));
    if (errno)
        return (print_error(strerror(errno)));
    while (*str && *str == ' ')
        str++;
    if (*str)
        sphere.color = get_color(&str);
    else
        return (print_error(E_FILE_PARSE));
    if (errno)
        return (print_error(strerror(errno)));
    if (ft_realloc(&scene->spheres, &scene->nb_spheres, sizeof(t_sphere), sphere))
        return (print_error(E_MALLOC));
    return (0);
}

int add_plane(t_scene *scene, char *str)
{
    t_plane plane;

    while (*str && *str == ' ')
        str++;
    if (*str)
        plane.point = get_point(&str);
    else
        return (print_error(E_FILE_PARSE));
    if (errno)
        return (print_error(strerror(errno)));
    while (*str && *str == ' ')
        str++;
    if (*str)
        plane.vector = get_vector(&str);
    else
        return (print_error(E_FILE_PARSE));
    if (errno)
        return (print_error(strerror(errno)));
    while (*str && *str == ' ')
        str++;
    if (*str)
        plane.point = get_point(&str);
    else
        return (print_error(E_FILE_PARSE));
    if (errno)
        return (print_error(strerror(errno)));
    if (ft_realloc(&scene->planes, &scene->nb_planes, sizeof(t_plane), plane))
        return (print_error(E_MALLOC));
    return (0);
}

int add_cylinder(t_scene *scene, char *str)
{
    t_cylinder  cylinder;

    while (*str && *str == ' ')
        str++;
    if (*str)
        cylinder.point = get_point(&str);
    else
        return (print_error(E_FILE_PARSE));
    if (errno)
        return (print_error(strerror(errno)));
    while (*str && *str == ' ')
        str++;
    if (*str)
        cylinder.direction = get_vector(&str);
    else
        return (print_error(E_FILE_PARSE));
    if (errno)
        return (print_error(strerror(errno)));
    while (*str && *str == ' ')
        str++;
    if (*str)
        cylinder.diameter = ft_atof(&str);
    else
        return (print_error(E_FILE_PARSE));
    if (errno)
        return (print_error(strerror(errno)));
    while (*str && *str == ' ')
        str++;
    if (*str)
        cylinder.color = get_color(&str);
    else
        return (print_error(E_FILE_PARSE));
    if (errno)
        return (print_error(strerror(errno)));
    if (ft_realloc(&scene->cylinder, &scene->nb_cylinder, sizeof(t_cylinder), cylinder))
        return (print_error(E_MALLOC));
    return (0);
}
