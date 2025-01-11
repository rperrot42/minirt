/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:22:59 by rperrot           #+#    #+#             */
/*   Updated: 2025/01/11 18:23:28 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	key_press(int keycode, t_scene *scene)
{
	if (keycode == KEY_ESC)
		free_scene(scene);
	else if (keycode == KEY_W)
		scene->press_key.w_press = true;
	else if (keycode == KEY_S)
		scene->press_key.s_press = true;
	else if (keycode == KEY_A)
		scene->press_key.a_press = true;
	else if (keycode == KEY_D)
		scene->press_key.d_press = true;
	else if (keycode == KEY_SP)
		scene->press_key.sp_press = true;
	else if (keycode == KEY_TAB)
		scene->press_key.tab_press = true;
	return (0);
}

int	key_release(int keycode, t_scene *scene)
{
	if (keycode == KEY_W)
		scene->press_key.w_press = false;
	else if (keycode == KEY_S)
		scene->press_key.s_press = false;
	else if (keycode == KEY_A)
		scene->press_key.a_press = false;
	else if (keycode == KEY_D)
		scene->press_key.d_press = false;
	else if (keycode == KEY_SP)
		scene->press_key.sp_press = false;
	else if (keycode == KEY_TAB)
		scene->press_key.tab_press = false;
	return (0);
}
