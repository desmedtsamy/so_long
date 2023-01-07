/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:48:27 by samy              #+#    #+#             */
/*   Updated: 2023/01/05 15:27:01 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	can_access(int x, int y, char **map)
{
	char	pos;

	pos = map[x][y];
	if (pos == '1' || pos == 'P')
		return (0);
	map[x][y] = 'P';
	if (pos == 'E')
		return (0);
	return (1);
}

static int	is_finish(char **map, int row, int column)
{
	int	y;
	int	x;

	x = 0;
	while (x < row)
	{
		y = 0;
		while (y < column)
		{
			if (map[x][y] == 'C')
				return (0);
			if (map[x][y] == 'E')
				return (0);
			y++;
		}
		x++;
	}
	return (42);
}

static char	**check_access(int x, int y, char **map)
{
	if (can_access(x - 1, y, map))
		check_access(x - 1, y, map);
	if (can_access(x, y - 1, map))
		check_access(x, y - 1, map);
	if (can_access(x + 1, y, map))
		check_access(x + 1, y, map);
	if (can_access(x, y + 1, map))
		check_access(x, y + 1, map);
	return (map);
}

int	can_win(t_map map)
{
	int		finish;
	int		i;
	char	**cpy;

	finish = 0;
	cpy = malloc(map.row * sizeof(char *));
	if (!cpy)
		error("can't malloc the cpy\n", &map);
	i = -1;
	while (++i < map.row)
		cpy[i] = ft_strdup(map.map[i]);
	check_access(map.player.x, map.player.y, cpy);
	finish = is_finish(cpy, map.row, map.column);
	i = -1;
	while (++i < map.row)
		free(cpy[i]);
	free(cpy);
	return (finish);
}

int	check_wall(t_map map)
{
	int	y;
	int	x;

	x = 0;
	while (x < map.row)
	{
		y = 0;
		while (y < map.column)
		{
			if ((x == 0 || x == map.row - 1) && map.map[x][y] != '1')
				return (-1);
			if ((y == 0 || y == map.column - 1) && map.map[x][y] != '1')
				return (-1);
			y++;
		}
		x++;
	}
	return (42);
}
