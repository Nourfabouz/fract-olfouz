/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:42:41 by fabou-za          #+#    #+#             */
/*   Updated: 2022/06/16 14:06:46 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_handler2(int key, t_mlx_params *data)
{
	t_complex	cent;

	cent = (t_complex){data->view.x_max - data->view.x_min, \
		data->view.y_max - data->view.y_min};
	if (key == 123)
		data->view.move.re += cent.re / 10;
	if (key == 124)
		data->view.move.re -= cent.re / 10;
	if (key == 125)
		data->view.move.im -= cent.im / 10;
	if (key == 126)
		data->view.move.im += cent.im / 10;
}

int	key_handler1(int key, t_mlx_params *data)
{
	if (key == 8)
		change_color(data);
	if (key == 53)
		ft_close(data);
	if (key == 69)
		(data->view.precision) *= 2.0;
	if (key == 78)
		(data->view.precision) /= 2.0;
	key_handler2(key, data);
	if (key == 3)
		change_fract(data);
	if (key == 15)
		init_view(&data->view);
	fill_pixel(data);
	return (key);
}
