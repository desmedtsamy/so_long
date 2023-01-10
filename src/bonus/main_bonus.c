/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-smed <sde-smed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:43:21 by samy              #+#    #+#             */
/*   Updated: 2023/01/10 12:30:57 by sde-smed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	quit(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_destroy_image(game->mlx, game->sprites.empty);
	mlx_destroy_image(game->mlx, game->sprites.food);
	mlx_destroy_window(game->mlx, game->window);
	free_map(&game->map);
	exit (0);
	return (0);
}

static int	update(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->map.player.new_direction != 42 && game->frames++ == FRAMES)
	{
		update_enemies(game);
		update_player(game);
		game->frames = 0;
		render_map_2(game);
	}
	return (0);
}

static int	deal_keys(int key, void *param)
{
	t_game		*game;
	t_vector	pos;
	char		str[42];

	game = (t_game *)param;
	if (key == 53)
		quit(param);
	if (key == 2 || key == 0 || key == 13 || key == 1)
	{
		if (game->map.player.new_direction != key)
		{
			game->map.player.old_direction = game->map.player.new_direction;
			game->map.player.new_direction = key;
			game->moves++;
			ft_printf("%d\n", game->moves);
		}
	}
	return (0);
}

static void	init_game(t_game *game, char *path)
{
	game->mlx = mlx_init();
	game->path = path;
	game->update = 0;
	game->frames = 0;
	game->map.player.new_direction = 42;
	game->map.player.current_direction = 42;
	game->map.player.old_direction = 42;
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
	init_game(&game, argv[1]);
	col = game.map.column * SIZE;
	row = game.map.row * SIZE + 20;
	game.window = mlx_new_window(game.mlx, col, row, "pacman_42");
	game.moves = 0;
	set_default_sprites(&game, &game.sprites);
	mlx_key_hook(game.window, deal_keys, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_hook(game.window, DESTROYNOTIFY, 0, quit, &game);
	render_map(&game);
	mlx_loop(game.mlx);
	return (0);
}
