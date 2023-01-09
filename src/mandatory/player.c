/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:36:29 by samy              #+#    #+#             */
/*   Updated: 2023/01/08 17:44:39 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move(int x, int y, t_game *game)
{
	t_vector	player;

	player = game->map.player.pos;
	game->map.player.old_pos = player;
	if (game->map.map[player.x + x][player.y + y] == '1')
		return (0);
	if (game->map.map[player.x + x][player.y + y] == 'E')
	{
		if (game->map.food == 0)
		{
			ft_printf("You win");
			quit(game);
		}
		return (0);
	}
	if (game->map.map[player.x + x][player.y + y] == 'C')
		game->map.food--;
	game->map.map[player.x][player.y] = '0';
	game->map.map[player.x + x][player.y + y] = 'P';
	game->map.player.pos.x = player.x + x;
	game->map.player.pos.y = player.y + y;
	return (1);
}

static int	move_player(t_game *game, int direction)
{
	int	moved;

	moved = 0;
	if (direction == 2)
		moved = move(0, 1, game);
	if (direction == 0)
		moved = move(0, -1, game);
	if (direction == 13)
		moved = move(-1, 0, game);
	if (direction == 1)
		moved = move(1, 0, game);
	return (moved);
}

void	update_player(t_game *game)
{
	int	new_direction;

	new_direction = game->map.player.new_direction;
	if (!move_player(game, new_direction))
		move_player(game, game->map.player.old_direction);
	else
	{
		game->map.player.old_direction = 42;
		game->map.player.current_direction = new_direction;
	}
}
