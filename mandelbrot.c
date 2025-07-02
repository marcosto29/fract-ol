/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:18:01 by marcos            #+#    #+#             */
/*   Updated: 2025/07/02 23:09:04 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		{
			free(z);
			free(c);
			return (iterations);
		}
		iterations++;
	}
	free(z);
	free(c);
	return (0);
}

int	check_julia(double x, double y, double c_imaginary, double c_real)
{
	int				iterations;
	t_mandelbrot	*z;
	t_mandelbrot	*c;

	z = ft_calloc(sizeof(t_mandelbrot), 1);
	c = ft_calloc(sizeof(t_mandelbrot), 1);
	z->real = y;
	z->imaginary = x;
	c->real = c_imaginary;
	c->imaginary = c_real;
	iterations = 0;
	while (iterations < 42)
	{
		z = add_z(pow_z(z), c);
		if ((z->real * z->real + z->imaginary * z->imaginary) > 4.0)
		{
			free(z);
			free(c);
			return (iterations);
		}
		iterations++;
	}
	free(z);
	free(c);
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
	g = (figure * 0) % 256;
	b = (figure * 50) % 256;
	return (r << 16 | g << 8 | b);
}