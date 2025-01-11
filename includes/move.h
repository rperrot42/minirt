/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:23:51 by rperrot           #+#    #+#             */
/*   Updated: 2024/11/24 20:24:10 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# include "struct.h"
# include "include.h"

void	move_plane(t_scene *scene, int x, int y, int z);
int		all_deplacement(t_scene *scene, int deplacement);
int		key_press(int keycode, t_scene *scene);
int		key_release(int keycode, t_scene *scene);
void	rotation_obj(t_scene *scene, double rotation, t_coordinate rotate);
#endif
