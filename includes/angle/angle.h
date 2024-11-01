/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:09:09 by sabitbol          #+#    #+#             */
/*   Updated: 2024/10/23 21:10:00 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANGLE_H
# define ANGLE_H
# include "struct.h"

float   get_angle_plan(t_point p, t_point q, t_plane *plan);
float	scalar_product(t_point a, t_point b);
#endif