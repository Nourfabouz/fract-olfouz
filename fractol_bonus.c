/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:43:38 by fabou-za          #+#    #+#             */
/*   Updated: 2022/06/17 19:12:25 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(t_mlx_params *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

void	change_fract(t_mlx_params *data)
{
	if (data->view.fract == 3)
		data->view.fract = 1;
	else
		(data->view.fract += 1);
}

void	menu(void)
{
	ft_putstr("For Mandelbrot_set use the key 1\n");
	ft_putstr("For julia_set use the key 2\n");
	ft_putstr("For Burningship_set use the key 3\n");
}

t_pixel	fractal(t_point *point, t_view *view)
{
	t_pixel	pix;

	if (view->fract == 1)
		(pix = mandelbrot_set(point->x, point->y, view));
	else if (view->fract == 2)
		pix = julia_set(point->x, point->y, view);
	else if (view->fract == 3)
		pix = burningship_set(point->x, point->y, view);
	else
	{
		menu();
		exit(1);
	}
	return (pix);
}

int	main(int argc, char **argv)
{
	t_mlx_params	data;

	if (argc != 2 || ((ft_strcmp(argv[1], "1") != 0) \
				&& (ft_strcmp(argv[1], "2") != 0) && \
				(ft_strcmp(argv[1], "3") != 0)))
	{
		ft_putstr("Invalid arguments.\n");
		ft_putstr("Correct format: [./fractol_bonus <keycode of fractal>].\n");
		menu();
		exit (1);
	}
	init_mlx(&data);
	data.view.fract = ft_atoi(argv[1]);
	fill_pixel(&data);
	mlx_key_hook(data.win_ptr, key_handler1, &data);
	mlx_mouse_hook(data.win_ptr, zoom_control, &data);
	mlx_hook(data.win_ptr, 6, 0, &mouse_move, &data);
	mlx_hook(data.win_ptr, 17, 0L, ft_close, &data);
	mlx_loop(data.mlx_ptr);
}
