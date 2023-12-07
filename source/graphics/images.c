/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:37:17 by ddemarco          #+#    #+#             */
/*   Updated: 2023/02/26 18:14:14 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

typedef struct s_image_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image_data;

void	set_pixle_loc(t_image_data *image, int x, int y, int color)
{
	char	*loc;

	loc = image->addr + (y * image->line_length + x
			* (image->bits_per_pixel / 8));
	*(int *)loc = color;
}

void	*generate_image(t_mlx *mlx)
{
	t_image_data	image;
	int				width;
	int				height;

	image.img = mlx_new_image(mlx->mlx, 1920, 1080);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	width = g_gamedata.map.width;
	height = g_gamedata.map.height;
	set_pixle_loc(&image, width / 2, height / 2, 0xABCDEF);
	return (image.img);
}
