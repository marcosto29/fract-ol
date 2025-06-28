/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:34:36 by marcos            #+#    #+#             */
/*   Updated: 2025/06/28 20:08:05 by marcos           ###   ########.fr       */
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
