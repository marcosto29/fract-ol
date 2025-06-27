/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:13:14 by marcos            #+#    #+#             */
/*   Updated: 2025/06/27 20:01:53 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <math.h>

s_xWindow	*createWindow(s_xScreen *xScreen, int width, int heigth)
{
	s_xWindow 	*xWin;

	xWin = ft_calloc(sizeof(s_xWindow *), 1);
	xWin->width = width;
	xWin->heigth = heigth;
	if(!(xWin->win = mlx_new_window(xScreen->mlx, xWin->heigth, xWin->width, "Window title")))
		return (NULL);
	return(xWin);
}

s_xImage	*createImage(s_xScreen *xScreen, int width, int heigth)
{
	s_xImage 	*xImg;

	xImg = ft_calloc(sizeof(s_xImage *), 1);
	xImg->width = width;
	xImg->heigth = heigth;
	if(!(xImg->img = mlx_new_image(xScreen->mlx, xImg->heigth, xImg->width)))
		return (NULL);
	return(xImg);
}

int	closeWindow(s_xScreen *xScreen)
{
	printf("Closing...\n");
	mlx_clear_window(xScreen->mlx, xScreen->xWin->win);
	mlx_destroy_window(xScreen->mlx, xScreen->xWin->win);
	exit (0);
}

int keyEvent(int key, s_xScreen *xScreen)
{
	if (key == 0xff1b)
		closeWindow(xScreen);
	return (1);
}

int	chooseColor(int x, int width, int y, int heigth)
{
	int	r;
	int	g;
	int	b;

	r = ((x * y) * 256 / width);
	g = (x * 256 / heigth) * pow(16, 2);
	b = (x * 256 / width) * pow(16, 4);
	return (r + g + b);
}

void	drawImage(s_xScreen *xScreen, int width, int heigth)
{
	int					x;
	int					y;
	int					color;
	unsigned int		imgColor;
	char				*imgPositon;

	imgPositon = mlx_get_data_addr(xScreen->xImg->img, &(xScreen->xImg->bpp), &(xScreen->xImg->sl), &(xScreen->xImg->end));
	y = 0;
	while (y < heigth)
	{
		x = 0;
		while (x < width)
		{
			color = chooseColor(x, width, y, heigth);
			imgColor = mlx_get_color_value(xScreen->mlx, color);
			*(unsigned int *)imgPositon = imgColor;
			x++;
			imgPositon += xScreen->xImg->bpp / 8;
		}
		y++;
	}
}

int	main()
{
    s_xScreen	*xScreen;

	xScreen = ft_calloc(sizeof(s_xScreen *), 1);
	if (!(xScreen->mlx = mlx_init()))
		exit(1);
	if (!(xScreen->xWin = createWindow(xScreen, 500, 500)))
		exit(1);
	if (!(xScreen->xImg = createImage(xScreen, 250, 250)))
		exit(1);
	drawImage(xScreen, xScreen->xImg->width, xScreen->xImg->heigth);
	mlx_put_image_to_window(xScreen->mlx, xScreen->xWin->win, xScreen->xImg->img, 0, 0);
	//manage the window close event
	mlx_hook(xScreen->xWin->win, 17, 1L << 1, closeWindow, xScreen);
	mlx_hook(xScreen->xWin->win, 2, 1L << 0, keyEvent, xScreen);
	//function needed to listen to events
	mlx_loop(xScreen->mlx);
}
