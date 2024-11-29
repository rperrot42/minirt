/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:42:51 by sabitbol          #+#    #+#             */
/*   Updated: 2024/11/29 09:46:20 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "angle.h"
#include <math.h>

float	scalar_product(t_point a, t_point b)
{
	return ((a.x * b.x + a.y * b.y + a.z * b.z) / (sqrt(a.x * a.x + a.y * a.y + a.z * a.z) * sqrt(b.x * b.x + b.y * b.y + b.z * b.z)));
}

//Scalar product with normalized vectors