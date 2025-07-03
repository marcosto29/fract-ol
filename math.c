/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:39:29 by marcos            #+#    #+#             */
/*   Updated: 2025/07/03 17:44:40 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	world_to_image(double wl_beginning, double l_size, double coordinate)
{
	if (coordinate <= wl_beginning)
		return (0);
	if (coordinate >= wl_beginning + l_size)
		return (l_size);
	return (coordinate - wl_beginning);
}

void	colors_value(t_fractal_config *config, int r, int g, int b)
{
	config->r_percentage += r;
	config->g_percentage += g;
	config->b_percentage += b;
}
