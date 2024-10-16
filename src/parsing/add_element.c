/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:56:27 by sabitbol          #+#    #+#             */
/*   Updated: 2024/10/16 20:58:25 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	add_elem(t_scene *scene, char *str, t_bool *camera, t_bool *ambient)
{
    if (str[0] && str[1])
    {
        if (str[0] == 'A')
		{
			if (*ambient)
				return (print_error(E_AMB_NB));
			*ambient = true;
			return (add_ambient(scene, str + 1));
		}
        else if (str[0] == 'C')
		{
			if (*camera)
				return (print_error(E_CAM_NB));
			*camera = true;
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
	if (str[0] && !ft_had_whitespace(str))
		return (print_error(E_FILE_INP));
    return (0);
}
