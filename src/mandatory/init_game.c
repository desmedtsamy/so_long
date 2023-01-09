/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:29:55 by samy              #+#    #+#             */
/*   Updated: 2023/01/08 17:44:31 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_value(t_map *map, int x, int y)
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
