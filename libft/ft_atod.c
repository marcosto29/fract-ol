/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 23:11:16 by marcos            #+#    #+#             */
/*   Updated: 2025/07/03 20:25:43 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(const char *nptr)
{
	int		first_part;
	double	second_part;
	double	number;
	int		negative;

	number = 0.0;
	negative = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == 43 || *nptr == 45)
	{
		if (*nptr == 45)
			negative = -1;
		nptr++;
	}
	first_part = ft_atoi(nptr);
	while (ft_isdigit(*nptr))
		nptr++;
	nptr++;
	second_part = ft_atoi(nptr);
	number += first_part;
	while (second_part >= 1)
		second_part /= 10;
	number += second_part;
	return (number * negative);
}
