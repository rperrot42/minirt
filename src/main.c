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

#include "mini_rt.h"

int main(int argc, const char **argv)
{
	if (argc == 2)
	{
		printf("Usage: %f <float>\n", ft_atof(&argv[1]));
		return 1;
	}
	return 0;
}