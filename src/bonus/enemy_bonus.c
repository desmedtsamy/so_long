/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:19:37 by samy              #+#    #+#             */
/*   Updated: 2023/01/08 16:37:37 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	can_move_enemy(t_game *game, t_enemy enemy, int x, int y)
{
	char	pos;

	pos = game->map.map[enemy.pos.x + x][enemy.pos.y + y];
	if (pos == '1' || pos == 'E' || pos == 'G')
		return (0);
	return (1);
}

static void	move_enemy(t_game *game, t_enemy *enemy, int x, int y)
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
