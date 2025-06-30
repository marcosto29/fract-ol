/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:13:14 by marcos            #+#    #+#             */
/*   Updated: 2025/06/30 23:31:28 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

t_mandelbrot	*add_z(t_mandelbrot *z, t_mandelbrot *c)
{
	double	z_real;
	double	z_imaginary;
	double	c_real;
	double	c_imaginary;

	z_real = z->real;
	z_imaginary = z->imaginary;
	c_real = c->real;
	c_imaginary = c->imaginary;
	z->real = z_real + c_real;
	z->imaginary = z_imaginary + c_imaginary;
	return (z);
}

t_mandelbrot	*pow_z(t_mandelbrot *z)
{
	double	real;
	double	imaginary;

	real = z->real;
	imaginary = z->imaginary;
	z->real = pow(real, 2) - pow(imaginary, 2);
	z->imaginary = 2 * (real * imaginary);
	return (z);
}

int	check_mandelbrot(double x, double y)
{
	int				iterations;
	t_mandelbrot	*z;
	t_mandelbrot	*c;

	z = ft_calloc(sizeof(t_mandelbrot), 1);
	c = ft_calloc(sizeof(t_mandelbrot), 1);
	z->real = 0;
	z->imaginary = 0;
	c->real = x;
	c->imaginary = y;
	iterations = 0;
	while (iterations < 42)
	{
		z = add_z(pow_z(z), c);
		if ((z->real * z->real + z->imaginary * z->imaginary) > 4.0)
			return (iterations);
		iterations++;
	}
	return (0);
}

//map numbers formula
//this way numbers between (X and Y)
//will be transformed to numbers between (MX and MY)
//os = output_start
//oe = output_end
//is = input_start
//ie = input_end
//i = input
//os + ((oe - os) / (ie - is)) * (i - is)
int	mandelbrot(double x, int width, double y, int heigth)
{
	int	r;
	int	g;
	int	b;
	int	figure;

	x = x * 4.0 / width - 2.0;
	y = y * 4.0 / heigth - 2.0;
	figure = check_mandelbrot(x, y);	
	r = (figure * 50) % 256;
	g = (figure * 50) % 256;
	b = (figure * 50) % 256;
	return (r << 16 | g << 8 | b);
}

//change the img_position data to put it on different x
//*(unsigned int *)(img_position + (x_screen->x_img->bpp / 8) * X) = img_color
//Where X is the times the image is gonna be moved to the right
//substract to move to the left
void	draw_mandelbrot(t_x_screen *x_screen, int width, int heigth)
{
	double				x;
	double				y;
	int					color;
	unsigned int		img_color;
	char				*img_position;

	img_position = mlx_get_data_addr(x_screen->x_img->img,
			&(x_screen->x_img->bpp), &(x_screen->x_img->sl),
			&(x_screen->x_img->end));
	heigth = 500;
	width = 500;
	y = 0;
	while (y < heigth)
	{
		x = 0;
		while (x < width)
		{
			color = mandelbrot(x, width, y, heigth);
			img_color = mlx_get_color_value(x_screen->mlx, color);
			*(unsigned int *)img_position = img_color;
			x++;
			img_position += x_screen->x_img->bpp / 8;
		}
		//zoom in or zoom out the image
		//can change the X direction adding or deleting X explained on the upside
		img_position -= (x_screen->x_img->bpp / 8) * (int)x;
		img_position += x_screen->x_img->sl;
		y++;
	}
}

int	main(void)
{
	t_x_screen	*x_screen;

	x_screen = create_screen();
	x_screen->x_img = create_image(x_screen, 1000, 1000);
	if (!(x_screen->x_img))
		exit(1);
	draw_mandelbrot(x_screen, x_screen->x_img->width, x_screen->x_img->heigth);
	mlx_put_image_to_window(x_screen->mlx, x_screen->x_win->win,
		x_screen->x_img->img, 0, 0);
	mlx_loop(x_screen->mlx);
}
