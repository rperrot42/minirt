/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:24:17 by rperrot           #+#    #+#             */
/*   Updated: 2024/10/15 20:24:24 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "error.h"
#include  "mini_rt.h"
#include "parsing.h"

int main(int argc, char **argv)
{
	errno = 0;
	if (argc == 2)
	{
		check_file(argv[1]);
		return 1;
	}
	else
		ft_dprintf(STDOUT_FILENO, E_NB_ARGS);
	return 0;
}