/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:30:12 by rperrot           #+#    #+#             */
/*   Updated: 2024/10/15 19:31:43 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool	find_signe(const char **str);

static float	error_atof(void);

static void		divide_value(int decimal, float *value);

float	ft_atof(const char **str)
{
	float	value;
	t_bool	neg;
	int		decimal;

	value = 0;
	decimal = 0;
	neg = find_signe(str);
	if (!ft_isdigit(**str))
		return (error_atof());
	while (ft_isdigit(**str) || **str == '.')
	{
		if (**str == '.')
		{
			if (decimal)
				return (error_atof());
			decimal = 1;
		}
		else
			value = value * 10 + (**str) - '0';
		(*str)++;
		if (decimal)
			decimal++;
	}
	divide_value(decimal, &value);
	return (value * ((int)(!neg - neg)));
}

static void	divide_value(int decimal, float *value)
{
	int	i;

	i = 2;
	while (i < decimal)
	{
		*value = *value / 10;
		i++;
	}
}

static t_bool	find_signe(const char **str)
{
	t_bool	neg;

	neg = false;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			neg = true;
		(*str)++;
	}
	return (neg);
}

static float	error_atof(void)
{
	errno = EINVAL;
	return (0);
}
