/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:14:16 by marcos            #+#    #+#             */
/*   Updated: 2025/06/28 19:37:01 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "mlx_int.h"
# include "libft/libft.h"
# include "libft/libftprintf/libftprintf.h"
# include "libft/libftget_next_line/libftget_next_line.h"

typedef	struct	x_window
{
	void	*win;
	int		heigth;
	int		width;
}	t_x_window;

typedef	struct	x_image
{
	void	*img;
	int		heigth;
	int		width;
	int		bpp;
	int		sl;
	int		end;
}	t_x_image;

typedef struct	x_screen
{
	void		*mlx;
	t_x_window	*x_win;
	t_x_image	*x_img;
}	t_x_screen;

void		free_image(t_x_screen *x_screen);
void		free_window(t_x_screen *x_screen);
void		free_screen(t_x_screen *x_screen);
int			close_window(t_x_screen *x_screen);
t_x_screen  *create_screen();
t_x_image	*create_image(t_x_screen *x_screen, int width, int heigth);
t_x_window	*create_window(t_x_screen *x_screen, int width, int heigth);
int			key_event(int key, t_x_screen *x_screen);

#endif