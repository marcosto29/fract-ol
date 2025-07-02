/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:13:14 by marcos            #+#    #+#             */
/*   Updated: 2025/07/02 23:31:24 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

//the first argument is the name of the fractal
//if the fractal is julia it will read the following
int	main(int argc, char *argv[])
{
	(void)argc;
	t_x_screen			*x_screen;
	t_fractal_config	*config;

	config = ft_calloc(sizeof(t_fractal_config), 1);
	config->zoom = 1.0;
	config->x_mouse = 0;
	config->y_mouse = 0;
	config->name = ft_strdup(argv[1]);
	config->x = ft_atod(argv[2]);
	config->y = ft_atod(argv[3]);
	x_screen = create_screen(1000, 1000, config->name);
	x_screen->x_img = create_image(x_screen, 500, 500);
	if (!(x_screen->x_img))
	{
		free(config->name);
		free(config);
		exit(1);
	}
	x_screen->x_img->config = config;
	draw_fractal(x_screen, x_screen->x_img->width,
		x_screen->x_img->heigth, config);
	show_image(x_screen, 0, 0);
	mlx_mouse_hook(x_screen->x_win->win, mouse_event, x_screen);
	mlx_loop(x_screen->mlx);
}
