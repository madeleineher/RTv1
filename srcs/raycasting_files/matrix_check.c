/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:47:57 by sabonifa          #+#    #+#             */
/*   Updated: 2019/11/07 15:48:01 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

float	m3_det(t_vec3 x, t_vec3 y, t_vec3 z)
{
	float	det;

	det = x.x * (y.y * z.z - y.z * z.y) \
		+ x.y * (z.x * y.z - y.x * z.z) \
		+ x.z * (y.x * z.y - z.x * y.y);
	return (det);
}
