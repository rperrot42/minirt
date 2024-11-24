/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:09:09 by sabitbol          #+#    #+#             */
/*   Updated: 2024/11/24 18:25:43 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANGLE_H
# define ANGLE_H
# include "struct.h"

float 	get_angle_plan(t_line l, t_plane *plan, float dot_product);
float	scalar_product(t_point a, t_point b);
t_point	normalize_vector(t_point vector);
#endif