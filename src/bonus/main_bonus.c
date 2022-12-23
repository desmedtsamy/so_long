/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:43:21 by samy              #+#    #+#             */
/*   Updated: 2022/12/23 17:59:32 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	quit(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	exit (0);
	return (0);
}

void	exit_game(void *param, char *str)
{
	ft_printf("\n%s", str);
	// free param
	exit (0);
}

int	can_move_enemy(t_game *game, t_enemy enemy, int x, int y)
{
	char	pos;

	pos = game->map.map[enemy.pos.x + x][enemy.pos.y + y];
	if (pos == '1' || pos == 'E' || pos == 'G')
		return (0);
	return (1);
}

void	move_enemy(t_game *game, t_enemy *enemy, int x, int y)
{
	game->map.map[enemy->pos.x][enemy->pos.y] = enemy->old_value;
	enemy->old_value = game->map.map[enemy->pos.x + x][enemy->pos.y + y];
	if (enemy->old_value == 'P')
		exit_game(game, "You have been eaten");
	game->map.map[enemy->pos.x + x][enemy->pos.y + y] = 'G';
	enemy->pos.x = enemy->pos.x + x;
	enemy->pos.y = enemy->pos.y + y;
}

void	update_enemies(t_game *game)
{
	int			i;
	t_enemy		*enemy;
	t_vector	player;

	i = -1;
	player = game->map.player;
	while (++i < game->map.number_enemies)
	{
		enemy = &game->map.enemies[i];
		if (enemy->pos.x < player.x && can_move_enemy(game, *enemy, 1, 0))
			move_enemy(game, enemy, 1, 0);
		else if (enemy->pos.x > player.x && can_move_enemy(game, *enemy, -1, 0))
			move_enemy(game, enemy, -1, 0);
		else if (enemy->pos.y > player.y && can_move_enemy(game, *enemy, 0, -1))
			move_enemy(game, enemy, 0, -1);
		else if (enemy->pos.y < player.y && can_move_enemy(game, *enemy, 0, 1))
			move_enemy(game, enemy, 0, 1);
	}
}

int	update(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->frames++ == 5000)
	{
		update_enemies(game);
		render_map(game);
		game ->frames = 0;
	}
	return (0);
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
			exit_game(game, "You win");
		return ;
	}
	if (game->map.map[player.x + x][player.y + y] == 'G')
		exit_game(game, "You have been eaten");
	if (game->map.map[player.x + x][player.y + y] == 'C')
		game->map.food--;
	game->map.map[player.x][player.y] = '0';
	game->map.map[player.x + x][player.y + y] = 'P';
	game->map.player.x = player.x + x;
	game->map.player.y = player.y + y;
	player.x = game->map.player.x;
	player.y = game->map.player.y;
	game->moves++;
	ft_printf("%d\n", game->moves);
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
	game.frames = 0;
	game.path = argv[1];
	col = game.map.column * SIZE;
	row = game.map.row * SIZE + 15;
	game.window = mlx_new_window(game.mlx, col, row, "pacman_42");
	game.moves = 0;
	mlx_key_hook(game.window, deal_keys, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_hook(game.window, DESTROYNOTIFY, 0, quit, &game);
	render_map(&game);
	mlx_loop(game.mlx);
	return (0);
}
