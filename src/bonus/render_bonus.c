/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:53:52 by sde-smed          #+#    #+#             */
/*   Updated: 2023/01/08 17:35:40 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print(t_vector pos, t_game *game, t_sprites *sprites, char val)
{
	int	r;
	int	c;

	r = pos.y * SIZE;
	c = pos.x * SIZE;
	if (val == '1')
		mlx_put_image_to_window(game->mlx, game->window, sprites->wall, r, c);
	else if (val == 'P')
		mlx_put_image_to_window(game->mlx, game->window, sprites->pacman, r, c);
	else if (val == 'C')
		mlx_put_image_to_window(game->mlx, game->window, sprites->food, r, c);
	else if (val == 'E')
		mlx_put_image_to_window(game->mlx, game->window, sprites->exit, r, c);
	else if (val == 'G')
		mlx_put_image_to_window(game->mlx, game->window, sprites->enemy, r, c);
	else if (val == '0')
		mlx_put_image_to_window(game->mlx, game->window, sprites->empty, r, c);
}

void	print_score(t_game game)
{
	char	*moves;
	int		pos;

	moves = ft_itoa(game.moves);
	pos = game.map.row * SIZE + 10;
	mlx_string_put(game.mlx, game.window, 10, pos, 0xccccff, moves);
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
			print(p, game, &game->sprites, game->map.map[p.x][p.y]);
		p.x++;
	}
	print_score(*game);
	mlx_destroy_image(game->mlx, game->sprites.pacman);
	mlx_destroy_image(game->mlx, game->sprites.enemy);
	mlx_destroy_image(game->mlx, game->sprites.wall);
	mlx_destroy_image(game->mlx, game->sprites.exit);
}

void	render_map_2(t_game *game)
{
	t_vector	player;
	int			i;
	t_enemy		enemy;
	char		old_pos_value;

	player = game->map.player.pos;
	set_sprites(game, &game->sprites);
	i = -1;
	while (++i < game->map.number_enemies)
	{
		enemy = game->map.enemies[i];
		old_pos_value = game->map.map[enemy.old_pos.x][enemy.old_pos.y];
		print(enemy.old_pos, game, &game->sprites, '0');
		if (old_pos_value != '0')
			print(enemy.old_pos, game, &game->sprites, old_pos_value);
		print(enemy.pos, game, &game->sprites, 'G');
	}
	print(game->map.player.old_pos, game, &game->sprites, '0');
	print(player, game, &game->sprites, 'P');
	i = game->map.row * SIZE;
	mlx_put_image_to_window(game->mlx, game->window, game->sprites.empty, 0, i);
	print_score(*game);
	mlx_destroy_image(game->mlx, game->sprites.pacman);
	mlx_destroy_image(game->mlx, game->sprites.enemy);
}
