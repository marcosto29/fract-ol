/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:13:14 by marcos            #+#    #+#             */
/*   Updated: 2025/06/26 21:18:55 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <math.h>

int	closeWindow(s_xScreen *xScreen)
{
	printf("Closing...\n");
	mlx_clear_window(xScreen->mlx, xScreen->win);
	mlx_destroy_window(xScreen->mlx, xScreen->win);
	exit (0);
}

int keyEvent(int key, s_xScreen *xScreen)
{
	if (key == 0xff1b)
		closeWindow(xScreen);
	return (1);
}

void	drawWindow(s_xScreen *xScreen)
{
	int	x = -200;
	int y;

	while (x <= 200)
	{
		y = 3 + sqrt(10000 - pow((x - 2), 2));
		mlx_pixel_put(xScreen->mlx, xScreen->win, x + 200, y + 200, 0xFFFFFF);
		y = 3 - sqrt(10000 - pow((x - 2), 2));
		mlx_pixel_put(xScreen->mlx, xScreen->win, x + 200, y + 200, 0xFFFFFF);
		x++;
	}
}

int	main()
{
    s_xScreen	*xScreen;

	xScreen = ft_calloc(sizeof(s_xScreen *), 1);
	if (!(xScreen->mlx = mlx_init()))
		exit(1);
	if (!(xScreen->win = mlx_new_window(xScreen->mlx, 500, 500, "Window title")))
		exit(1);

	drawWindow(xScreen);
	//manage the window close event
	mlx_hook(xScreen->win, 17, 1L << 1, closeWindow, xScreen);
	mlx_hook(xScreen->win, 2, 1L << 0, keyEvent, xScreen);
	//function needed to listen to events
	mlx_loop(xScreen->mlx);
}
