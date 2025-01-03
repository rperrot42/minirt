/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:22:41 by rperrot           #+#    #+#             */
/*   Updated: 2025/01/03 15:30:02 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

long	ft_clock();
void 	printf_fps(t_scene *scene);
float	second_degree_equation(float a, float b, float c);
t_point	parametric_equation(t_line l, float t);
void	unit_vector(t_point *v);

#endif
