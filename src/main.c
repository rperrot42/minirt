/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:24:17 by rperrot           #+#    #+#             */
/*   Updated: 2024/10/16 01:13:41 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "error.h"
#include  "mini_rt.h"
#include "parsing.h"

int main()
{
	int *oui;
	int test;

	oui = malloc(sizeof(char *) * 2);
	oui[0] = 1;
	oui[1] = 0;
	test = 2;
	ft_realoc((void **)&oui, &test);
	printf("%d\n", oui[0]);
	printf("%d\n", oui[1]);
	printf("%d\n", oui[2]);
	free(oui);
	return (0);
}