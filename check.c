/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-smed <sde-smed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:38:36 by sde-smed          #+#    #+#             */
/*   Updated: 2022/11/30 14:18:27 by sde-smed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	nb_row(char *path)
{
	int		fd;
	int		count;
	char	c;

	count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (read(fd, &c, 1))
		if (c == '\n')
			count++;
	close(fd);
	return (count + 1);
}

static char	**parse(int fd, int nb)
{
	char	**map;
	char	*row;
	int		i;

	i = 0;
	map = malloc(nb * sizeof(char *));
	row = get_next_line(fd);
	while (row)
	{
		map[i++] = row;
		row = get_next_line(fd);
	}
	close(fd);
	return (map);
}

static int	check_wall(t_map map)
{
	int	y;
	int	x;

	x = 0;

	while (x < map.column)
	{
		y = 0;
		while (y < map.row)
		{
			if ((x == 0 || x == map.column - 1) && map.map[x][y] != '1')
				return (-1);
			if ((y == 0 || y == map.row - 1) && map.map[x][y] != '1')
				return (-1);
			y++;
		}
		x++;
	}
	return (42);
}

void	start_check(char *path, t_map map)
{
	int	fd;

	if (ft_strrncmp(path, ".ber", 4))
		error("map should be a .ber");
	fd = open(path, O_RDONLY);
	if (fd <= 0)
		error("can't open map");
	map.row = nb_row(path);
	if (map.row <= 0)
		error("wrong number of row (%d)", map.row);
	map.map = parse(fd, map.row);
	map.column = ft_strlen(map.map[0]) - 1;

	if (check_wall(map) == -1)
	{
		free_map(map);
		error("map isn't ok");
	}
}
