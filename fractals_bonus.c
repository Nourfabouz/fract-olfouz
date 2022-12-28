/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:57:02 by fabou-za          #+#    #+#             */
/*   Updated: 2022/06/15 11:57:05 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pixel	mandelbrot_set(int x, int y, t_view *view)
{
	t_pixel		pixel;
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	double		i;

	i = 0;
	z = (t_complex){0, 0};
	c = get_complex(x, y, view);
	while (z.re * z.re + z.im * z.im < 4 && i < view->precision)
	{
		temp.re = z.re * z.re - z.im * z.im + c.re;
		temp.im = z.re * z.im * 2 + c.im;
		if (z.re == temp.re && z.im == temp.im)
		{
			i = view->precision;
			break ;
		}
		z.re = temp.re;
		z.im = temp.im;
		i++;
	}
	pixel = (t_pixel){z, i};
	return (pixel);
}

t_pixel	julia_set(int x, int y, t_view *view)
{
	t_pixel		pixel;
	t_complex	z;
	t_complex	temp;
	double		i;

	i = 0;
	z = get_complex(x, y, view);
	while ((z.re * z.re + z.im * z.im < 4) && i < view->precision)
	{
		temp.re = z.re * z.re - z.im * z.im + view->c.re;
		temp.im = z.re * z.im * 2 + view->c.im;
		if (z.re == temp.re && z.im == temp.im)
		{
			i = view->precision;
			break ;
		}
		z.re = temp.re;
		z.im = temp.im;
		i++;
	}
	pixel.coord = z;
	pixel.iteration = i;
	return (pixel);
}

t_pixel	burningship_set(int x, int y, t_view *view)
{
	t_pixel		pixel;
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	double		i;

	i = 0;
	z = (t_complex){0, 0};
	c = get_complex(x, y, view);
	while (z.re * z.re + z.im * z.im < 4 && i < view->precision)
	{
		temp.re = fabs(z.re * z.re - z.im * z.im + c.re);
		temp.im = fabs(z.re * z.im * 2 + c.im);
		if (z.re == temp.re && z.im == temp.im)
		{
			i = view->precision;
			break ;
		}
		z.re = temp.re;
		z.im = temp.im;
		i++;
	}
	pixel = (t_pixel){z, i};
	return (pixel);
}
