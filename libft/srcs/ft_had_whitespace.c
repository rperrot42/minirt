/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_had_whitespace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:49:34 by rperrot           #+#    #+#             */
/*   Updated: 2024/10/16 19:52:04 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

t_bool	ft_had_whitespace(char *str)
{
	while (*str)
	{
		if (((*str) < 7	|| (*str) > 13) && (*str) != 32)
			return (false);
		str++;
	}
	return (true);
}