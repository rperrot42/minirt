/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:57:36 by rperrot           #+#    #+#             */
/*   Updated: 2024/10/16 20:59:02 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int ft_readline(int fd, t_scene *scene)
{
	char	*line;
	t_bool	camera;
	t_bool	ambient;

	line = get_next_line(fd);
	camera = false;
	ambient = false;
	ft_memset(scene, 0, sizeof(t_scene));
	while (line)
	{
		if (add_elem(scene, line, &camera, &ambient))
		{
			free(line);
			errno = EINVAL;
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (camera == false | ambient == false)
	{
		errno = 1;
		if (camera == false)
			ft_dprintf(STDERR_FILENO, "Error: %s", E_NOT_CAMERAS);
		if (ambient == false)
			ft_dprintf(STDERR_FILENO, "Error: %s", E_NOT_AMBIENT);
		return (1);
	}
	return (0);
}