/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:13:14 by marcos            #+#    #+#             */
/*   Updated: 2025/06/28 19:40:22 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <math.h>

int	inside_figure(int x, int y)
{
	int	operation;

	operation = pow(((x - 250) - 5), 2) + pow(((y - 250) - 2), 2);
	if (10000 - operation > 0)
		return (1);
	return (0);
}

int	choose_color(int x, int width, int y, int heigth)
{
	int	r;
	int	g;
	int	b;
	int	figure;

	figure = inside_figure(x, y);
	if (figure == 0)
	{
		r = (y * 256 / width);
		g = (y * 256 / heigth) * pow(16, 2);
		b = (x * 256 / width) * pow(16, 4);
	}
	else
	{
		r = 0;
		g = 0;
		b = 0;
	}
	return (r + g + b);
}

void	draw_image(t_x_screen *x_screen, int width, int heigth)
{
	int					x;
	int					y;
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
			color = choose_color(x, width, y, heigth);
			img_color = mlx_get_color_value(x_screen->mlx, color);
			*(unsigned int *)img_position = img_color;
			x++;
			img_position += x_screen->x_img->bpp / 8;
		}
		y++;
	}
}

int	main(void)
{
	t_x_screen	*x_screen;

	x_screen = create_screen();
	x_screen->x_img = create_image(x_screen, 500, 500);
	if (!(x_screen->x_img))
		exit(1);
	draw_image(x_screen, x_screen->x_img->width, x_screen->x_img->heigth);
	mlx_put_image_to_window(x_screen->mlx, x_screen->x_win->win,
		x_screen->x_img->img, 0, 0);
	mlx_loop(x_screen->mlx);
}
