/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:12:57 by marcos            #+#    #+#             */
/*   Updated: 2025/07/02 23:10:20 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//zoom in - out
//x / 2, y / 2 <- double the size x / 0.5, y / 0.5 <- half the size
//add to x and y to move in the axis x + 10, y + 10
void	draw_fractal(t_x_screen *x_screen, int width,
					int heigth, t_fractal_config *config)
{
	double				x;
	double				y;
	int					color;
	unsigned int		img_color;
	char				*img_position;

	img_position = mlx_get_data_addr(x_screen->x_img->img,
			&(x_screen->x_img->bpp), &(x_screen->x_img->sl),
			&(x_screen->x_img->end));
	y = 0;
	while (y < heigth)
	{
		x = 0;
		while (x < width)
		{
			color = mandelbrot((x / config->zoom) + config->x_mouse, width,
					(y / config->zoom) + config->y_mouse, heigth);
			img_color = mlx_get_color_value(x_screen->mlx, color);
			*(unsigned int *)img_position = img_color;
			x++;
			img_position += x_screen->x_img->bpp / 8;
		}
		y++;
	}
}
