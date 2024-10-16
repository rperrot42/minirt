/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:36:53 by rperrot           #+#    #+#             */
/*   Updated: 2024/10/16 00:53:49 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int ft_realoc(void **ptr, short *size, int size_struct, void *new_object)
{
	char *new_ptr;

	new_ptr = malloc(((*size) + 1) * size_struct);
	if (!new_ptr)
		return (1);
	ft_memmove(new_ptr, *ptr, (*size) * size_struct);
	free(*ptr);
	*ptr = new_ptr;
	ft_memmove(new_ptr + ((*size) * size_struct), new_object, size_struct);
	(*size)++;
	return (0);
}