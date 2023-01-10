/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-smed <sde-smed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:29:55 by samy              #+#    #+#             */
/*   Updated: 2023/01/10 12:42:57 by sde-smed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_value(t_map *map, int x, int y)
{
	if (map->map[x][y] == 'P')
	{
		map->spawn++;
		map->player.pos.x = x;
		map->player.pos.y = y;
	}
	else if (map->map[x][y] == 'C')
		map->food++;
	else if (map->map[x][y] == 'E')
		map->exit++;
	else if (map->map[x][y] == 'G')
		map->number_enemies++;
	else if (map->map[x][y] != '0' && map->map[x][y] != '1')
		return (0);
	return (1);
}

int	init_value(t_map *map)
{
	int	y;
	int	x;

	x = -1;
	while (++x < map->row)
	{
		y = -1;
		while (++y < map->column)
			if (!check_value(map, x, y))
				return (0);
	}
	return (1);
}

void	init_enemies(t_map *map)
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
