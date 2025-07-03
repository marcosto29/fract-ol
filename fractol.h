/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:14:16 by marcos            #+#    #+#             */
/*   Updated: 2025/07/03 17:37:14 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"
# include "libftprintf.h"
# include "libftget_next_line.h"
# include <math.h>
# include <limits.h>
# include <float.h>

typedef struct fractal
{
	double	imaginary;
	double	real;
}	t_fractal;

typedef struct x_window
{
	void	*win;
	int		heigth;
	int		width;
}	t_x_window;

typedef struct fractal_config
{
	double	zoom;
	char	*name;
	int		x_mouse;
	int		y_mouse;
	double	x;
	double	y;
	int		r_percentage;
	int		g_percentage;
	int		b_percentage;
}	t_fractal_config;

typedef struct x_image
{
	void				*img;
	int					heigth;
	int					width;
	int					bpp;
	int					sl;
	int					end;
	int					x_beginning;
	int					y_beginning;
	t_fractal_config	*config;
}	t_x_image;

typedef struct x_screen
{
	void		*mlx;
	t_x_window	*x_win;
	t_x_image	*x_img;
}	t_x_screen;

void					input_parse(int argc, char *argv[]);
void					free_image(t_x_screen *x_screen);
void					free_window(t_x_screen *x_screen);
void					free_screen(t_x_screen *x_screen);
void					free_memory(char **double_array);
int						close_window(t_x_screen *x_screen);
t_fractal_config		*configurate_fractal(char *argv[]);
t_x_screen				*create_screen(int window_width,
							int window_heigth, char *name);
void					show_image(t_x_screen *x_screen,
							int x_beginning, int y_beginning);
t_x_image				*create_image(t_x_screen *x_screen,
							int width, int heigth);
t_x_window				*create_window(t_x_screen *x_screen, int width,
							int heigth, char *name);
int						key_event(int key, t_x_screen *x_screen);
int						mouse_event(int mouse, int x, int y,
							t_x_screen *context);
void					draw_fractal(t_x_screen *x_screen,
							t_fractal_config *config);
double					world_to_image(double wl_beginning, double l_size,
							double coordinate);
void					colors_value(t_fractal_config *config,
							int r, int g, int b);
int						fractal(double x, double y, t_x_screen *x_screen);

#endif