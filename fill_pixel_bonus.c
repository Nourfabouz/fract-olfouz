/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pixel_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:39:17 by fabou-za          #+#    #+#             */
/*   Updated: 2022/06/18 15:53:32 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_color(t_mlx_params *data)
{
	int	temp;

	temp = data->color_index.i;
	data->color_index.i = data->color_index.j;
	data->color_index.j = data->color_index.k;
	data->color_index.k = temp;
}

void	coloring_pixel(t_mlx_params *data, t_pixel *pix, t_point *point)
{
	int	color;
	int	pixel;

	pixel = 0;
	color = map_to_color(pix->iteration, data->view.precision, 0, 255);
	if (pix->iteration == data->view.precision)
		color = 0;
	pixel = (point->y * data->img.size_line) + (point->x * 4);
	data->img.buff[pixel + data->color_index.i] = map_to_color(color \
			* color, 255 * 255 * 255, 0, 255);
	data->img.buff[pixel + data->color_index.j] = color;
	data->img.buff[pixel + data->color_index.k] = map_to_color(sqrt(color), \
			sqrt(255), 0, 255);
	data->img.buff[pixel + 3] = 0;
}

void	fill_pixel(t_mlx_params *data)
{
	t_point	point;
	t_pixel	pix;

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	point.y = 0;
	while (point.y < data->view.height)
	{
		point.x = 0;
		while (point.x < data->view.width)
		{
			pix = fractal(&point, &data->view);
			coloring_pixel(data, &pix, &point);
			point.x++;
		}
		point.y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
}
