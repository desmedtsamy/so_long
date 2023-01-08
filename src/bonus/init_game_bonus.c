/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:29:55 by samy              #+#    #+#             */
/*   Updated: 2023/01/08 16:08:09 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_value(t_map *map)
{
	int	y;
	int	x;

	x = -1;
	while (++x < map->row)
	{
		y = -1;
		while (++y < map->column)
		{
			if (map->map[x][y] == 'P')
			{
				map->spawn++;
				map->player.pos.x = x;
				map->player.pos.y = y;
			}
			if (map->map[x][y] == 'C')
				map->food++;
			if (map->map[x][y] == 'E')
				map->exit++;
			if (map->map[x][y] == 'G')
				map->number_enemies++;
		}
	}
}

void	init_ghosts(t_map *map)
{
	int	y;
	int	x;
	int	i;

	x = -1;
	i = 0;
	map->enemies = malloc(map->number_enemies * sizeof(t_enemy));
	if (!map->enemies)
		error("can't malloc", NULL);
	while (++x < map->row)
	{
		y = -1;
		while (++y < map->column)
		{
			if (map->map[x][y] == 'G')
			{
				map->enemies[i].pos.x = x;
				map->enemies[i].old_value = '0';
				map->enemies[i++].pos.y = y;
			}
		}
	}
}
