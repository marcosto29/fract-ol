/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:14:16 by marcos            #+#    #+#             */
/*   Updated: 2025/06/27 19:45:12 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef	struct	xWindow
{
	void	*win;
	int		heigth;
	int		width;
}	s_xWindow;

typedef	struct	xImage
{
	void	*img;
	int		heigth;
	int		width;
	int		bpp;
	int		sl;
	int		end;
}	s_xImage;

typedef struct	xScreen
{
	void		*mlx;
	s_xWindow	*xWin;
	s_xImage	*xImg;
}	s_xScreen;

# include "mlx.h"
# include "mlx_int.h"
# include "libft/libft.h"
# include "libft/libftprintf/libftprintf.h"
# include "libft/libftget_next_line/libftget_next_line.h"

#endif