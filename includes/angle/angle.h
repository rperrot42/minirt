/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:09:09 by sabitbol          #+#    #+#             */
/*   Updated: 2024/11/26 12:06:32 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANGLE_H
# define ANGLE_H
# include "struct.h"

float 	get_angle_plan(t_line l, t_plane *plan, float dot_product);
float	scalar_product(t_point a, t_point b);
t_point	normalize_vector(t_point vector);
t_line	get_line_2point(t_point *a, t_point *b);
int	point_between(t_point a, t_point b, t_point c);

#endif