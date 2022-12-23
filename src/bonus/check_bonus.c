/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:38:36 by sde-smed          #+#    #+#             */
/*   Updated: 2022/12/23 17:46:36 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static char	**parse(int fd, int nb_row)
{
	char	**map;
	int		nb_col;
	int		i;

	i = 0;
	map = malloc(nb_row * sizeof(char *));
	if (!map)
		return (NULL);
	map[i] = get_next_line(fd);
	nb_col = ft_strlen(map[i]);
	while (++i < nb_row)
	{
		map[i] = get_next_line(fd);
		if (ft_strlen(map[i]) != nb_col || i == nb_row - 1)
		{
			if (i != nb_row - 1 || (ft_strlen(map[i]) != nb_col - 1))
			{
				while (i >= 0)
					free(map[i--]);
				error("map isn't a rectangle\n", NULL);
			}
		}
	}
	return (map);
}

static void	init_value(t_map *map)
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
				map->player.x = x;
				map->player.y = y;
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

void	check_file(char *path, t_map *map)
{
	int		fd;

	if (ft_strrncmp(path, ".ber", 4))
		error("map should be a .ber\n", NULL);
	fd = open(path, O_RDONLY);
	if (fd <= 0)
		error("can't open map\n", NULL);
	map->row = nb_row(path);
	if (map->row == 0)
		error("Empty file\n", NULL);
	map->map = parse(fd, map->row);
	if (map->map <= 0)
		error("error while parsing\n", NULL);
	map->column = ft_strlen(map->map[0]) - 1;
	init_value(map);
}

static void	init_ghosts(t_map *map)
{
	int	y;
	int	x;
	int	i;

	x = -1;
	i = 0;
	map->enemies = malloc(map->number_enemies * sizeof(t_enemy));
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

void	start_check(char *path, t_map *map)
{
	check_file(path, map);
	map->spawn = 0;
	map->food = 0;
	map->exit = 0;
	map->enemies = 0;
	init_value(map);
	init_ghosts(map);
	if (check_wall(*map) == -1)
		error("wall isn't ok\n", map);
	if (map->food == 0)
		error("no food found\n", map);
	if (map->exit == 0)
		error("no exit found\n", map);
	if (map->exit > 1)
		error("too much exit found\n", map);
	if (map->spawn == 0)
		error("no player found\n", map);
	if (map->spawn > 1)
		error("too much player found\n", map);
	if (!can_win(*map))
		error("can't access to all food or exit\n", map);
}
