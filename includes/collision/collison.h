/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collison.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrot <rperrot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:40:45 by rperrot           #+#    #+#             */
/*   Updated: 2024/10/23 14:45:22 by rperrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define COLLISON_H
# include "struct.h"
# include "include.h"
t_point intersection_plane_line(t_line *line, t_new_plane *plane);

#endif //MINIRT_COLLISON_H
