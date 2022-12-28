/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:46:45 by fabou-za          #+#    #+#             */
/*   Updated: 2022/06/16 14:30:41 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_move(int x, int y, t_mlx_params *data)
{
	if (data->pause == 0 && data->view.fract == 2)
	{
		data->view.c.re = x / (data->view.width / \
				(data->view.x_max - data->view.x_min)) + data->view.x_min;
		data->view.c.im = y / (data->view.height / \
				(data->view.y_max - data->view.y_min)) + data->view.y_min;
	}
	fill_pixel(data);
	return (1);
}

void	julia_pause(int key, t_mlx_params *data)
{
	if (key == 3)
	{
		if (data->pause == 0)
			data->pause = 1;
		else
			data->pause = 0;
	}
}

int	zoom_control(int key, int x, int y, t_mlx_params *data)
{
	double	zoom_factor;

	data->view.mouse.re = x / (data->view.width / \
			(data->view.x_max - data->view.x_min)) + data->view.x_min;
	data->view.mouse.im = y / (data->view.height / \
			(data->view.y_max - data->view.y_min)) + data->view.y_min;
	zoom_factor = 1.05;
	if (data->view.fract == 2)
		julia_pause(key, data);
	if (key == 5)
	{
		data->view.zoom /= zoom_factor;
		apply_zoom(&data->view, 1.0 / zoom_factor);
	}
	else if (key == 4)
	{
		data->view.zoom *= zoom_factor;
		apply_zoom(&data->view, zoom_factor);
	}
	fill_pixel(data);
	return (0);
}

void	apply_zoom(t_view *view, double zoom_factor)
{
	view->x_min = view->mouse.re - (zoom_factor * \
			(view->mouse.re - view->x_min));
	view->x_max = view->mouse.re + (zoom_factor * \
			(view->x_max - view->mouse.re));
	view->y_min = view->mouse.im - (zoom_factor * \
			(view->mouse.im - view->y_min));
	view->y_max = view->mouse.im + (zoom_factor * \
			(view->y_max - view->mouse.im));
}
