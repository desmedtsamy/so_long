/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:01:45 by sde-smed          #+#    #+#             */
/*   Updated: 2023/01/09 11:34:31 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->row)
		free(map->map[i++]);
	free(map->map);
}

void	error(char *message, t_map *map)
{
	ft_printf("Error\n%s", message);
	if (map != NULL)
		free_map(map);
	exit(0);
}

void	set_default_sprites(t_game *game, t_sprites *sprites)
{
	int		s;

	s = SIZE;
	sprites->wall = mlx_xpm_file_to_image(game->mlx, WALL, &s, &s);
	sprites->food = mlx_xpm_file_to_image(game->mlx, FOOD, &s, &s);
	sprites->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &s, &s);
	sprites->empty = mlx_xpm_file_to_image(game->mlx, EMPTY, &s, &s);
	sprites->pacman = mlx_xpm_file_to_image(game->mlx, PACMAN, &s, &s);
}
