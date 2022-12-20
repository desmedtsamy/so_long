/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:43:21 by samy              #+#    #+#             */
/*   Updated: 2022/12/19 14:51:58 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	exit(0);
}

void	move(int x, int y, t_game *game)
{
	t_vector	player;

	player.x = game->map.player.x;
	player.y = game->map.player.y;
	if (game->map.map[player.x + x][player.y + y] == '1')
		return ;
	if (game->map.map[player.x + x][player.y + y] == 'E')
	{
		if (game->map.food == 0)
		{
			ft_printf("\nYou win\n");
			quit(&game);
		}
		return ;
	}
	if (game->map.map[player.x + x][player.y + y] == 'C')
		game->map.food--;
	game->map.map[player.x][player.y] = '0';
	game->map.map[player.x + x][player.y + y] = 'P';
	game->map.player.x = player.x + x;
	game->map.player.y = player.y + y;
	player.x = game->map.player.x;
	player.y = game->map.player.y;
	game->moves++;
	render_map(game);
}

int	deal_keys(int keycode, void *param)
{
	t_game		*game;
	t_vector	pos;
	char		str[42];

	game = (t_game *)param;
	if (keycode == 53)
		quit(param);
	if (keycode == 124 || keycode == 2)
		move(0, 1, game);
	if (keycode == 123 || keycode == 0)
		move(0, -1, game);
	if (keycode == 126 || keycode == 13)
		move(-1, 0, game);
	if (keycode == 125 || keycode == 1)
		move(1, 0, game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		col;
	int		row;

	if (argc < 2)
		error("no map in arguments", NULL);
	if (argc > 2)
		error("to much arguments", NULL);
	start_check(argv[1], &game.map);
	game.mlx = mlx_init();
	col = game.map.column * SIZE;
	row = game.map.row * SIZE + 42;
	game.window = mlx_new_window(game.mlx, col, row, "pacman_42");
	game.moves = 0;
	mlx_key_hook(game.window, deal_keys, &game);
	mlx_hook(game.window, DESTROYNOTIFY, 0, quit, &game);
	render_map(&game);
	mlx_loop(game.mlx);
	return (0);
}
