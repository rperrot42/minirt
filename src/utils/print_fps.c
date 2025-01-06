/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:48:53 by rperrot           #+#    #+#             */
/*   Updated: 2025/01/06 17:07:50 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include "mlx.h"

void	ft_itoa_simple(int n, char *s);

void	printf_fps(t_scene *scene)
{
	char	fps_str[20];
	int		len_str_fps;

	ft_itoa_simple(scene->last_fps, fps_str);
	len_str_fps = ft_strlen(fps_str);
	fps_str[len_str_fps] = ' ';
	fps_str[len_str_fps + 1] = 'f';
	fps_str[len_str_fps + 2] = 'p';
	fps_str[len_str_fps + 3] = 's';
	fps_str[len_str_fps + 4] = 0;
	mlx_string_put(scene->mlx, scene->window, 10, 10, 0xFFFFFFF, fps_str);
}

void	ft_itoa_simple(int n, char *s)
{
	long int	long_n;
	int			i;

	long_n = (long int)n;
	i = 0;
	i += ft_len_number(n);
	s[i] = 0;
	if (long_n == 0)
		s[i - 1] = '0';
	while (long_n != 0)
	{
		i--;
		s[i] = long_n % 10 + '0';
		long_n /= 10;
	}
}
