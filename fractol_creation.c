/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_creation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:30:45 by marcos            #+#    #+#             */
/*   Updated: 2025/07/02 20:15:48 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_x_window	*create_window(t_x_screen *x_screen, int width,
			int heigth, char *name)
{
	t_x_window	*x_win;

	x_win = ft_calloc(sizeof(t_x_window), 1);
	x_win->width = width;
	x_win->heigth = heigth;
	x_win->win = mlx_new_window(x_screen->mlx, x_win->width, x_win->heigth,
			name);
	if (!(x_win->win))
		return (NULL);
	mlx_hook(x_win->win, 17, 1L << 1, &close_window, x_screen);
	mlx_hook(x_win->win, 2, 1L << 0, &key_event, x_screen);
	return (x_win);
}

void	show_image(t_x_screen *x_screen, int x_beginning, int y_beginning)
{
	x_screen->x_img->x_beginning = x_beginning;
	x_screen->x_img->y_beginning = y_beginning;
	mlx_put_image_to_window(x_screen->mlx, x_screen->x_win->win,
		x_screen->x_img->img, x_beginning, y_beginning);
}

t_x_image	*create_image(t_x_screen *x_screen, int width, int heigth)
{
	t_x_image	*x_img;

	x_img = ft_calloc(sizeof(t_x_image), 1);
	x_img->width = width;
	x_img->heigth = heigth;
	x_img->img = mlx_new_image(x_screen->mlx, x_img->heigth, x_img->width);
	if (!(x_img->img))
		return (NULL);
	return (x_img);
}

t_x_screen	*create_screen(int window_width, int window_heigth, char *name)
{
	t_x_screen	*x_screen;

	x_screen = ft_calloc(sizeof(t_x_screen), 1);
	x_screen->mlx = mlx_init();
	if (!(x_screen->mlx))
		exit(1);
	x_screen->x_win = create_window(x_screen, window_width,
			window_heigth, name);
	x_screen->x_win->name = name;
	if (!(x_screen->x_win))
		exit(1);
	return (x_screen);
}
