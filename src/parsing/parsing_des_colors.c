/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_des_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:38:27 by mrony             #+#    #+#             */
/*   Updated: 2023/10/26 10:38:28 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_atoi_cub(const char *nptr)
{
	long	res;
	int		count;

	count = 0;
	res = 0;
	while ((*nptr >= 8 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			return (-1);
		nptr++;
	}
	if (*nptr < '0' || *nptr > '9')
		return (-1);
	while (*nptr >= 48 && *nptr <= 57)
	{
		res = res * 10 + *nptr - 48;
		nptr++;
		count++;
	}
	if (res > __INT_MAX__ || count > 11)
		return (-1);
	return ((int)res);
}

int	ft_encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	color_save(t_world *world, char **split)
{
	char	**colors;
	int		r;
	int		g;
	int		b;

	colors = ft_split(split[1], ',');
	if (!colors)
		return (ft_error_msg(ERR, NULL, IFL, MAL), FAIL);
	if (ft_table_size(colors) != 3)
		return (ft_free(colors), ft_error_msg(ERR, NULL, IFL, MSC), FAIL);
	r = ft_atoi_cub(colors[0]);
	g = ft_atoi_cub(colors[1]);
	b = ft_atoi_cub(colors[2]);
	if (r < 0 || b < 0 || g < 0)
		return (ft_free(colors), ft_error_msg(ERR, NULL, IFL, COL), FAIL);
	if (strcmp(split[0], "C\0"))
		world->setup->c = ft_encode_rgb(r, g, b);
	else if (strcmp(split[0], "F\0"))
		world->setup->f = ft_encode_rgb(r, g, b);
	else
		return (ft_free(colors), ft_error_msg(ERR, NULL, IID, COL), FAIL);
	ft_free(colors);
	return (SUCCESS);
}
