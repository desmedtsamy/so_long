/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:53:52 by sde-smed          #+#    #+#             */
/*   Updated: 2023/01/05 10:12:56 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print(int x, int y, t_game *game, t_sprites *sprites, char c)
{
	int	w;
	int	h;

	w = y * SIZE;
	h = x * SIZE;
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->window, sprites->wall, w, h);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->window, sprites->pacman, w, h);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->window, sprites->food, w, h);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->window, sprites->exit, w, h);
	else if (c == 'G')
		mlx_put_image_to_window(game->mlx, game->window, sprites->enemy, w, h);
}

void	set_default_sprites(t_game *game, t_sprites *sprites)
{
	int		s;

	s = SIZE;
	sprites->wall = mlx_xpm_file_to_image(game->mlx, WALL, &s, &s);
	sprites->food = mlx_xpm_file_to_image(game->mlx, FOOD, &s, &s);
	sprites->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &s, &s);
	sprites->empty = mlx_xpm_file_to_image(game->mlx, EMPTY, &s, &s);
}

void	set_sprites(t_game *game, t_sprites *sprites)
{
	int		s;

	s = SIZE;
	if (game->direction == 42)
	{
		sprites->pacman = mlx_xpm_file_to_image(game->mlx, PACMAN_CLOSE, &s, &s);
		sprites->enemy = mlx_xpm_file_to_image(game->mlx, GHOST, &s, &s);
	}
	else if (game->update == 1)
	{
		if (game->direction == 2)
			sprites->pacman = mlx_xpm_file_to_image(game->mlx, PACMAN_SEMI_RIGHT, &s, &s);
		else if (game->direction == 0)
			sprites->pacman = mlx_xpm_file_to_image(game->mlx, PACMAN_SEMI_LEFT, &s, &s);
		else if (game->direction == 13)
			sprites->pacman = mlx_xpm_file_to_image(game->mlx, PACMAN_SEMI_UP, &s, &s);
		else if (game->direction == 1)
			sprites->pacman = mlx_xpm_file_to_image(game->mlx, PACMAN_SEMI_DOWN, &s, &s);
		else
			sprites->pacman = mlx_xpm_file_to_image(game->mlx, WALL, &s, &s);
		sprites->enemy = mlx_xpm_file_to_image(game->mlx, GHOST, &s, &s);
		game->update = 2;
	}
	else if (game->update == 2)
	{
		if (game->direction == 2)
			sprites->pacman = mlx_xpm_file_to_image(game->mlx, PACMAN_OPEN_RIGHT, &s, &s);
		else if (game->direction == 0)
			sprites->pacman = mlx_xpm_file_to_image(game->mlx, PACMAN_OPEN_LEFT, &s, &s);
		else if (game->direction == 13)
			sprites->pacman = mlx_xpm_file_to_image(game->mlx, PACMAN_OPEN_UP, &s, &s);
		else if (game->direction == 1)
			sprites->pacman = mlx_xpm_file_to_image(game->mlx, PACMAN_OPEN_DOWN, &s, &s);
		sprites->enemy = mlx_xpm_file_to_image(game->mlx, GHOST_2, &s, &s);
		game->update = 0;
	}
	else
	{
		sprites->pacman = mlx_xpm_file_to_image(game->mlx, PACMAN_CLOSE, &s, &s);
		sprites->enemy = mlx_xpm_file_to_image(game->mlx, GHOST, &s, &s);
		game->update = 1;
	}
}

void	print_score(t_game game)
{
	char	*moves;
	int		pos;

	moves = ft_itoa(game.moves);
	pos = game.map.row * SIZE + 10;
	mlx_string_put(game.mlx, game.window, 10, pos, 0xccccff, moves);
	mlx_string_put(game.mlx, game.window, 42, pos, 0xccccff, game.path);
}

void	render_map(t_game *game)
{
	t_vector	p;
	int			s;

	s = SIZE;
	p.x = 0;
	set_sprites(game, &game->sprites);
	while (p.x < game->map.row)
	{
		p.y = -1;
		while (++p.y < game->map.column)
			print(p.x, p.y, game, &game->sprites, game->map.map[p.x][p.y]);
		p.x++;
	}
	print_score(*game);
	mlx_destroy_image(game->mlx, game->sprites.pacman);
	mlx_destroy_image(game->mlx, game->sprites.enemy);
}

void	render_map_2(t_game *game)
{
	t_vector	player;
	int			i;
	t_enemy		enemy;

	player = game->map.player;
	set_sprites(game, &game->sprites);
	i = -1;
	while (++i < 5)
	{
		enemy = game->map.enemies[i];
		mlx_put_image_to_window(game->mlx, game->window, game->sprites.empty, enemy.old_pos.y * SIZE, enemy.old_pos.x * SIZE);
		print(enemy.pos.x, enemy.pos.y, game, &game->sprites, 'G');
	}
	mlx_put_image_to_window(game->mlx, game->window, game->sprites.empty, game->map.old_pos.y * SIZE, game->map.old_pos.x * SIZE);
	print(player.x, player.y, game, &game->sprites, 'P');
	print_score(*game);
	//regler le fait que les chifre s'ecrit sur les autres
	mlx_destroy_image(game->mlx, game->sprites.pacman);
	mlx_destroy_image(game->mlx, game->sprites.enemy);
}
