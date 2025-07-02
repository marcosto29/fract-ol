/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:34:36 by marcos            #+#    #+#             */
/*   Updated: 2025/07/02 23:10:07 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_x_screen *x_screen)
{
	printf("Closing...\n");
	free_screen(x_screen);
	exit (0);
}

int	key_event(int key, t_x_screen *x_screen)
{
	if (key == 0xff1b)
		close_window(x_screen);
	return (1);
}

//safe the point of the mouse before zoom
//apply zoom to check where is goona be
//substract the difference so that when the offset is applied
//the point is gonna stay on the same or close to the place it was
int	mouse_event(int mouse, int x, int y, t_x_screen *x_screen)
{
	double				b_x;
	double				b_y;
	t_fractal_config	*config;

	config = x_screen->x_img->config;
	b_x = (world_to_image(x_screen->x_img->x_beginning,
				x_screen->x_img->width, x) / config->zoom) + config->x_mouse;
	b_y = (world_to_image(x_screen->x_img->y_beginning,
				x_screen->x_img->heigth, y) / config->zoom) + config->y_mouse;
	if (mouse == 4)
		config->zoom *= 1.1;
	else if (mouse == 5)
		config->zoom /= 1.1;
	config->x_mouse = b_x - (b_x / config->zoom);
	config->y_mouse = b_y - (b_y / config->zoom);
	draw_fractal(x_screen, x_screen->x_img->width,
		x_screen->x_img->heigth, config);
	show_image(x_screen, x_screen->x_img->x_beginning,
		x_screen->x_img->y_beginning);
	return (1);
}
