/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:43:43 by tgibier           #+#    #+#             */
/*   Updated: 2023/10/26 10:43:44 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wonderland.h"
#include "display.h"
#include "error.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_world	world;

	printf("\e[?25l");
	if (argc != 2)
		return (printf("\e[?25h"), ft_error_msg(ERR, &argc, ARG, USG), 1);
	if (clean_init(&world))
		return (printf("\e[?25h"), 1);
	if (parsing(&world, argv) && printf("\e[?25h"))
		clean_exit(&world);
	if (loop(&world) && printf("\e[?25h"))
		clean_exit(&world);
	printf("\e[?25h");
	clean_exit(&world);
	return (1);
}
