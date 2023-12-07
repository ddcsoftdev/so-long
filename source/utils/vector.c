/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:21:58 by ddemarco          #+#    #+#             */
/*   Updated: 2023/03/11 18:23:39 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_vector2d	create_vector2d(int y, int x)
{
	t_vector2d	vector;

	vector.y = y;
	vector.x = x;
	return (vector);
}

t_vector2d	substract_vector(t_vector2d v1, t_vector2d v2)
{
	t_vector2d	result;

	result.y = v1.y - v2.y;
	result.x = v1.x - v2.x;
	return (result);
}

t_vector2d	add_vector(t_vector2d v1, t_vector2d v2)
{
	t_vector2d	result;

	result.y = v1.y + v2.y;
	result.x = v1.x + v2.x;
	return (result);
}

int	compare_vector(t_vector2d v1, t_vector2d v2)
{
	int	result;
	int	compare;

	compare = v1.y - v2.y;
	if (compare < 0)
	compare = v2.y - v1.y;
	result = v1.x - v2.x;
	if (result < 0)
	result = v2.x - v1.x;
	if (result > compare)
		result = compare;
	return (result);
}

int	is_equal_vector(t_vector2d v1, t_vector2d v2)
{
	if (v1.y == v2.y && v1.x == v2.x)
		return (1);
	return (0);
}
