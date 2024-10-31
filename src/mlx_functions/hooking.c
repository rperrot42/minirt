/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:29:15 by sabitbol          #+#    #+#             */
/*   Updated: 2024/10/31 12:52:40 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "error.h"
#include "stdlib.h"

int	close_win(int keycode, t_scene *scene)
{
	if (keycode == 65307)
	{
		free_scene(scene);
		exit(0);
	}
	return (0);
}
