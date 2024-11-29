/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:38:55 by rperrot           #+#    #+#             */
/*   Updated: 2024/11/29 15:38:55 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

long	ft_atoif_toint(char *string);

long	ft_clock()
{
	char	time[100];
	int		fd;

	fd = open("/proc/uptime", O_RDONLY);
	if (fd == -1)
		return (-1);
	if (read(fd, time, 100) < 0)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return ft_atoif_toint(time);
}

long ft_atoif_toint(char *string)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while ((string[i] >= '0' && string[i] <= '9') || string[i] == '.')
	{
		if (string[i] != '.')
			res = res * 10 + string[i] - '0';
		i++;
	}
	return (res);
}