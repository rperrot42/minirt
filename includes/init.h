/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:28:08 by sabitbol          #+#    #+#             */
/*   Updated: 2024/10/24 14:06:35 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

int init_window(t_scene *scene);
void	hooking(t_scene *scene);

#  ifdef __APPLE__
	int mlx_destroy_display(void *ptr);
# endif
#endif