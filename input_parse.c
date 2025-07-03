/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:09:51 by marcos            #+#    #+#             */
/*   Updated: 2025/07/03 20:24:01 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	show_input_error(void)
{
	char	*print;
	int		fd;

	fd = open("error.txt", O_RDONLY);
	print = get_next_line(fd);
	while (print && *print)
	{
		ft_printf("%s", print);
		free(print);
		print = get_next_line(fd);
	}
	close(fd);
	exit(1);
}

static char	**ft_strdup_double(int count, ...)
{
	char	**double_array;
	char	**aux;
	char	*simple_array;
	va_list	args;

	va_start(args, count);
	double_array = ft_calloc(sizeof(char *), count + 1);
	aux = double_array;
	while (count--)
	{
		simple_array = ft_strdup(va_arg(args, char *));
		*aux = simple_array;
		aux++;
	}
	va_end(args);
	return (double_array);
}

static int	valid_fractal_argument(char *arg)
{
	char	*aux_a;
	char	**valid_fractal_argument;
	char	**aux;
	int		count;

	count = 2;
	valid_fractal_argument = ft_strdup_double(count, "MANDELBROT", "JULIA");
	aux_a = arg;
	while (*aux_a)
	{
		*aux_a = ft_toupper(*aux_a);
		aux_a++;
	}
	aux = valid_fractal_argument;
	while (count--)
	{
		if (ft_strncmp(arg, *aux, ft_strlen(*aux)) == 0)
		{
			free_memory(valid_fractal_argument);
			return (0);
		}
		aux++;
	}
	ft_printf("Incorrect argument\n");
	return (free_memory(valid_fractal_argument), 1);
}

int	valid_double_argument(char *arg)
{
	char	*aux;

	aux = arg;
	if (*arg == '-' || *arg == '+')
		arg++;
	while (*arg)
	{
		if (*arg == '.' && ft_isdigit(*(arg + 1)) != 0)
			arg++;
		if (ft_isdigit(*arg) == 0)
			return (1);
		arg++;
	}
	if (ft_atod(aux) < -2.0 || ft_atod(aux) > 2.0)
		return (1);
	return (0);
}

void	input_parse(int argc, char *argv[])
{
	if (argc < 2 || argc > 4)
	{
		ft_printf("invalid number of arguments\n");
		show_input_error();
	}
	if (valid_fractal_argument(argv[1]) == 1)
		show_input_error();
	if (ft_strncmp(argv[1], "JULIA", ft_strlen("JULIA")) == 0)
	{
		if (!argv[2] || !argv[3])
		{
			ft_printf("invalid arguments for Julia fractal.\n");
			show_input_error();
		}
		if (valid_double_argument(argv[2]) == 1
			|| valid_double_argument(argv[3]) == 1)
		{
			ft_printf("invalid arguments for Julia fractal.\n");
			show_input_error();
		}
	}
}
