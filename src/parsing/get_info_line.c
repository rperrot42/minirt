/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:14:11 by rperrot           #+#    #+#             */
/*   Updated: 2025/01/11 19:56:45 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_color	get_color(char **line)
{
	t_color	color;
	int		result;

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
		return (errno = EINVAL, (t_point){0, 0, 0});
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
		return (errno = EINVAL, (t_point){0, 0, 0});
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
	if (!point.x && !point.y && !point.z)
		return (errno = EINVAL, point);
	return (point);
}

void	unit_vector(t_point *v)
{
	float	n;

	n = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	v->x /= n;
	v->y /= n;
	v->z /= n;
}
