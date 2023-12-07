/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:13:40 by ddemarco          #+#    #+#             */
/*   Updated: 2023/02/26 17:16:32 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	render_sprite(t_mlx *mlx, void *sprite, t_vector2d vector)
{
	return (mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			sprite, vector.x, vector.y));
}
