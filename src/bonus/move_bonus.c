/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:19:37 by samy              #+#    #+#             */
/*   Updated: 2023/01/08 16:09:02 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	{
		ft_printf("\nyou were eaten");
		quit(game);
	}
	game->map.map[enemy->pos.x + x][enemy->pos.y + y] = 'G';
	enemy->pos.x = enemy->pos.x + x;
	enemy->pos.y = enemy->pos.y + y;
}

void	move(int x, int y, t_game *game)
{
	t_vector	player;

	player = game->map.player.pos;
	game->map.player.old_pos = player;
	if (game->map.map[player.x + x][player.y + y] == '1')
		return ;
	if (game->map.map[player.x + x][player.y + y] == 'E')
	{
		if (game->map.food == 0)
		{
			ft_printf("You win");
			quit(game);
		}
		return ;
	}
	if (game->map.map[player.x + x][player.y + y] == 'C')
		game->map.food--;
	game->map.map[player.x][player.y] = '0';
	game->map.map[player.x + x][player.y + y] = 'P';
	game->map.player.pos.x = player.x + x;
	game->map.player.pos.y = player.y + y;
}

void	update_player(t_game *game)
{

}

void	update_enemies(t_game *game)
{
	int			i;
	t_enemy		*enemy;
	t_vector	player;

	i = -1;
	player = game->map.player.pos;
	while (++i < game->map.number_enemies)
	{
		enemy = &game->map.enemies[i];
		enemy->old_pos = enemy->pos;
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
