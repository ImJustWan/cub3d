/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:37:44 by mrony             #+#    #+#             */
/*   Updated: 2023/11/03 13:32:27 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "wonderland.h"

# define ERR "\1\033[1m\2\1\033[38;5;127m\2Error\n\1\033[0m\2"

// general error message
# define MAL "Malloc error"
# define PAR "Parsing"

// File related error 
# define OPN "Opening file"
# define ARG "Incorrect number of arguments"
# define USG "Usage: ./cub3d [scene_description_file.cub]"
# define CUB "\1\033[1m\2Incorect file extension\1\033[0m\2"

// description file content error
# define IDF "\1\033[1m\2Invalid scene description file\1\033[0m\2"
# define EMP "Empty File"
# define UKN "Unknown identifyier"

	// Map errors
# define IMP "\1\033[1m\2Invalid map\1\033[0m\2"
# define NPL "No player on the map"
# define MPL "Too many players on the map"
# define WAL "The map is not enclosed by walls"
# define EMF "Error on map file"

	// Textures & colors errors
# define IFL "\1\033[1m\2Invalid file\1\033[0m\2"
# define XPM "Incorrect file extension"
# define COL "Invalid colors"
# define MSC "Missing color(s)"
# define MTX "Missing texture(s)"
# define IID "Invalid identifyier"
# define MFP "Missing identifyier or file path"
# define MIF "Too many information"
# define DPX "Duplicate texture assignment"

void	ft_error_msg(char *err, int *ptr, char *arg, char *str);

#endif