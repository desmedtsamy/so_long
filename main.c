/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:43:21 by samy              #+#    #+#             */
/*   Updated: 2022/12/06 19:43:56 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	quit(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	exit(0);
}

void	render_map(t_game game)
{
	t_vector	p;
	int			size;
	void		*wall;
	void		*player;
	void		*food;
	void		*exit;

	p.x = 0;
	size = SIZE;
	wall = mlx_xpm_file_to_image(game.mlx, "./sprites/wall.xmp", &size, &size);
	player = mlx_xpm_file_to_image(game.mlx, "./sprites/pacman.xmp", &size, &size);
	food = mlx_xpm_file_to_image(game.mlx, "./sprites/food.xmp", &size, &size);
	exit = mlx_xpm_file_to_image(game.mlx, "./sprites/exit.xmp", &size, &size);
	mlx_clear_window(game.mlx, game.window);
	while (p.x < game.map.row)
	{
		p.y = 0;
		while (p.y < game.map.column)
		{
			if (game.map.map[p.x][p.y] == '1')
				mlx_put_image_to_window(game.mlx, game.window, wall, p.y * SIZE, p.x * SIZE);
			else if (game.map.map[p.x][p.y] == 'P')
				mlx_put_image_to_window(game.mlx, game.window, player, p.y * SIZE, p.x * SIZE);
			else if (game.map.map[p.x][p.y] == 'C')
				mlx_put_image_to_window(game.mlx, game.window, food, p.y * SIZE, p.x * SIZE);
			else if (game.map.map[p.x][p.y] == 'E')
				mlx_put_image_to_window(game.mlx, game.window, exit, p.y * SIZE, p.x * SIZE);
			p.y++;
		}
		p.x++;
	}
	mlx_destroy_image(game.mlx, wall);
	mlx_destroy_image(game.mlx, player);
	mlx_destroy_image(game.mlx, food);
	mlx_destroy_image(game.mlx, exit);
	ft_printf("%d\n", game.moves);
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
	render_map(*game);
}

int	deal_keys(int keycode, void *param)
{
	t_game		*game;
	t_vector	pos;
	char		str[42];

	game = (t_game *)param;
	if (keycode == 53)
		quit(param);
	if (keycode == 124)
		move(0, 1, game);
	if (keycode == 123)
		move(0, -1, game);
	if (keycode == 126)
		move(-1, 0, game);
	if (keycode == 125)
		move(1, 0, game);
	return (0);
}

void	put_image(t_game game)
{
	int		size;
	void	*img;

	size = SIZE;
	img = mlx_xpm_file_to_image(game.mlx, "./sprites/pacman.xmp", &size, &size);
	mlx_put_image_to_window(game.mlx, game.window, img, 400, 300);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		error("no map in arguments");
	if (argc > 2)
		error("to much arguments");
	start_check(argv[1], &game.map);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.map.column * SIZE, game.map.row * SIZE, "pacman_42");
	game.moves = 0;
	mlx_key_hook(game.window, deal_keys, &game);
	mlx_hook(game.window, DESTROYNOTIFY, 0, quit, &game);
	render_map(game);
	mlx_loop(game.mlx);
	return (0);
}
