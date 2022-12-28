/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:01:17 by fabou-za          #+#    #+#             */
/*   Updated: 2022/06/13 15:02:28 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map_to_color(int color, int old_range_max, \
		double range_min, double range_max)
{
	double	range;

	range = range_max - range_min;
	return (color * (range / old_range_max) + range_min);
}

t_complex	get_complex(int x, int y, t_view *view)
{
	double		range_re;
	double		range_im;
	t_complex	number;

	range_re = (view->x_max + view->move.re) - (view->x_min + view->move.re);
	range_im = (view->y_max + view->move.im) - (view->y_min + view->move.im);
	number.re = x * (range_re / view->width) + (view->x_min + view->move.re);
	number.im = y * (range_im / view->height) + (view->y_min + view->move.im);
	return (number);
}
