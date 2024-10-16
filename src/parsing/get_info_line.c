/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:14:11 by rperrot           #+#    #+#             */
/*   Updated: 2024/10/15 21:14:20 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_color	get_color(char **line)
{
	t_color	color;

	int result;
	result = ft_atoi(line);
	if (errno || **line != ',' || result < 0 || result > 255)
		return (errno = EINVAL, (t_color){0, 0, 0});
	color.r = result;
	(*line)++;
	result = ft_atoi(line);
	if (errno || **line != ',' || result < 0 || result > 255)
		return (errno = EINVAL, (t_color){0, 0, 0});
	color.g = result;
	(*line)++;
	result = ft_atoi(line);
	if (errno || result < 0 || result > 255)
		return (errno = EINVAL, (t_color){0, 0, 0});
	color.b = result;
	return (color);
}

t_point	get_point(char **line)
{
	t_point	point;
	float	result;

	result = ft_atof(line);
	if (errno || **line != ',' || result < -1000000 || result > 1000000)
		return (errno = EINVAL, (t_point ){0, 0, 0});
	point.x = result;
	(*line)++;
	result = ft_atof(line);
	if (errno || **line != ',' || result < -1000000 || result > 1000000)
		return (errno = EINVAL, (t_point){0, 0, 0});
	point.y = result;
	(*line)++;
	result = ft_atof(line);
	if (errno || result < -1000000 || result > 1000000)
		return (errno = EINVAL, (t_point){0, 0, 0});
	point.z = result;
	return (point);
}

t_point	get_vector(char **line)
{
	t_point	point;
	float	result;

	result = ft_atof(line);
	if (errno || **line != ',' || result < -1 || result > 1)
		return (errno = EINVAL, (t_point ){0, 0, 0});
	point.x = result;
	(*line)++;
	result = ft_atof(line);
	if (errno || **line != ',' || result < -1 || result > 1)
		return (errno = EINVAL, (t_point){0, 0, 0});
	point.y = result;
	(*line)++;
	result = ft_atof(line);
	if (errno || result < -1 || result > 1)
		return (errno = EINVAL, (t_point){0, 0, 0});
	point.z = result;
	return (point);
}
