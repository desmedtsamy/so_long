/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-smed <sde-smed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:53:52 by sde-smed          #+#    #+#             */
/*   Updated: 2023/01/10 12:47:27 by sde-smed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print(t_vector pos, t_game *game, t_sprites *sprites, char val)
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
	else if (val == '0')
		mlx_put_image_to_window(game->mlx, game->window, sprites->empty, r, c);
}

void	render_map(t_game *game)
{
	t_vector	p;
	int			s;

	s = SIZE;
	p.x = 0;
	while (p.x < game->map.row)
	{
		p.y = -1;
		while (++p.y < game->map.column)
			print(p, game, &game->sprites, game->map.map[p.x][p.y]);
		p.x++;
	}
	mlx_destroy_image(game->mlx, game->sprites.wall);
	mlx_destroy_image(game->mlx, game->sprites.food);
	mlx_destroy_image(game->mlx, game->sprites.exit);
}

void	render_map_2(t_game *game)
{
	t_vector	player;
	char		old_pos_value;

	player = game->map.player.pos;
	print(game->map.player.old_pos, game, &game->sprites, '0');
	print(player, game, &game->sprites, 'P');
}
