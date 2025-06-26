/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:14:16 by marcos            #+#    #+#             */
/*   Updated: 2025/06/26 20:29:30 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct	xScreen
{
	void	*mlx;
	void	*win;
	void	*img;
}	s_xScreen;

# include "mlx.h"
# include "mlx_int.h"
# include "libft/libft.h"
# include "libft/libftprintf/libftprintf.h"

#endif