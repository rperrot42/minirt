/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:35:55 by rperrot           #+#    #+#             */
/*   Updated: 2023/12/06 15:00:50 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	value_atoi( char **str, int signe)
{
	long long int	value;

	value = 0;
	while (ft_isdigit(**str))
	{
		value *= 10;
		value += **str - '0';
		if (value < 0)
		{
			errno = EINVAL;
		}
		(*str)++;
	}
	if (signe)
		value *= -1;
	return ((int)value);
}

int	ft_atoi(char **str)
{
	int	signe;

	signe = 0;
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	if (!ft_isdigit(**str))
	{
		errno = EINVAL;
		return (0);
	}
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			signe++;
		(*str)++;
	}
	return (value_atoi(str, signe));
}

t_bool	char_is_number(char *str)
{
	int	i;

	i = -1;
	if (str[i + 1] == '+' || str[i + 1] == '-')
		i++;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}
