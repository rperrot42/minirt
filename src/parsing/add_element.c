/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:52:03 by sabitbol          #+#    #+#             */
/*   Updated: 2025/01/11 16:11:34 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	add_elem(t_scene *scene, char *str, t_bool *camera, t_bool *ambient)
{
	if (str[0] == 'A')
	{
		if (*ambient)
			return (print_error(E_AMB_NB));
		return (*ambient = true, add_ambient(scene, str + 1));
	}
	if (str[0] == 'C')
	{
		if (*camera)
			return (print_error(E_CAM_NB));
		return (*camera = true, add_camera(scene, str + 1));
	}
	if (str[0] == 'L')
		return (add_light(scene, str + 1));
	if (str[0] && str[1] && str[0] == 's' && str[1] == 'p')
		return (add_sphere(scene, str + 2));
	if (str[0] && str[1] && str[0] == 'p' && str[1] == 'l')
		return (add_plane(scene, str + 2));
	if (str[0] && str[1] && str[0] == 'c' && str[1] == 'y')
		return (add_cylinder(scene, str + 2));
	if (str[0] && str[1] && str[0] == '#')
		return (0);
	return (str[0] && !ft_had_whitespace(str) && print_error(E_FILE_PARS));
}
