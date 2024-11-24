/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:42:51 by sabitbol          #+#    #+#             */
/*   Updated: 2024/11/24 18:26:14 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "angle.h"
#include <math.h>

float	scalar_product(t_point a, t_point b)
{
	float	a_norm = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	float	b_norm = sqrt(b.x * b.x + b.y * b.y + b.z * b.z);
	return ((a.x / a_norm) * (b.x / b_norm) + (a.y / a_norm) * (b.y / b_norm) + (a.z / a_norm) * (b.z / b_norm));
}
