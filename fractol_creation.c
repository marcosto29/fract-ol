/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_creation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:30:45 by marcos            #+#    #+#             */
/*   Updated: 2025/06/28 20:08:23 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_x_window	*create_window(t_x_screen *x_screen, int width, int heigth)
{
	t_x_window	*x_win;

	x_win = ft_calloc(sizeof(t_x_window), 1);
	x_win->width = width;
	x_win->heigth = heigth;
	x_win->win = mlx_new_window(x_screen->mlx, x_win->width, x_win->heigth,
			"Fractal window");
	if (!(x_win->win))
		return (NULL);
	mlx_hook(x_win->win, 17, 1L << 1, close_window, x_screen);
	mlx_hook(x_win->win, 2, 1L << 0, key_event, x_screen);
	return (x_win);
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

t_x_screen  *create_screen()
{
    t_x_screen  *x_screen;

    x_screen = ft_calloc(sizeof(t_x_screen), 1);
	x_screen->mlx = mlx_init();
	if (!(x_screen->mlx))
		exit(1);
	x_screen->x_win = create_window(x_screen, 500, 500);
	if (!(x_screen->x_win))
		exit(1);
    return(x_screen);
}