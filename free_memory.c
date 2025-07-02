/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:37:46 by marcos            #+#    #+#             */
/*   Updated: 2025/07/02 20:10:45 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_image(t_x_screen *x_screen)
{
	mlx_destroy_image(x_screen->mlx, x_screen->x_img->img);
	free(x_screen->x_img->config->name);
	free(x_screen->x_img->config);
	free (x_screen->x_img);
}

void	free_window(t_x_screen *x_screen)
{
	mlx_clear_window(x_screen->mlx, x_screen->x_win->win);
	mlx_destroy_window(x_screen->mlx, x_screen->x_win->win);
	free (x_screen->x_win);
}

void	free_screen(t_x_screen *x_screen)
{
	mlx_loop_end(x_screen->mlx);
	if (x_screen->x_img)
		free_image(x_screen);
	if (x_screen->x_win)
		free_window(x_screen);
	mlx_destroy_display(x_screen->mlx);
	free (x_screen);
}
