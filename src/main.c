/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:24:17 by rperrot           #+#    #+#             */
/*   Updated: 2024/12/05 17:02:15 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "parsing.h"
#include "init.h"
#include "collison.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		return_value;
	t_scene	scene;

	errno = 0;
	scene = (t_scene){0};
	if (argc != 2)
		return (print_error(E_NB_ARGS));
	fd = check_file(argv[1]);
	if (fd == -1)
		return (1);
	return_value = ft_readline(fd, &scene);
	if (point_in_obj(&scene, &scene.lights->position))
		scene.light_in_obj = true;
	if (init_window(&scene))
		return (1);
	if (!return_value)
		hooking(&scene);
	else
	{
		free_scene(&scene);
		return (1);
	}
	free_scene(&scene);
	return (0);
}
