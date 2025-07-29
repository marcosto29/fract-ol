/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:13:14 by marcos            #+#    #+#             */
/*   Updated: 2025/07/03 17:47:58 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

//the first argument is the name of the fractal
//if the fractal is julia it will read the following
int	main(int argc, char *argv[])
{
	t_x_screen			*x_screen;
	t_fractal_config	*config;

	input_parse(argc, argv);
	config = configurate_fractal(argv);
	x_screen = create_screen(1000, 1000, config->name);
	x_screen->x_img = create_image(x_screen, 1000, 1000);
	if (!(x_screen->x_img))
	{
		free(config->name);
		free(config);
		exit(1);
	}
	x_screen->x_img->config = config;
	draw_fractal(x_screen, config);
	show_image(x_screen, 0, 0);
	mlx_loop(x_screen->mlx);
}
