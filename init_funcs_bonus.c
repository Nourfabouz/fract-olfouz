/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_funcs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:44:28 by fabou-za          #+#    #+#             */
/*   Updated: 2022/06/17 19:22:47 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_view	init_view(t_view *view)
{
	view->x_min = -2;
	view->y_min = -2;
	view->x_max = 2;
	view->y_max = 2;
	view->width = 600;
	view->height = 600;
	view->zoom = 1;
	view->move = (t_complex){0, 0};
	view->mouse = (t_complex){-0.835f, -0.232f};
	view->zoom_factor = 1.05;
	view->c.re = -0.835f;
	view->c.im = -0.232f;
	view->precision = 50;
	return (*view);
}

void	init_mlx(t_mlx_params *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return ;
	init_view(&data->view);
	data->pause = 0;
	data->color_index = (t_color){1, 0, 2};
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->view.width, \
			data->view.height, "Fractals");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return ;
	}
	data->img.ptr = mlx_new_image(data->mlx_ptr, data->view.width, \
			data->view.height);
	data->img.buff = mlx_get_data_addr(data->img.ptr, \
			&(data->img.bits_per_pixel), &(data->img.size_line), \
			&(data->img.endian));
}
