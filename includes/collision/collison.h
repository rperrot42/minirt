/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collison.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:40:45 by rperrot           #+#    #+#             */
/*   Updated: 2024/10/25 18:42:04 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define COLLISON_H
# include "struct.h"
# include "include.h"
t_point intersection_plane_line(t_line *line, t_plane *plane);

#endif //MINIRT_COLLISON_H
