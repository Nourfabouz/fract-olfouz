/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:45:47 by fabou-za          #+#    #+#             */
/*   Updated: 2022/06/16 14:32:48 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_color
{
	int	i;
	int	j;
	int	k;
}				t_color;

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_pixel
{
	t_complex	coord;
	int			iteration;
}				t_pixel;

typedef struct s_img
{
	void	*ptr;
	char	*buff;
	int		bits_per_pixel;
	int		endian;
	int		size_line;
}				t_img;

typedef struct s_view
{
	double		x_max;
	double		x_min;
	double		y_max;
	double		y_min;
	int			width;
	int			height;
	int			fract;
	double		zoom;
	double		zoom_factor;
	int			precision;
	t_complex	mouse;
	t_complex	c;
	t_pixel		pix;
	int			color;
	t_complex	move;
}				t_view;

typedef struct mlx_params
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*add;
	t_img	img;
	int		pause;
	t_color	color_index;	
	t_view	view;
}				t_mlx_params;

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

t_complex	get_complex(int x, int y, t_view *view);
t_pixel		fractal(t_point *point, t_view *view);
t_pixel		mandelbrot_set(int x, int y, t_view *view);
t_pixel		burningship_set(int x, int y, t_view *view);
t_pixel		julia_set(int x, int y, t_view *view);
t_view		init_view(t_view *view);
void		coloring_pixel(t_mlx_params *data, t_pixel *pix, t_point *point);
void		fill_pixel(t_mlx_params *data);
void		menu(void);
void		change_fract(t_mlx_params *data);
void		change_color(t_mlx_params *data);
void		init_mlx(t_mlx_params *data);
int			zoom_control(int key, int x, int y, t_mlx_params *data);
double		map_to_color(int color, int old_range_max, \
		double range_min, double range_max);
void		apply_zoom(t_view *view, double zoom_factor);
int			key_handler1(int key, t_mlx_params *data);
int			mouse_move(int x, int y, t_mlx_params *data);
int			ft_close(t_mlx_params *data);
int			mouse_hook(int mousecode, int x, int y, t_mlx_params *data);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_putstr(char *s);
int			ft_atoi(const char *str);
void		julia_pause(int key, t_mlx_params *data);

#endif
