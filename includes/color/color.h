/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:18:04 by sabitbol          #+#    #+#             */
/*   Updated: 2024/10/25 20:19:24 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
#include "struct.h"

int	create_trgb(int t, int r, int g, int b);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);
t_color	get_multiple_color(t_color obj, t_color light);
int color_to_int(t_color color);
#endif