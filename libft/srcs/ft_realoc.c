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

t_bool	ft_realoc(void **ptr, void *new_object)
{
	size_t	size;
	void	*ptr_value;

	size = 0;
	ptr_value = *ptr;
	while (((char *)(*ptr))[size])
		size++;
	*ptr = malloc(sizeof(char  *) * (size + 2));
	printf(" %p %p\n" , *ptr, ptr_value);
	if (!*ptr)
	{
		free(ptr_value);
		return false;
	}
	(void)new_object;
	ft_memmove(*ptr, ptr_value, size);
	*(ptr + size) = (char *)new_object;
	free(ptr_value);
	*(ptr + size + 1) = NULL;
	return true;
}
