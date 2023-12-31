/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:37:51 by mrony             #+#    #+#             */
/*   Updated: 2023/11/03 14:10:21 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "wonderland.h"
# include "error.h"
# include <limits.h>

# define FAIL 1
# define SUCCESS 0

# define TRUE 1
# define FALSE 0

// parsing.c
int		parsing(t_world *world, char **argv);

// parsing_read.c
int		file_name(char **argv);
int		read_file(char **argv, t_list **read);

// parsing_map.c
t_list	*isolate_map(t_list *read, t_list *map);
char	**map_fill(char **map, t_list *map_lst, int size);
char	**build_map(t_world *world, t_list *map_lst);
int		parsing_map(t_world *world, t_list *read);

// parsing_map_checks.c
int		check_surroundings(char **map, int i, int j);
int		player_info(t_world *world, char **map, int i, int j);
int		map_verif(t_world *world, char **map, int i, int j);

// parsing_description.c
int		parsing_description(t_world *world, t_list *read);

// parsing_des_textures.c
int		texture_save(t_world *world, char **split);

// parsing_description_clean.c
t_list	*remove_empty_lines(t_list *read);
void	remove_newline(t_list *read);

// parsing_description_colors.c
int		color_save(t_world *world, char **split);

// // utils.c
int		empty_line(char *str);
int		map_size(t_list *map_lst);
int		ft_table_size(char **table);
void	ft_del_node(t_list *lst, void (*del)(void*));
void	free_split(char **split);

// int	file_access(char *path);
// // parsing_read.c
// int	check_description(t_world *world, t_list *read);

// // content.c
// // int	check_content(t_world *world, t_list **read);

// hat_list_functions.c
// void	ft_add_back_hat(t_hat **hat, t_hat *new);
// int		ft_hat_size(t_hat *node);
// t_hat	*ft_hatnew(char *index, char *path, int *rgb);
// t_hat	*ft_hatlast(t_hat *node);

// typedef struct s_hat
// {
// 	char			*index;
// 	char			*path;
// 	int				*rgb;
// 	struct s_hat	*prev;
// 	struct s_hat	*next;
// }	t_hat;
#endif